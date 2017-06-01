/**
 * データ構造 - リスト構造
 * 双方向リスト
 */

#include <iostream>
#include <string>

#include "Node.h"

using namespace std;

/**
 * リストの先頭にノードを追加
 * @param  key  ノード値
 * @param  name ノード名
 * @param  head リストの先頭ポインタ
 * @return      リストの先頭ポインタ
 */
Node *appendNode(int key, string name, Node *head) {

}

int main(int argc, char const *argv[]) {
    Node *head = NULL;
    head = appendNode(0, "foo", head);
    head = appendNode(1, "bar", head);
    head = appendNode(2, "hoge", head);
    showList(head);

    deleteList(head);

    return 0;
}
