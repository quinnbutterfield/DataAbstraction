#include <iostream>
using namespace std;
template<typename T>
class LinkedList{
  private:   
  struct Node{
    T data;
    Node* prev;
    Node* next;
  };
  int sz;
  Node* sentinel;
  public:
   typedef T value_type;
   class iterator {
      private:
          Node* x;
      public:
              iterator(){
                x = nullptr;
              }
              iterator(Node* n){
                x = n;
              }
              iterator(const iterator &i){
                x = i.x;
              }
              T &operator*() {
                return x -> data;
              }
              bool operator==(const iterator &i) const {
                return x == i.x;
              }
              bool operator!=(const iterator &i) const { 
                return x != i.x;
              }
              iterator &operator=(const iterator &i) { 
                x = i.x;
                return *this;
              }
              iterator &operator++() { 
                x = x -> next;
                return *this;
              }
              iterator &operator--() {
                x = x -> prev;
                return *this;
              }
              iterator operator++(int) {
                      auto tmp = x;
                      x = x -> next;
                      return iterator(tmp);
              }
              iterator operator--(int) {
                      auto tmp = x;
                      x = x -> prev;
                      return iterator(tmp);
              }
              friend class const_iterator;
              friend class LinkedList;
    };

class const_iterator {
      private:
          Node* x;
      public:
              const_iterator(){
                x = nullptr;
              }
              const_iterator(Node* n){
                x = n;
              }
              const_iterator(const const_iterator &i){
                x = i.x;
              }
              T &operator*() {
                return x -> data;
              }
              bool operator==(const const_iterator &i) const {
                return x == i.x;
              }
              bool operator!=(const const_iterator &i) const { 
                return x != i.x;
              }
              const_iterator &operator=(const const_iterator &i) { 
                x = i.x;
                return *this;
              }
              const_iterator &operator++() { 
                x = x -> next;
                return *this;
              }
              const_iterator &operator--() {
                x = x -> prev;
                return *this;
              }
              const_iterator operator++(int) {
                      auto tmp = x;
                      x = x -> next;
                      return const_iterator(tmp);
              }
              const_iterator operator--(int) {
                      auto tmp = x;
                      x = x -> prev;
                      return const_iterator(tmp);
              }
              friend class iterator;
              friend class LinkedList;
    };

LinkedList(){
  sz = 0;
  sentinel = new Node;
  sentinel -> next = sentinel;
  sentinel -> prev = sentinel;
}
LinkedList(const LinkedList & other){
  sz = 0;
  sentinel = new Node;
  sentinel -> next = sentinel;
  sentinel -> prev = sentinel;

  for (auto x : other){
    push_back(x);
  }
}
LinkedList &operator=(const LinkedList &al){
 clear();
 for(auto x : al){
   push_back(x);
 }
 return *this;
}
~LinkedList() {
  clear();
  delete sentinel;
}
void pop_back(){
  erase(sentinel -> prev);
}
void push_back(const T &t){
  insert(sentinel, t);
}
void clear() {
  while(sz > 0){
    pop_back();
  }
}
int size() const {
  return sz;
}
T &operator[](int index) {
  auto iter = begin();
  for(int i = 0; i<index; i++){
    iter++;
  }
  return *iter;
}
const T &operator[](int index) const {
  auto iter = begin();
  for(int i = 0; i<index; i++){
    iter++;
  }
  return *iter;
}

iterator insert(iterator position, const T &t){
    auto ptr = position.x;
    auto newNode = new Node{t, ptr->prev,ptr};
    ptr->prev->next = newNode;
    ptr->prev = newNode;
    sz++;
    return iterator(newNode);
}
iterator erase(iterator position){
    auto ptr = position.x;
    ptr->prev->next = ptr-> next;
    ptr->next->prev = ptr->prev;
    auto tmp = ptr->next;
    delete ptr;
    sz--;
    return iterator(tmp);
}


iterator begin(){
  return iterator(sentinel -> next);
}
const_iterator begin() const{
  return const_iterator(sentinel -> next);
}
iterator end(){
  return iterator(sentinel);
}
const_iterator end() const {
  return const_iterator(sentinel);
}
const_iterator cbegin() const{
  return begin();
}
const_iterator cend() const{
  return end();
}






};
