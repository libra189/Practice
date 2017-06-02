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
 * @return      リストの先頭ポインタ
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

int main(int argc, char const *argv[]) {
    appendNode(0, "foo");
    appendNode(1, "bar");
    appendNode(2, "hoge");
    showList(head);
    cout << endl;
    reverseShowList(teil);
    cout << endl;

    deleteList(head);

    return 0;
}
