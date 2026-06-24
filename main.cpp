#include <iostream>
#include <string>

// ==========================================
// DATA STRUCTURE 1: SINGLY LINKED LIST
// ==========================================

// Node structure for the Linked List
struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() { head = nullptr; }

    // Complexity: O(1) - Fast insertion at the beginning
    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        std::cout << "Inserted " << value << " into Linked List.\n";
    }

    // Complexity: O(n) - Needs to search the list to find the value
    void remove(int value) {
        Node* temp = head;
        Node* prev = nullptr;

        if (temp != nullptr && temp->data == value) {
            head = temp->next;
            delete temp;
            std::cout << "Deleted " << value << " from Linked List.\n";
            return;
        }

        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout << "Value " << value << " not found in Linked List.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        std::cout << "Deleted " << value << " from Linked List.\n";
    }

    // Complexity: O(n) - Searches through elements
    bool search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) return true;
            current = current->next;
        }
        return false;
    }

    // Displays the list
    void display() {
        Node* current = head;
        std::cout << "Linked List: ";
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "NULL\n";
    }
};

// ==========================================
// DATA STRUCTURE 2: STACK (Using Pointers)
// ==========================================

class Stack {
private:
    Node* top;

public:
    Stack() { top = nullptr; }

    // Complexity: O(1) - Pushing to top is instantaneous
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        std::cout << "Pushed " << value << " onto Stack.\n";
    }

    // Complexity: O(1) - Popping from top is instantaneous
    void pop() {
        if (top == nullptr) {
            std::cout << "Stack Underflow! Cannot pop.\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        std::cout << "Popped " << temp->data << " from Stack.\n";
        delete temp;
    }

    // Complexity: O(1)
    int peek() {
        if (top != nullptr) return top->data;
        return -1;
    }

    void display() {
        Node* current = top;
        std::cout << "Stack (Top -> Bottom): ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }
};

// ==========================================
// DRIVER PROGRAM (Demonstrating functionality)
// ==========================================
int main() {
    std::cout << "--- DEMONSTRATING LINKED LIST ---\n";
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display();

    std::cout << "Searching for 20: " << (list.search(20) ? "Found" : "Not Found") << "\n";
    list.remove(20);
    list.display();

    std::cout << "\n--- DEMONSTRATING STACK ---\n";
    Stack stack;
    stack.push(100);
    stack.push(200);
    stack.push(300);
    stack.display();

    stack.pop();
    stack.display();

    return 0;
}