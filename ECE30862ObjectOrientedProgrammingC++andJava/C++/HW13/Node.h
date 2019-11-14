#ifndef NODE_H_
#define NODE_H_
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
   something data;
   Node* prev; 
   Node* next; 
public:
   Node(const something& data, Node* prev, Node<T>* next);
   Node(const something& data);
   void setNext(Node* nP);
   void setPrev(Node* nP);
   Node* getNext( ) const;
   Node* getPrev( ) const;
   virtual ~Node( );
   something& getData( );
   bool operator<(const Node&) const;
   bool operator==(const Node&) const;
};

template<typename T>
bool isPrimitiveType() {
    return false;
}

template<>
bool isPrimitiveType<int>() {
    return true;
}

template<>
bool isPrimitiveType<float>() {
    return true;
}

template<>
bool isPrimitiveType<double>() {
    return true;
}

template <typename T> Node<T>::Node(const T& data, Node<T>* prev, Node<T>* next) : 
   data(data), prev(prev), next(next) { }
#endif /* NODE_H_ */
