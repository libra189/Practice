#include <iostream>
#include <string>

using namespace std;

class Node {
private:
  string name;
  Node *next;
public:
  Node(string s) {
    name = s;
    next = NULL;
  }

  string toString() {
    return name;
  }
};

int main(int argc, char const *argv[]) {
  Node l("ボス");
  cout << l.toString() << endl;
  return 0;
}
