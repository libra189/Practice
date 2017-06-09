/**
 * リストを表示
 */
void showList(Node *head) {
    Node *p = head;
    do {
        cout << p->toString() << endl;
        p = p->next;
    } while(p != head);
}

/**
 * リストを削除
 */
void deleteList(Node *head, Node *tail) {
    Node *p = head;
    Node *p2;
    do {
        p2 = p->next;
        delete p;
        p = p2;
    } while (p != tail);
}
