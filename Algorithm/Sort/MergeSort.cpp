#include <iostream>
#include "CommonUtil.cpp"

using namespace std;

/**
 * 配列の結合
 * @param array ソート対象配列
 * @param left  左端インデックス
 * @param mid   中央インデックス
 * @param right 右端インデックス
 */
void merge(int *array, int left, int mid, int right) {
    int num = right - left;
    int *tmp = new int[num];

    int iw = 0;
    int il = left;
    int ir = mid;

    while (il < mid && ir < right) {
        if (array[il] <= array[ir]) {
            tmp[iw++] = array[il++];
        } else {
            tmp[iw++] = array[ir++];
        }
    }

    while (il < mid) {
        tmp[iw++] = array[il++];
    }
    while (ir < right) {
        tmp[iw++] = array[ir++];
    }

    for (int i = 0; i < num; i++) {
        array[left + i] = tmp[i];
    }

    delete[] tmp;
}

/**
 * マージソート
 * 配列を最小単位まで分割
 * @param  array ソート対象配列
 * @param  len   配列の長さ
 * @return       ソート済み配列
 */
void mergeSort(int *array, const int left, const int right) {
    if (right - left <= 1) {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid, right);

    merge(array, left, mid, right);
}

int main(int argc, char const *argv[]) {
    const int len = 5;
    int *array = randomizer(len);
    showArray(array, len);

    mergeSort(array, 0, len);
    showArray(array, len);

    return 0;
}
