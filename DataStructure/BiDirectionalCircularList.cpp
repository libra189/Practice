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
 * 【デバッグ用】ノードのポインタ表示
 */
void listOpen() {
    Node *node = head;
    do {
        cout << node->front << " " << node << " " << node->next << endl;
        node = node->next;
    } while(node != head);
}

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
        node->front = tail;
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
    Node *p = head;
    Node *node = new Node(key, name);
    int i = 0;

    if (point == 0) {
        node->front = tail;
        node->next = head;
        head = node;
        tail->next = node;
    }

    while (i != point-1) {
        if (p == tail) {
            head->front = node;
            node->front = p;
            node->next = head;
            p->next = node;
            tail = node;
            return;
        }
        p = p->next;
        i++;
    }

    p->next->front = node;
    node->next = p->next;
    node->front = p;
    p->next = node;
}

/**
 * 任意の位置のノードを削除
 * @param point 削除位置
 */
void deleteNode(int point) {
    int i = 0;
    Node *node = head;

    if (point == 0) {
        head = head->next;
        head->front = tail;
        tail->next = head;
        delete node;
        return;
    }

    while (i != point) {
        if (node == tail) {
            tail = tail->front;
            tail->next = head;
            return;
        }
        node = node->next;
        i++;
    }

    node->front->next = node->next;
    node->next->front = node->front;
    delete node;
}

int main(int argc, char const *argv[]) {
    // 新規ノードの追加
    insertNode(0, "foo");
    insertNode(1, "bar");
    insertNode(2, "hoge");
    showList(head);
    cout << endl;

    // 任意の位置にノードを挿入
    appendNode(1, 3, "test1");
    appendNode(5, 4, "test2");
    showList(head);
    cout << endl;

    // 任意の位置のノードを削除
    deleteNode(1);
    deleteNode(5);
    showList(head);
    cout << endl;

    // リストの削除
    deleteList(head, tail);

    return 0;
}
