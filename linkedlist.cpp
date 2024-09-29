#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

node* insertbegin(node* head, int value) {
    node* newnode = new node(value);
    newnode->next = head;
    head = newnode;
    return head;
}

node* insertPos(node* head, int pos, int data) {
    if (pos < 1) {
        cout << "Invalid position!" << endl;
        return head;
    }

    // Special case for inserting at the head
    if (pos == 1) {
        node* temp = new node(data);
        temp->next = head;
        return temp;
    }

    // Traverse the list to find the node before the insertion point
    node* prev = head;
    int count = 1;
    while (count < pos - 1 && prev != NULL) {
        prev = prev->next;
        count++;
    }

    // If position is greater than the number of nodes
    if (prev == NULL) {
        cout << "Invalid position!" << endl;
        return head;
    }

    // Insert the new node at the specified position
    node* temp = new node(data);
    temp->next = prev->next;
    prev->next = temp;
    return head;
}

node* insertAtEnd(node* head, int value) {
    node* newnode = new node(value);
    if (head == NULL)
        return newnode;

    // Traverse the list until the last node is reached
    node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Link the new node to the current last node
    current->next = newnode;
    return head;
}

node* deletelast(node* head) {
    if (head == NULL)
        return NULL;

    if (head->next == NULL) {  // Corrected condition
        delete head;
        return NULL;
    }

    node* secondlast = head;
    while (secondlast->next->next != NULL)
        secondlast = secondlast->next;

    // Delete last node
    delete (secondlast->next);

    // Change next of second last
    secondlast->next = NULL;

    return head;
}

// Function to create a linked list from user input
node* createList() {
    node* head = NULL;
    int n, value;
    cout << "Enter the number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        head = insertAtEnd(head, value);
    }
    return head;
}

// Function to print the linked list
void printList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    node* head = createList();
    int choice, value, pos;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at position\n";
        cout << "3. Insert at end\n";
        cout << "4. Delete last node\n";
        cout << "5. Print list\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                head = insertbegin(head, value);
                break;
            case 2:
                cout << "Enter position to insert: ";
                cin >> pos;
                cout << "Enter value to insert at position " << pos << ": ";
                cin >> value;
                head = insertPos(head, pos, value);
                break;
            case 3:
                cout << "Enter value to insert at end: ";
                cin >> value;
                head = insertAtEnd(head, value);
                break;
            case 4:
                head = deletelast(head);
                break;
            case 5:
                printList(head);
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
