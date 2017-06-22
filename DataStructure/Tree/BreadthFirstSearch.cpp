#include <string>
#include <vector>
#include <iostream>

#include "Node.h"

using namespace std;

/**
 * Vectorリスト内を検索
 * @param  v_list 検索対象リスト
 * @param  key    検索値
 * @return        bool
 */
bool isFindVector(vector<int> v, int key) {
    for (int x : v) {
        if (x == key) {
            return true;
        }
    }
    return false;
}

string showVector(vector<Node> v) {
    string rtn = "";
    for (Node x : v) {
        rtn += to_string(x.key) + " ";
    }
    return rtn;
}

/**
 * 幅優先探査
 * @param root 根ノード
 */
void bfs(Node *root) {
    Node *node;
    vector<Node> nodeList;
    vector<int> visited;

    nodeList.push_back(*root);
    visited.push_back(root->key);
    while (!nodeList.empty()) {
        cout << showVector(nodeList) << endl;
        node = &(nodeList.back());
        nodeList.pop_back();
        cout << node->toString() << endl;

        if (node->left != NULL) {
            if (!isFindVector(visited, node->left->key)) {
                visited.push_back(node->left->key);
                nodeList.push_back(*node->left);
            }
        }
        if (node->right != NULL) {
            if (!isFindVector(visited, node->right->key)) {
                visited.push_back(node->right->key);
                nodeList.push_back(*node->right);
            }
        }
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
 * 深さ優先・行きがけ順探索による走査
 * @param node 部分木の根ノード
 */
void showTree(Node *node) {
    cout << node->toString() << endl;
    if (node->left != NULL) {
        showTree(node->left);
    }
    if (node->right != NULL) {
        showTree(node->right);
    }
}

int main(int argc, char const *argv[]) {
    Node *root;

    // 探索用木構造の作成
    root = new Node(10, "bar");
    root->left = new Node(5, "foge");
    root->right = new Node(20, "hoge");
    root->left->right = new Node(7, "tes");
    root->left->left = new Node(3, "tes2");
    root->right->right = new Node(30, "jeg");
    bfs(root);

    destroyTree(root);

    return 0;
}
