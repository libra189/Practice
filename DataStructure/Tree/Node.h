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

    string toString() {
        string k = to_string(this->key);
        return "{key:" + k + ", name:" + this->name + "}";
    }
}
