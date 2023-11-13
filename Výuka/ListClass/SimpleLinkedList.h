#pragma once
#include "SimpleNode.h"

template <typename T>
class SimpleLinkedList {
private:
    SimpleNode<T>* head;

public:public:
SimpleLinkedList();
void print_LL();
void push_back_val(T val);
void insert_val(int idx, T val);
Node* operator[](int idx);
void remove_val(T val);
};