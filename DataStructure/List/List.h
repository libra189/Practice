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
