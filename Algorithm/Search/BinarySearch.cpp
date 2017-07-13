#include <iostream>
#include "CommonUtil.cpp"

using namespace std;

/**
 * 二分探索
 * @param  list 探索リスト
 * @param  key  探索対象
 * @param  min  最小インデックス
 * @param  max  最大インデックス
 * @return      インデックス番号
 */
int binarySearch(int *list, int key, int min, int max) {
    if (max < min) {
        return -1;
    } else {
        int mid = min + (max - min) / 2;
        if (list[mid] > key) {
            return binarySearch(list, key, min, mid - 1);
        } else if (list[mid] < key) {
            return binarySearch(list, key, mid + 1, max);
        } else {
            return mid;
        }
    }
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
    index = binarySearch(list, 5, 0, n);
    cout << "5 -> index is " << index << endl;

    index = binarySearch(list, 100, 0, n);
    cout << "100 -> index is " << index << endl;

    return 0;
}
