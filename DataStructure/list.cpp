/**
 * データ構造 - リスト構造
 * 単方向リスト
 *
 * TODO
 * 任意のノードの削除
 */

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
Node *appendNode(int key, string name, Node *head) {
    Node *p = new Node(key, name);
    p->next = head;
    head = p;
    return head;
}

/**
 * 任意の場所にノードを追加
 * @param  point 挿入番号
 * @param  key   ノード番号
 * @param  name  ノード名
 * @param  head  リストの先頭ポインタ
 * @return       リストの先頭ポインタ
 */
Node *insertNode(int point, int key, string name, Node *head) {
    int i = 0;
    Node *p = new Node(key, name);
    Node *node;

    if (point == i) {
        p->next = head;
        head = p;
        return head;
    }

    node = head;
    while (i != point-1) {
        node = node->next;
        i++;
        if (node->next == NULL) {
            break;
        }
    }
    p->next = node->next;
    node->next = p;

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

/**
 * 任意のノードの削除
 * @param  point [description]
 * @param  head  [description]
 * @return       [description]
 */
Node *deleteNode(int point, Node *head) {
    Node *node;
    if (point == 0) {
        node = head->next;
        delete head;
        head = node;
    }
}

int main(int argc, char const *argv[]) {
    Node *head = NULL;
    head = appendNode(0, "foo", head);
    head = appendNode(1, "bar", head);
    head = appendNode(2, "hoge", head);
    showList(head);

    cout << endl;

    head = insertNode(2, 3, "test", head);
    showList(head);

    deleteList(head);

    return 0;
}
