#include <iostream>

using namespace std;

int Fibonacci(const int n) {
    switch (n) {
    case 0:
        return 0;
    case 1:
        return 1;
    default:
        return Fibonacci(n-1) + Fibonacci(n-2);
    }
}

int main(int argc, char const *argv[]) {
    const int n = 6;
    int res = Fibonacci(n);

    cout << n << " -> " << res << endl;

    return 0;
}
