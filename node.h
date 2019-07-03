#ifndef NODE_H
#define NODE_H
template<typename T>
struct Node{
    Node *next;
    Node *prev;
    T value;
    bool is_initial = false;
};
#endif // NODE_H
