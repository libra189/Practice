#include <iostream>
#include "CommonUtil.cpp"

using namespace std;

/**
 * クイックソート
 * @param array 対象配列
 * @param left  要素の最初
 * @param right 要素の最後
 */
void quickSort(int *array, int left, int right) {
    int i = left;
    int j = right;
    int pivot = array[(i + j) / 2];

    while (true) {
        while (array[i] < pivot) {
            ++i;
        }
        while (pivot < array[j]) {
            --j;
        }
        if (i >= j) break;

        swap(&array[i], &array[j]);
        i++;
        j--;
    }

    if (left < i - 1) {
        quickSort(array, left, i - 1);
    }
    if (j + 1 < right) {
        quickSort(array, j + 1, right);
    }
}

int main(int argc, char const *argv[]) {
    const int len = 5;
    int *array = randomizer(len);
    showArray(array, len);

    quickSort(array, 0, len - 1);
    showArray(array, len);

    delete array;
    return 0;
}
