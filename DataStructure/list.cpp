#include <iostream>
#include <string>

#include "node.h"

using namespace std;

/**
 * リスト先頭へノードを追加
 * @param  key  ノード番号
 * @param  name ノード名
 * @param  head リストの先頭ポインタ
 * @return      リストの先頭ポインタ
 */
Node* appendNode(int key, string name, Node *head) {
    Node *p = new Node(key, name);
    p->next = head;
    head = p;
    return head;
}

/**
 * リストの出力
 * @param p 先頭ポインタ
 */
void showList(Node *p) {
    while (p != NULL) {
        cout << p->toString() << endl;
        p = p->next;
    }
}

/**
 * リストの削除
 * @param p 先頭ポインタ
 */
void deleteList(Node *p) {
    Node *p2;
    while (p != NULL) {
        p2 = p->next;
        delete p;
        p = p2;
    }
}

int main(int argc, char const *argv[]) {
    Node *head = NULL;
    head = appendNode(0, "foo", head);
    head = appendNode(1, "bar", head);

    showList(head);

    deleteList(head);

    return 0;
}
