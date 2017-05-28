/**
 * データ構造 - リスト構造
 * ノードクラス
*/

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
    string str = "{name : " + this->name + "}";
    return str;
  }
};

