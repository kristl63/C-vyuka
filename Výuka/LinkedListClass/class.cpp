
#include <iostream>

using namespace std;

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void push_front(int data) {
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = head;
        head = new_node;
    }

    void push_back(int data) {
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = nullptr;

        if (head == nullptr) {
            head = new_node;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    void insert(int data, int index) {
        Node* new_node = new Node;
        new_node->data = data;

        if (index == 0) {
            new_node->next = head;
            head = new_node;
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                if (current == nullptr) {
                    throw out_of_range("Index out of range");
                }
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
    }

    void remove(int index) {
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                if (current == nullptr) {
                    throw out_of_range("Index out of range");
                }
                current = current->next;
            }
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    int size() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(0);
    list.insert(4, 4);
    list.remove(2);
    list.print();
    return 0;
}
