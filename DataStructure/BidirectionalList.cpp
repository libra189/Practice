/**
 * データ構造 - リスト構造
 * 双方向リスト
 */

#include <iostream>
#include <string>

#include "Node.h"
#include "List.h"

using namespace std;

Node *head = NULL;  // リストの先頭ポインタ
Node *teil = NULL;  // リストの末尾ポインタ

/**
 * リストを逆順に表示
 * @param p リストの末尾ポインタ
 */
void reverseShowList(Node *p) {
    while (p != NULL) {
        cout << p->toString() << endl;
        p = p->front;
    }
}

/**
 * リストの先頭にノードを追加
 * @param  key  ノード値
 * @param  name ノード名
 */
void appendNode(int key, string name) {
    Node *p = new Node(key, name);

    if (head != NULL) {
        p->next = head;
        p->next->front = p;
        head = p;
    } else {
        head = p;
        teil = p;
    }
}

/**
 * 任意の位置にノードを挿入
 * @param  point 挿入位置
 * @param  key   ノード番号
 * @param  name  ノード名
 */
void insertNode(int point, int key, string name) {
    int i = 0;
    Node *p = new Node(key, name);

    if (point == 0) {
        p->next = head;
        p->next->front = p;
        head = p;
    }

    Node *node = head;
    while (i != point-1) {
        node = node->front;
    }
    node->next->front = p;
    p->next = node->next;
    p->front = node;
    node->next = p;
}

int main(int argc, char const *argv[]) {
    appendNode(0, "foo");
    appendNode(1, "bar");
    appendNode(2, "hoge");
    showList(head);
    cout << endl;
    reverseShowList(teil);
    cout << endl;

    insertNode(1, 3, "test");
    showList(head);
    cout << endl;
    reverseShowList(teil);
    cout << endl;

    deleteList(head);

    return 0;
}
