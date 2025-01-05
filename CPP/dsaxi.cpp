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

// Function to delete at the beginning
void deleteAtBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty. No nodes to delete.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    cout << "Node deleted from the beginning.\n";
}

// Function to delete at the end
void deleteAtEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty. No nodes to delete.\n";
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Node deleted from the end.\n";
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    cout << "Node deleted from the end.\n";
}

// Function to delete after a given node
void deleteAfter(Node* head, int target) {
    if (head == nullptr) {
        cout << "List is empty. No nodes to delete.\n";
        return;
    }
    Node* temp = head;
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr) {
        cout << "Target node not found or no node exists after the target.\n";
    } else {
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        cout << "Node deleted after " << target << ".\n";
    }
}

// Function to traverse the linked list
void traverseList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "Linked list elements: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int choice, data, target;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at the beginning (for testing)\n";
        cout << "2. Delete at the beginning\n";
        cout << "3. Delete at the end\n";
        cout << "4. Delete after a given node\n";
        cout << "5. Traverse the list\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                insertAtBeginning(head, data);
                break;
            case 2:
                deleteAtBeginning(head);
                break;
            case 3:
                deleteAtEnd(head);
                break;
            case 4:
                cout << "Enter the target node value after which to delete: ";
                cin >> target;
                deleteAfter(head, target);
                break;
            case 5:
                traverseList(head);
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
