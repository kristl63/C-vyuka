template <typename T>
class SimpleNode {
    private:
        T val;
        SimpleNode* next;
    public:
    SimpleNode();
    SimpleNode(T val);
    SimpleNode(T val, SimpleNode* next);
    SimpleNode* getNext();
    changeNext(SimpleNode* next);
    void print_node();
    ~SimpleNode();
};

template <typename T>
SimpleNode<T>::SimpleNode() {
    this->val = NULL;
    this->next = NULL;
}

template <typename T>
SimpleNode<T>::SimpleNode(T val) {
    this->val = val;
    this->next = NULL;
}

template <typename T>
SimpleNode<T>::SimpleNode(T val, SimpleNode* next) {
    this->val = val;
    this->next = next;
}

template <typename T>
SimpleNode<T>* SimpleNode<T>::getNext() {
    return this->next;
}

template <typename T>
void SimpleNode<T>::changeNext(SimpleNode* next) {
    this->next = next;
}

template <typename T>
void SimpleNode<T>::print_node() {
    std::cout << this->val << std::endl;
}

template <typename T>
SimpleNode<T>::~SimpleNode() {
    delete this->next;
}