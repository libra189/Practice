/**
 * データ構造 - リスト構造
 * 片方向循環リスト
 */

#include <iostream>
#include <string>

#include "Node.h"
#include "List.h"

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
        teil = p;
    }
}

int main(int argc, char const *argv[]) {

    return 0;
}
