#include <iostream>
#include "CommonUtil.cpp"

using namespace std;

#define LEFT_CHILD(i) (((i) + 1) * 2 - 1)
#define RIGHT_CHILD(i) (((i) + 1) * 2)
#define PARENT(i) (((i) + 1) / 2 - 1)

/**
 * ヒープへの登録
 * @param array 未整列配列
 * @param n     ヒープ登録用添え字
 */
void upheap(int *array, int n) {
    while (n > 0) {
        int m = PARENT(n);

        if (array[m] < array[n]) {
            swap(&array[m], &array[n]);
        } else {
            break;
        }

        n = m;
    }
}

/**
 * 配列への登録
 * @param array ヒープ済み配列
 * @param n     配列登録用添え字
 */
void downheap(int *array, int n) {
    int m = 0;
    int tmp = 0;

    while (true) {
        int l_chld = LEFT_CHILD(m);
        int r_chld = RIGHT_CHILD(m);

        if (l_chld >= n) {
            break;
        }

        if (array[l_chld] > array[tmp]) {
            tmp = l_chld;
        }
        if ((r_chld < n) && (array[r_chld] > array[tmp])) {
            tmp = r_chld;
        }

        if (tmp == m) {
            break;
        }

        swap(&array[tmp], &array[m]);
        m = tmp;
    }
}

/**
 * ヒープソート
 * @param  array ソート対象配列
 * @param  len   配列の長さ
 */
void heapSort(int *array, int len) {
    int i = 0;
    while (++i < len) {
        upheap(array, i);
    }

    while (--i > 0) {
        swap(&array[0], &array[i]);
        downheap(array, i);
    }
}

int main(int argc, char const *argv[]) {
    const int len = 5;
    int *array = randomizer(len);
    showArray(array, len);

    heapSort(array, len);
    showArray(array, len);

    return 0;
}
