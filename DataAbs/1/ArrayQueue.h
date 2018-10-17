#include <iostream>
#include <stdexcept>
#include <string>
#include "Queue.h"
using namespace std;
template <typename T>
class ArrayQueue: Queue<T> {
    public:
        ArrayQueue(){
          sz = 10;
          elem = new T[sz];
          front = 0;
          numElem = 0;

          
        }
        ArrayQueue(const ArrayQueue<T>& arr){
          sz = arr.sz;
          elem = new T[sz];
          front = arr.front;
          numElem = arr.numElem;
          for(int i = 0; i<sz; i++){
            elem[i] = arr.elem[i];
          }
        }
        void enqueue(const T &t){
          if(numElem == sz){
            T* tmp = new T[sz*2];
            for(int i = 0; i< sz; ++i){
              tmp[i] = elem[(i+front) % sz];
            }
            front = 0;
            delete[] elem;
            elem = tmp;
            sz *= 2;
          }
          elem[(numElem+front) % sz] = t;
          numElem++;  
          //cout << "queued" << t << "\n";
        }
        ~ArrayQueue(){
          delete[] elem;
        }
        T dequeue(){
         if(isEmpty()){
          throw std::underflow_error("nothing in the queue!");
         }
         else{
          T ret = elem[front];
          front = (front + 1) % sz;
          //cout << "dequeued " << ret << "\n";
          numElem--;
          return ret;
         }
        }
        T peek() const {
          if(isEmpty()){
            throw std::underflow_error("nothing in the queue!");
          }
          else {
            T ret = elem[numElem-1];
            //cout << "peeked " << ret << "\n";
            return ret;
          }
        }
        bool isEmpty() const {
          if(numElem == 0){
            //cout << "queue is empty\n";
            return true;
          }
          else{
            //cout << "queue is not empty\n";
            return false;
          }
        }
    private:
      int sz;
      T* elem;
      int front;
      int numElem;
        

};
