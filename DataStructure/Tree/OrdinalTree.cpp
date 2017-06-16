#include <iostream>
#include <string>

#include "Node.h"

using namespace std;

/**
 * ノード挿入
 * @param  **node 現在のノード
 * @param  key  キー
 * @param  name 名前
 */
Node *insertNode(int key, string name, Node *node) {
    if (node == NULL) {
        return new Node(key, name);
    } else if (key < node->key) {
        node->left = insertNode(key, name, node->left);
    } else if (key > node->key) {
        node->right = insertNode(key, name, node->right);
    }
    return node;
}

/**
 * 節の削除
 * @param node 節ノード
 */
void deleteNode(Node *node) {
    if (node != NULL) {
        deleteNode(node->left);
        deleteNode(node->right);
        delete node;
    }
}

/**
 * 木の削除
 * @param root 根ノード
 */
void destroyTree(Node *root) {
    deleteNode(root);
    delete root;
}

int main(int argc, char const *argv[]) {
    // 根ノード
    static Node *root = NULL;

    // 木構造の構築
    root = insertNode(5, "foo", root);
    root = insertNode(1, "bar", root);
    root = insertNode(2, "hoge", root);
    root = insertNode(10, "test", root);
    showTree(root);

    destroyTree(root);

    return 0;
}
