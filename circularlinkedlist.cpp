#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* last;

public:
    CircularLinkedList() {
        last = nullptr;
    }

    // Function to traverse the circular linked list
    void traverse() {
        if (last == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = last->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }

    // Function to insert a node at the beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        if (last == nullptr) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
    }

    // Function to insert a node at the end
    void insertAtEnd(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        if (last == nullptr) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    // Function to insert a node at a specified position
    void insertAtPosition(int data, int position) {
        if (position < 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        Node* newNode = new Node();
        newNode->data = data;
        if (last == nullptr) {
            if (position == 1) {
                last = newNode;
                last->next = last;
            } else {
                cout << "Invalid position!" << endl;
            }
            return;
        }
        Node* temp = last->next;
        for (int i = 1; i < position - 1 && temp != last; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == last) {
            last = newNode;
        }
    }

    // Function to delete a node from the beginning
    void deleteFromBeginning() {
        if (last == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = last->next;
        if (last->next == last) {
            last = nullptr;
        } else {
            last->next = temp->next;
        }
        delete temp;
    }

    // Function to delete a node from the end
    void deleteFromEnd() {
        if (last == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = last->next;
        if (last->next == last) {
            last = nullptr;
        } else {
            while (temp->next != last) {
                temp = temp->next;
            }
            temp->next = last->next;
            delete last;
            last = temp;
        }
    }

    // Function to delete a node from a specified position
    void deleteFromPosition(int position) {
        if (last == nullptr || position < 1) {
            cout << "Invalid position or list is empty!" << endl;
            return;
        }
        Node* temp = last->next;
        if (position == 1) {
            if (last->next == last) {
                last = nullptr;
            } else {
                last->next = temp->next;
            }
            delete temp;
            return;
        }
        for (int i = 1; i < position - 1 && temp->next != last->next; i++) {
            temp = temp->next;
        }
        if (temp->next == last->next) {
            cout << "Invalid position!" << endl;
            return;
        }
        Node* delNode = temp->next;
        temp->next = delNode->next;
        if (delNode == last) {
            last = temp;
        }
        delete delNode;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.traverse();

    cll.insertAtBeginning(5);
    cll.traverse();

    cll.insertAtPosition(25, 3);
    cll.traverse();

    cll.deleteFromBeginning();
    cll.traverse();

    cll.deleteFromEnd();
    cll.traverse();

    cll.deleteFromPosition(2);
    cll.traverse();

    return 0;
}
