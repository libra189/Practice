#include <string>

using namespace std;

/**
 * 木構造を構成するノードクラス
 */
class Node {
public:
    int key;
    string name;
    Node *right;
    Node *left;

    Node(int key, string name) {
        this->key = key;
        this->name = name;
        this->right = NULL;
        this->left = NULL;
    }

    ~Node() {}

    string toString() {
        string k = to_string(this->key);
        return "{key:" + k + ", name:" + this->name + "}";
    }
};

/**
 * 深さ優先・行きがけ順探索による走査
 * @param node 部分木の根ノード
 */
void showTree(Node *node);
