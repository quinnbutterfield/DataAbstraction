#include <iostream>
#include <stdexcept>
#include <string>
#include "ArrayList.h"
using namespace std;
int main(){
  ArrayList<int> a;
  a.push_back(3);
  a.pop_back();
  a.push_back(4);
  a.push_back(5);
  if(a.size() == 0){
    cout << "push function failed!";
  }
  if(a[1] != 5){
    cout << "index function failed!";
  }
  a.clear();
  
  if(a.size() != 0){
    cout << "clear function failed!";
  }
  ArrayList<string> b;
  b.push_back("ayy");
  b.push_back("rofl");
  b.push_back("lmao");
  b.remove(1);
  string test = b[1];
  if(test != "lmao"){
    cout << "remove function failed!";
  }
  b.insert("boop", 1);
  b.insert("rofl", 3);
  b.insert("ooo",3);
  test = b[3];
  if(test != "ooo"){
    cout << "insert function failed!";
  }
  for(int i = 0; i<b.size();++i){
    cout << b[i];
  }
  ArrayList<int> c = a;
  c.push_back(6);
  c.push_back(9);
  c.push_back(3);
  c.remove(0);
  for(int i = 0; i<c.size(); ++i){
    cout << c[i];
  }
  ArrayList<int> d;
  for(int i = 0; i < 50000; ++i){
    d.push_back(i);
  }
  long long sum = 0;
  for(auto i:d) sum +=i;
  if(sum != 1249975000){
    cout << "big test failed!";
  }



}
