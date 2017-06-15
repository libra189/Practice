#include <iostring>
#include <string>

using namespace std;

class Node {
    int key;
    string name;
    Node *right;
    Node *left;

    Node(int key, string name) {
        this->key = key;
        this->name = name;
        this->right = NULL;
        this->left = NULL;
    }

    ~Node() {}
}

int main(int argc, char const *argv[]) {

    return 0;
}
