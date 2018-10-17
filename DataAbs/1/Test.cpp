#include <iostream>
#include <string>
#include "ArrayStack.h"
#include "ArrayQueue.h"
using namespace std;
int main(){
  ArrayStack<int> a;
  if(!a.isEmpty()){
    throw std::runtime_error("isEmpty failed!");
  }
  
  a.push(3);
  a.push(4);
  a.push(9);
  a.push(4);
  a.push(4);
  a.push(4);
  a.push(9);
  a.push(4);
  a.push(4);
  a.push(9);
  a.push(4);
  a.push(9);
  a.push(4);

  //LARGE TEST
  ArrayStack<int> large;
  for(int i = 0; i<1100;++i){
    large.push(i);
  }
  for(int i = 0; i<1100;++i){
    if(large.pop() != 1099-i){
        throw std::runtime_error("large test failed!");
    }
  }
  a.isEmpty();

  a.pop();
  a.peek();
  
  ArrayStack<int> b{a};
  b.pop();
  b.push(69);
  b.pop();
  ArrayStack<string> s;
  s.push("ayy");
  s.pop();

  cout << "TESTING QUEUE\n";
  ArrayQueue<int> q;
  q.isEmpty();
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(2);
  q.enqueue(2);
  q.enqueue(2);
  q.enqueue(2);
  q.enqueue(2);
  q.enqueue(2);
  q.enqueue(2);
  q.enqueue(2);
  q.enqueue(2);
  q.enqueue(2);
  //Large test for queue
  //
  ArrayQueue<int> lmao;
  for(int i = 0; i<1100; ++i){
    lmao.enqueue(i);
  }
  for(int i = 0; i<1100; ++i){
    if(lmao.dequeue() != i){
      throw std::runtime_error("large queue test failed!");
    }
  }
  q.peek();
  q.dequeue();
  ArrayQueue<string> ayy;
  ayy.enqueue("ayy");
  ayy.enqueue("lmao");
  ayy.dequeue();
  ayy.dequeue();
  cout << "\nTESTS SUCCEEDED\n";
}
