#include<iostream>
using namespace std;

struct node {
    int data;
    node *left, *right;
};

class qNode {
    node* data;
    qNode* next;
public:
    qNode(node *data) {
        this->data = data;
        next = nullptr;
    }
};

class Queue {
    qNode *head, *rear;
public:
    Queue() {
        head = rear = nullptr;
    }
    Queue* createQueue(qNode* root);  
};

Queue* Queue::createQueue(qNode* root) {
    Queue *temp = new Queue;
    temp->head = temp->rear = root;
}
