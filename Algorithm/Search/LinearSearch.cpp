#include <iostream>
#include "CommonUtil.cpp"

using namespace std;

/**
 * 線形探索
 * @param  list 探索対象配列
 * @param  len  配列の長さ
 * @return      インデックス番号
 */
int linerSearch(int *list, int len, int target) {
    for (size_t i = 0; i < len; i++) {
        if (list[i] == target) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    cout << endl;
    const int n = 10;
    int *list = new int(n);
    for (size_t i = 0; i < n; i++) {
        list[i] = i + 1;
    }

    showArray(list, n);

    int index;
    index = linerSearch(list, n, 5);
    cout << "5 -> index is " << index << endl;

    index = linerSearch(list, n, 100);
    cout << "100 -> index is " << index << endl;

    return 0;
}
