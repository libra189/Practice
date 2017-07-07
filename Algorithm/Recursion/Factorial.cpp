#include <iostream>

using namespace std;

/**
 * 階乗
 * @param  n n!
 * @return   計算値
 */
int factorial(const int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main(int argc, char const *argv[]) {
    const int n = 10;
    int f = factorial(n);
    cout << n << "! = " << f << endl;
    return 0;
}
