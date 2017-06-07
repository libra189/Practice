/**
 * データ構造 - リスト構造
 * 片方向循環リスト
 */

#include <iostream>
#include <string>

#include "Node.h"

Node *head = NULL;
Node *tail = NULL;

void showList() {
    Node *p = head;
    do {
        cout << p->toString() << endl;
        p = p->next;
    } while(p != head);
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
        head = p;
        tail->next = p;
    } else {
        head = p;
        tail = p;
        p->next = p;
    }
}

int main(int argc, char const *argv[]) {
    // 新規リストの作成
    appendNode(0, "foo");
    appendNode(1, "bar");
    appendNode(2, "hoge");
    showList();
    cout << endl;

    return 0;
}
