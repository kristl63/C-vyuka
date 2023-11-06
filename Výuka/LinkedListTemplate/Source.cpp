#include <iostream>

using namespace std;


struct Node
{
	int val;
	Node* next;

    //vytiskne jeden prvek
    void print_node();
    //vytiskne prvek a všechny navazující
    void print_LL();
    //pridá na konec listu jeden prvek
    void push_back_val(int val);
    //na daný index vloží prvek a všechny ostatní posune
    void insert_val(int idx, int val);
    //vrátí pointer na prvek, který se nachází na daném indexu
    Node* operator[](int index);
    //odstraní prvek na daném indexu
    void delete_node(int idx);  

};


int main()
{
    Node LL;
    LL.val = 0;
    LL.next = NULL;

    LL.push_back_val(1);
    LL.push_back_val(2);
    LL.push_back_val(3);

    LL.print_LL();
    LL[1]->print_node();

    LL.insert_val(2,4);
    LL.delete_node(3);
    LL.print_LL();	
}

void print_node(Node* node)
{
    cout << node->val << endl;
}

void print_LL(Node* node)
{
    Node* current = node;
    while (current != NULL)
    {
        cout << current->val << endl;
        current = current->next;
    }
}

void push_back_val(Node* node, int val)
{
    Node* current = node;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new Node;
    current->next->val = val;
    current->next->next = NULL;
}

void insert_val(Node* node, int idx, int val)
{
    Node* current = node;
    for (int i = 0; i < idx; i++)
    {
        current = current->next;
    }
    Node* new_node = new Node;
    new_node->val = val;
    new_node->next = current->next;
    current->next = new_node;
}

Node* operator[](Node* node, int index)
{
    Node* current = node;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current;
}

void delete_node(Node* node, int idx)
{
    Node* current = node;
    for (int i = 0; i < idx-1; i++)
    {
        current = current->next;
    }
    Node* to_delete = current->next;
    current->next = current->next->next;
    delete to_delete;
}


