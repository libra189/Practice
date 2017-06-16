#include <iostream>
#include <string>

#include "Node.h"

using namespace std;

/**
 * ノード挿入
 * @param  key  キー
 * @param  name 名前
 * @return      根ノード
 */
Node *insertNode(Node *root, int key, string name) {

}

int main(int argc, char const *argv[]) {
    // 根ノード
    Node *root = NULL;

    // 木構造の構築
    root = insertNode(root, 1, "foo");
    root = insertNode(root, 2, "bar");
    root = insertNode(root, 3, "hoge");
    root = insertNode(root, 4, "test");
    showTree(root);

    return 0;
}
