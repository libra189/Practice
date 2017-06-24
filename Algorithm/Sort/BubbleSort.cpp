#include <iostream>
#include "CommonUtil.cpp"

using namespace std;

int *bubleSort(int *array, int len) {
    for (int i = 0;i < len-1;i++) {
        for (int j = 1;j < len - i + 1;j++) {
            if (array[j] < array[j-1]) {
                int tmp = array[j];
                array[j] = array[j-1];
                array[j-1] = tmp;
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
