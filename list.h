#ifndef LIST_H
#define LIST_H
#include "node.h"
#include<iostream>
#include<vector>
template <typename T>
class List{
public:
    List();
    ~List();
    //prints all node values from the speficied node
    void print_nodes(Node<T>*);
    //prints nodes
    void print();
    //adds a node to the list
    void add_node(Node<T>* currentNode,T value);
    //adss a new value
    void add(T);
    //removes node from the list
    void remove_node(Node<T>*);
    //reverses the linked list from a given node at a given index in the container
    void reverse_list(Node<T>*,int&);
    //reverses the whole linked list
    void reverse();
private:
    Node<T>* root;//root node
    int length;//number of noded
    std::vector<T> container;//contains values
};

template<typename T>
List<T>::List(){
    root = new Node<T>;
    root->next = nullptr;
    root->prev = nullptr;
    root->is_initial = true;
    length = 0;
}

template<typename T>
List<T>::~List(){}

template<typename T>
void List<T>::print_nodes(Node<T>* node){
    if (node->next==nullptr) {
        std::cout<<node->value<<"-->null";
        return;
    }
    else {
        std::cout<<node->value<<"-->";
        print_nodes(node->next);
    }
}

template<typename T>
void List<T>::print(){
    std::cout<<std::endl;
    print_nodes(root);
    std::cout<<std::endl;
}

template<typename T>
void List<T>::add_node(Node<T>* current_node, T value){
    if(current_node->is_initial){
        current_node->is_initial = false;
        current_node->value = value;
        length += 1;
        return;
    }else if(current_node->next == nullptr){
        Node<T> *new_node = new Node<T>;
        new_node->prev = current_node;
        new_node->next = nullptr;
        new_node->value = value;
        new_node->is_initial = false;
        current_node->next = new_node;
        length += 1;
        return;
    }else{
        add_node(current_node->next,value);
    }
}

template<typename T>
void List<T>::add(T value){
    container.push_back(value);
    add_node(root,value);
}

template<typename T>
void List<T>::reverse_list(Node<T>* node, int& index){
    node->value = container[container.size() - (index + 1)];
    index += 1;
    if(node->next == nullptr){
        return;
    }else{
        return reverse_list(node->next,index);
    }
}

template<typename T>
void List<T>::reverse(){
    int index = 0;
    reverse_list(root,index);
}

template<typename T>
void List<T>::remove_node(Node<T> *node){
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
}

#endif // LIST_H
