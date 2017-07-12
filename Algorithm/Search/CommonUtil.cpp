#include <iostream>
#include <random>

/**
 * 乱数生成器
 * 0-99の範囲で生成
 * @param  num 生成数
 * @return     指定された数の乱数配列
 */
int *randomizer(const int num) {
    int *randomList;
    std::random_device rnd;
    std::mt19937 mt(rnd());
    std::uniform_int_distribution<> rand100(0, 99);

    randomList = new int[num];
    for (int i = 0; i < num; ++i) {
        randomList[i] = rand100(mt);
    }

    return randomList;
}

/**
 * 配列表示メソッド
 * @param array 表示したい配列
 */
void showArray(int *array, int len) {
    for (int i = 0; i < len; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * 値の交換
 * @param a 交換対象Aのポインタ
 * @param b 交換対象Bのポインタ
 */
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
