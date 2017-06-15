#include <iostream>
#include <string>

#include "Node.h"

using namespace std;

/**
 * ノード挿入位置まで移動
 * @param root 部分木の根ノード
 * @param node 挿入ノード
 */
void nodeInsPoint(Node *root, Node *node) {
    if (root->left == NULL && root->right == NULL) {
        root->left = node;
    } else if (root->left != NULL) {
        nodeInsPoint(root->left, node);
    } else if (root->right != NULL) {
        nodeInsPoint(root->right, node);
    }
}

/**
 * ノード挿入
 * @param  key  キー
 * @param  name 名前
 * @return      根ノード
 */
Node *insertNode(Node *root, int key, string name) {
    Node *node = new Node(key, name);

    if (root == NULL) {
        root = node;
    } else {
        nodeInsPoint(root, node);
    }

    return root;
}

int main(int argc, char const *argv[]) {
    // 根ノード
    Node *root = NULL;

    // 木構造の構築
    root = insertNode(root, 1, "foo");
    root = insertNode(root, 2, "bar");
    root = insertNode(root, 3, "hoge");
    showTree(root);

    return 0;
}
