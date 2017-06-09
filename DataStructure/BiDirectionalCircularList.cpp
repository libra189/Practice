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

int main(int argc, char const *argv[]) {
    return 0;
}
