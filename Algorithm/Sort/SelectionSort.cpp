#include <iostream>
#include "CommonUtil.cpp"

using namespace std;

/**
 * 選択ソート
 * @param  array ソート対象配列
 * @param  len   配列の長さ
 * @return       ソート済み配列
 */
int *selectionSort(int *array, const int len) {
    for (int i = 0; i < len; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        swap(&array[i], &array[min]);
    }

    return array;
}

int main(int argc, char const *argv[]) {
    const int len = 5;
    int *array = randomizer(len);
    showArray(array, len);

    array = selectionSort(array, len);
    showArray(array, len);

    return 0;
}
