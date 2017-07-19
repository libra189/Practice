#include <cstdlib>
#include <cstdlib>
#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

const unsigned int hashElementNum = 51;

const unsigned int sampleHashfuc(const string& str) {
    unsigned int h = 0;
    string::const_iterator i = str.begin();

    for (;i != str.end(); ++i) {
        h += h * 137 + *i;
    }

    return h % hashElementNum;
}

template <typename TKey, typename TValue>
class Hash {
public:
    // 型宣言
    typedef const unsigned int (*HashFunc)(const TKey&);
    typedef pair<const TKey, TValue> Pair;
protected:
    // クラス内用の型宣言
    typedef list<Pair> list;
    typedef typename List::iterator Iterator;
    typedef vector<List> Vector;

    // Vector要素の１つのListの検索結果と終了をセットにした構造体
    struct BeginEnd {
        // Vectorの要素位置
        typename Vector::size_type hval;
        // 検索結果
        Iterator found;
        // Listの終了
        Iterator end;
    };

public:
    // コンストラクタ
    Hash(HashFunc func = &sampleHashFuc)
    : m_vec(hashElementNum), m_func(func)
    {};

    // 値の取り出し
    TValue& operator [](const TKey& key) {
        BeginEnd result = _find(key);
        Iterator i = result.found;

        // キーが見つかったとき
        if (i != result.end) return i->second;

        // キーが見つかったとき、新規追加する
        i = addPair(key);
        return i->second;
    };

    // キーの削除
    void remove(const TKey& key) {
        BeginEnd result = _find(key);
        Iterator i = result.found;
        if (i == result.end) return;
        // vectorのどこの要素に入っているかを取得
        m_vec[result.hval].erase(i);
    };

    // 検索
    Pair* find(const TKey& key) {
        BeginEnd result = _find(key);
        if (result.found != result.end) {
            return &*result.found;
        } else {
            return NULL;
        }
    };

protected:
    // マッピング値検索
    BeginEnd _find(const TKey& key) {
        // vectorのどこの要素に入っているかを取得
        const unsigned int hval = m_func(key);

        // 要素の中を検索
        Iterator i;
        Iterator begin = m_vec[hval].begin();
        Iterator end = m_vec[hval].end();
        for (i = begin; i != end; ++i) {
            if (i->first == key) break;
        }

        // 結果の返却
        BeginEnd k = {hval, i, end};
        return k;
    };

    // 新規にキーと値のセットを追加
    Iterator addPair(const TKey& key) {
        m_vec[hval].push_front(Pair(key, TValue()));
        return m_vec[hval].begin();
    };

private:
    Vector m_vec;
    HashFunc m_func;
};

int main(int argc, char const *argv[]) {
    Hash<string, string> h;

    h["abc"] = "ABC";
    h["bcd"] = "BCD";
    cout << h["abc"] << ":" << h["bcd"] << ":" << h["kkk"] << endl;

    // 削除
    h.remove("bcd");
    cout << h["abc"] << ":" << h["bcd"] << ":" << h["kkk"] << endl;

    system("PAUSE")
    return EXIT_SUCCESS;
}
