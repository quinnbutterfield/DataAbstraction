#include <iostream>
#include <stdexcept>
#include <string>
#include "Stack.h"
using namespace std;
template <typename T>
class ArrayStack: Stack<T> {
  public:
      ArrayStack(){
         sz = 10;
         elem = new T[sz];
         top = 0;
      }
      ArrayStack(const ArrayStack<T>& arr){
        sz = arr.sz;
        top = arr.top;
        elem = new T[sz];
        for(int i = 0; i<sz;i++){
          elem[i]= arr.elem[i];
        }
      }
      ArrayStack<T>& operator=(const ArrayStack<T>& arr){
        if(this != &arr){
          delete[] elem;
          elem = new T[arr.sz];
          top = arr.top;
          sz = arr.sz;
          for(int i = 0; i<sz; i++){
            elem[i] = arr.elem[i];
          }
        }
      }
      ~ArrayStack(){
        delete[] elem;
      }
      void push(const T &t){
        if(top == sz-1){
          T* tmp = new T[sz*2];
          for(int i =0; i<=top;++i){
            tmp[i]=elem[i];
          }
          delete[] elem;
          elem = tmp;
          sz *= 2;
        }
        elem[top] = t;
        top++;
       // cout << "pushed " << t << "\n"; 
      }
      T pop(){
        if(top < 1){
         throw std::underflow_error("nothing in the stack!"); 
          
        }
        top--;
        T ret = elem[top];
        //cout << "popped " << ret << "\n"; 
        return ret;  
      }
      T peek() const {
        if(top < 1){
         throw std::underflow_error("nothing in the stack!"); 
          
        }
        else {
          T ret = elem[top-1];
          cout << "peeked " << ret << "\n"; 
          return ret;
        }
      }
      bool isEmpty() const {
        if(top == 0){
          //cout << "stack is empty\n";
          return true;
        }
        else{
          //cout << "stack is not empty\n";
          return false;
        }
      }
  private:
    int sz;
    T* elem;
    int top;

};

