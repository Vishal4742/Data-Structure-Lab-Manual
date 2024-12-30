#include <iostream>
#include <cstdlib> 
using namespace std;


struct Node {
    int data;
    Node* next;
};


void insertAtBeginning(Node*& head, int value) {
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == nullptr) {
        cout << "Memory allocation failed!" << endl;
        return;
    }
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << value << " at the beginning.\n";
}


void insertAtEnd(Node*& head, int value) {
  
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == nullptr) {
        cout << "Memory allocation failed!" << endl;
        return;
    }
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        cout << "Inserted " << value << " at the end (it's the first node).\n";
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    cout << "Inserted " << value << " at the end.\n";
}


void deleteFromBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    free(temp); 
    cout << "Node deleted from the beginning.\n";
}


void deleteFromPosition(Node*& head, int position) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete.\n";
        return;
    }
    if (position == 0) {
        deleteFromBeginning(head);
        return;
    }
    Node* temp = head;
    for (int i = 0; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position is out of range.\n";
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete); 
    cout << "Node deleted from position " << position << ".\n";
}


void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main() {
    Node* head = nullptr;
    cout<<"Vishal Kumar.\n0126AL231142.\nAIML 3rd B\n";

    
    displayList(head);

   
    insertAtBeginning(head, 10);
    insertAtBeginning(head, 20);
    insertAtBeginning(head, 30);
    displayList(head);

    
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);
    displayList(head);

   
    deleteFromBeginning(head);
    displayList(head);

    
    deleteFromPosition(head, 2); 
    displayList(head);

    
    deleteFromPosition(head, 5); 
    displayList(head);

    return 0;
}
