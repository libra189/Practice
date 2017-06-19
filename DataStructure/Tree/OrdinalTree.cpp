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
 * 指定したkeyを持つノードを削除
 * @param root 根ノード
 * @param key  削除する値
 */
void deleteKeyNode(Node *root, int key) {
    Node *node, *parent;
    Node *leftBiggest;
    int direction;

    node = root;
    parent = NULL;
    direction = 0;

    // 削除するノードの探査
    while (node != NULL && node->key != key) {
        parent = node;
        if (node->key > key) {
            node = node->left;
            direction = -1; // 親の左側
        } else {
            node = node->right;
            direction = 1;  // 親の右側
        }
    }

    // 削除ノードが無かった場合
    if (node == NULL) {
        return;
    }

    if (node->left == NULL || node->right == NULL) {
        /* 左か右，どちらかがNULLであった場合
           (両方NULLの場合も含む) */

        // 親のポインタを変更
        if (node->left == NULL) {
            if (direction == -1) {
                parent->left = node->right;
            }
            if (direction == 1) {
                parent->right = node->right;
            }
            if (direction == 0) {
                root = node->left;
            }
        } else {
            if (direction == -1) {
                parent->left = node->left;
            }
            if (direction == 1) {
                parent->right = node->left;
            }
            if (direction == 0) {
                parent = node->left;
            }
        }

        delete node;
    } else {
        /* 両者ともNULLでなかった場合 */

        // nodeの左側の最も大きな値（最も右側の値）を取得する
        leftBiggest = node->left;
        parent = node;
        direction = -1;
        while (leftBiggest->right != NULL) {
            parent = leftBiggest->right;
            leftBiggest = leftBiggest->right;
            direction = 1;
        }

        // left_biggestの値をnodeに代入し、left_biggestは左側の枝を入れる
        node->key = leftBiggest->key;
        if (direction == -1) {
            parent->left = leftBiggest->left;
        } else {
            parent->right = leftBiggest->left;
        }

        delete leftBiggest;
    }
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

    deleteKeyNode(root, 10);
    showTree(root);

    destroyTree(root);

    return 0;
}
