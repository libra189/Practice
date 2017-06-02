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
 * リストの先頭にノードを追加
 * @param  key  ノード値
 * @param  name ノード名
 * @return      リストの先頭ポインタ
 */
void appendNode(int key, string name) {
    Node *p = new Node(key, name);

    if (head != NULL) {
        p->next = head;
        head->front = p;
        head = p;
    } else {
        head = p;
    }
}

int main(int argc, char const *argv[]) {
    appendNode(0, "foo");
    appendNode(1, "bar");
    appendNode(2, "hoge");
    showList(head);

    deleteList(head);

    return 0;
}
