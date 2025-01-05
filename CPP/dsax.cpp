#include <iostream>
using namespace std;

// Definition of a node
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert at the beginning
void insertAtBeginning(Node*& head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    cout << "Node inserted at the beginning.\n";
}

// Function to insert at the end
void insertAtEnd(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Node inserted at the end.\n";
}

// Function to insert after a given node
void insertAfter(Node* head, int target, int data) {
    Node* temp = head;
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Target node not found.\n";
    } else {
        Node* newNode = createNode(data);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Node inserted after " << target << ".\n";
    }
}

// Function to traverse the linked list
void traverseList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
    } else {
        Node* temp = head;
        cout << "Linked list elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    Node* head = nullptr;
    int choice, data, target;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at the end\n";
        cout << "3. Insert after a given node\n";
        cout << "4. Traverse the list\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                insertAtBeginning(head, data);
                break;
            case 2:
                cout << "Enter data to insert at the end: ";
                cin >> data;
                insertAtEnd(head, data);
                break;
            case 3:
                cout << "Enter the target node value after which to insert: ";
                cin >> target;
                cout << "Enter data to insert: ";
                cin >> data;
                insertAfter(head, target, data);
                break;
            case 4:
                traverseList(head);
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
