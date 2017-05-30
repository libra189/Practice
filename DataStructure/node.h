#include <string>

using namespace std;

/**
 * リストを構成するNodeクラス
 */
class Node {
public:
    int key;
    string name;
    Node *next;

    Node(int key, string name) {
        this->key = key;
        this->name = name;
        next = NULL;
    }

    ~Node() {}

    /**
     * Nodeの出力
     * @return string
     */
    string toString() {
        string s = to_string(this->key);
        return "{key:" + s + ", name:" + this->name + "}";
    }
};
