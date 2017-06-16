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

/**
 * 最小値走査メソッド
 * @param  node ノード
 * @return      最小値
 */
int searchMinTree(Node *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node->key;
}

/**
 * 最大値走査メソッド
 * @param  node ノード
 * @return      最大値
 */
int searchMaxTree(Node *node) {
    while (node->right != NULL) {
        node = node->right;
    }
    return node->key;
}

/**
 * 指定値の探査メソッド
 * @param  key  指定値
 * @param  node 根ノード
 * @return      boolean
 */
bool isMatchNode(int key, Node *node) {
    while (node != NULL) {
        if (node->key == key) {
            return true;
        } else if (key < node->key) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return false;
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
    cout << endl;

    cout << "最小値 : " << searchMinTree(root) << endl;
    cout << "最大値 : " << searchMaxTree(root) << endl << endl;

    root = insertNode(30, "age", root);
    showTree(root);
    cout << "最大値 : " << searchMaxTree(root) << endl << endl;

    destroyTree(root);

    return 0;
}
