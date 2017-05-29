/**
 * 単方向リスト
 */

//#include "node.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Node {
  int key;
  string name;
  struct Node *next;
};

/**
 * Nodeの追加
 */
struct Node *add_node(int key, string name, struct Node* head) {
  struct Node *p;
  if ((p = (struct Node *)malloc(sizeof(struct Node))) == NULL) {
    cout << "malloc error" << endl;
    exit(-1);
  }

  p->key = key;
  p->name = name;
  p->next = head;
  head = p;

  return head;
}

/**
 * リストの消去
 */
void free_list(struct Node *p) {
  struct Node *p2;
  while (p != NULL) {
    p2 = p->next;
    free(p);
    p = p2;
  }
}

/**
 * リストの表示
 */
void show_list(struct Node *p) {
  while (p != NULL) {
    cout << "{" << p->key << " : " << p->name << "}" << endl;
    p = p->next;
  }
}

int main(int argc, char const *argv[]) {
  struct Node *head = NULL;
  int key = 0;

  head = add_node(key++, "hoge", head);
  head = add_node(key++, "bar", head);

  show_list(head);

  free_list(head);

  return 0;
}