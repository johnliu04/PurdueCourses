#ifndef NODE_H_
#define NODE_H_
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
   T data;
   Node* prev; 
   Node* next; 
public:
   Node(const T& data, Node<T>* prev, Node<T>* next);
   Node(const T& data);
   void setNext(Node<T>* nP){this->next = nP;}
   void setPrev(Node<T>* nP){this->prev = nP;}
   Node* getNext( ) {return this->next;}
   Node* getPrev( ) {return this->prev;}
   virtual ~Node( );
   T& getData( ){return this->data;}
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

template <typename T> Node<T>::Node(const T& data): data(data){}

template <typename T> Node<T>::~Node( ){}

#endif /* NODE_H_ */
