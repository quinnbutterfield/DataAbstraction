#include <iostream>
#include <stdexcept>
#include <string>
#include "LinkedList.h"
using namespace std;
int main(){
  LinkedList<int> a;
  a.push_back(3);
  a.pop_back();
  a.push_back(4);
  if(a.size() == 0){
    cout << "push function failed!";
  }
  if(a[0] != 4){
    cout << "index function failed!";
  }
  a.clear();

  if(a.size() != 0){
    cout << "clear function failed!";
  }
  LinkedList<string> b;
  b.push_back("hey");
  b.push_back("hey");
  b.push_back("you");
  b.erase(++b.begin());
  string test = b[1];
  if(test != "you"){
    cout << "remove function failed";
  }
  b.insert(++b.begin(),"I");
  b.insert(++b.begin(), "like");
  test = b[1];
  if(test != "like"){
    cout << "insert function failed!";
  }
  LinkedList<int> d;
  for(int i = 0; i < 50000; ++i){
    d.push_back(i);
  }
  long long sum = 0;
  for(auto i:d) sum +=i;
  if(sum != 1249975000){
    cout << "big test failed!";
  }

}
