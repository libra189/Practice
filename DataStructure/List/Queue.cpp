#include <iostream>

using namespace std;

const int MAX = 10;
int *queue;
int head;
int tail;

void initialize() {
    queue = new int[MAX];
    head = tail = 0;
}

bool isFull() { return head == (tail + 1) % MAX; }

bool isEmpty() { return head == tail; }

void enqueue(int x) {
    if (isFull()) {
        cerr << "Queue is Full at Error" << endl;
        return;
    }
    queue[tail] = x;
    if (tail + 1 == MAX) {
        tail = 0;
    } else {
        tail++;
    }
}

int dequeue() {
    if (isEmpty()) {
        cerr << "Queue is Empth at Error" << endl;
        return NULL;
    }
    int x = queue[head];
    if (head + 1 == MAX) {
        head = 0;
    } else {
        head++;
    }
    return x;
}

int main(int argc, char const *argv[]) {
    initialize();

    enqueue(10);
    enqueue(5);
    enqueue(20);

    cout << dequeue() << endl;
    cout << dequeue() << endl;
    return 0;
}
