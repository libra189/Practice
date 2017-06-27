#include <iostream>
#include "CommonUtil.cpp"

using namespace std;

/**
 * マージソート
 * @param  array ソート対象配列
 * @param  len   配列の長さ
 * @return       ソート済み配列
 */
int *mergeSort(int *array, const int len) { return array; }

int main(int argc, char const *argv[]) {
    const int len = 5;
    int *array = randomizer(len);
    showArray(array, len);

    array = mergeSort(array, len);
    showArray(array, len);

    return 0;
}
