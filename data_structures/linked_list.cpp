#include "linked_list.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::insertAtBeginning(int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

void LinkedList::insertAtEnd(int value) {
    Node* newNode = new Node{value, nullptr};

    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

bool LinkedList::insertAtPosition(int value, int position) {
    if (position < 1) return false;

    if (position == 1) {
        insertAtBeginning(value);
        return true;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp; ++i) {
        temp = temp->next;
    }

    if (!temp) return false;

    Node* newNode = new Node{value, temp->next};
    temp->next = newNode;
    return true;
}

bool LinkedList::deleteFromBeginning() {
    if (!head) return false;
    Node* temp = head;
    head = head->next;
    delete temp;
    return true;
}

bool LinkedList::deleteFromEnd() {
    if (!head) return false;

    if (!head->next) {
        delete head;
        head = nullptr;
        return true;
    }

    Node* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    return true;
}

bool LinkedList::deleteFromPosition(int position) {
    if (position < 1 || !head) return false;

    if (position == 1) {
        return deleteFromBeginning();
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp; ++i) {
        temp = temp->next;
    }

    if (!temp || !temp->next) return false;

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
    return true;
}

void LinkedList::display() const {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}
