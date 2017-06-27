#include <iostream>
#include "CommonUtil.cpp"

using namespace std;

/**
 * 挿入ソート
 * @param  array ソート対象配列
 * @param  len   配列の長さ
 * @return       ソート済み配列
 */
int *insertSort(int *array, int len) {
    for (int i = 1; i < len; i++) {
        int tmp = array[i];
        if (array[i - 1] > tmp) {
            int j = i;
            do {
                array[j] = array[j - 1];
                j--;
            } while (j > 0 && array[j - 1] > tmp);
            array[j] = tmp;
        }
    }
    return array;
}

int main(int argc, char const *argv[]) {
    const int len = 5;
    int *array = randomizer(len);
    showArray(array, len);

    array = insertSort(array, len);
    showArray(array, len);

    return 0;
}
