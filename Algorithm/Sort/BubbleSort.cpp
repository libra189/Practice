#include <iostream>
#include "CommonUtil.cpp"

using namespace std;

/**
 * バブルソート
 * @param  array ソート対象配列
 * @param  len   配列の長さ
 * @return       ソート済み配列
 */
int *bubleSort(int *array, int len) {
    for (int i = 0;i < len-1;i++) {
        for (int j = len-1;j > i;j--) {
            if (array[j] < array[j-1]) {
                swap(&array[j], &array[j-1]);
            }
        }
    }
    return array;
}

int main(int argc, char const *argv[]) {
    const int len = 5;
    int *array = randomizer(len);
    showArray(array, len);

    array = bubleSort(array, len);
    showArray(array, len);

    return 0;
}
