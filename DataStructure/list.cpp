#include "node.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  Node n("テスト");
  cout << n.toString() << endl;

  return 0;
}