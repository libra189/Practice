/**
 * データ構造 - リスト構造
 * 双方向循環リスト
 */

#include <iostream>
#include <string>

#include "Node.h"
#include "CirculationList.h"

Node *head = NULL;
Node *tail = NULL;

/**
 * リストの先頭にノードを追加
 * @param key  ノード番号
 * @param name ノード名
 */
void insertNode(int key, string name) {
    Node *node = new Node(key, name);

    if (head == NULL && tail == NULL) {
        head = node;
        tail = node;
    } else {
        head->front = node;
        node->next = head;
        head = node;
        tail->next = node;
    }
}

/**
 * 任意の位置にノードを追加
 * @param point 挿入位置
 * @param key   ノード番号
 * @param name  ノード名
 */
void appendNode(int point, int key, string name) {

}

int main(int argc, char const *argv[]) {
    // 新規ノードの追加
    insertNode(0, "foo");
    insertNode(1, "bar");
    insertNode(2, "hoge");
    showList(head);
    cout << endl;

    // リストの削除
    deleteList();

    return 0;
}
