#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

public:
    LinkedList();
    ~LinkedList();

    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    bool insertAtPosition(int value, int position);

    bool deleteFromBeginning();
    bool deleteFromEnd();
    bool deleteFromPosition(int position);

    void display() const;
};

#endif
