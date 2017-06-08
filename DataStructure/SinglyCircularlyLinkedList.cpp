/**
 * データ構造 - リスト構造
 * 片方向循環リスト
 */

#include <iostream>
#include <string>

#include "Node.h"
#include "CirculationList.h"

Node *head = NULL;
Node *tail = NULL;

/**
 * リストの先頭にノードを追加
 * @param  key  ノード値
 * @param  name ノード名
 */
void appendNode(int key, string name) {
    Node *p = new Node(key, name);

    if (head != NULL) {
        p->next = head;
        head = p;
        tail->next = p;
    } else {
        head = p;
        tail = p;
        p->next = p;
    }
}

/**
 * 任意の位置にノードを挿入
 * @param  point 挿入位置
 * @param  key   ノード番号
 * @param  name  ノード名
 */
void insertNode(int point, int key, string name) {
    Node *node = new Node(key, name);
    Node *p = head;
    int i = 0;
    bool flg = false;

    if (point == 0) {
        node->next = head;
        head = node;
        tail->next = node;
    }

    while (true) {
        if (p == tail) {
            flg = true;
            break;
        }
        if (i == point-1) {
            break;
        }
        p = p->next;
        i++;
    }

    if (flg) {
        node->next = p->next;
        p->next = node;
        tail = node;
    } else {
        node->next = p->next;
        p->next = node;
    }
}

/**
 * 任意のノードを削除
 * @param point 削除位置
 */
void deleteNode(int point) {
    Node *node = head;
    if (point == 0) {
        tail->next = head->next;
        head = head->next;
        delete node;
    }

    int i = 0;
    bool flg = false;
    while (true) {
        if (i == point-1) {
            break;
        }

        if (node->next == tail) {
            flg = true;
            break;
        }
        node = node->next;
        i++;
    }

    Node *p = node->next;
    if (flg) {
        tail = node;
    }
    node->next = p->next;
    delete p;
}

int main(int argc, char const *argv[]) {
    // 新規リストの作成
    appendNode(0, "foo");
    appendNode(1, "bar");
    appendNode(2, "hoge");
    showList();
    cout << endl;

    // ノードの追加
    insertNode(1, 3, "test1");
    insertNode(4, 4, "test2");
    showList();
    cout << endl;

    // ノードの削除
    deleteNode(4);
    deleteNode(2);
    showList();
    cout << endl;

    // リストの削除
    deleteList();

    return 0;
}
