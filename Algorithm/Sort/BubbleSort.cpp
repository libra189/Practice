#include <iostream>
#include "CommonUtil.cpp"

using namespace std;

int main(int argc, char const *argv[]) {
    const int len = 5;
    int *array = randomizer(len);
    showArray(array, len);

    return 0;
}
