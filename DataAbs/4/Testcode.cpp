#include<iostream>
#include "FileArrayList.h"
using namespace std;
int main(){
FileArrayList<int> al("al.bin");
al.push_back(3);
al.pop_back();
al.push_back(4);
al.push_back(5);
if(al.size() == 0){
  cout << "push function failed!";
}
if(al[1] != 5){
  cout << "index function failed!";
}
al.clear();


if(al.size() != 0){
  cout << "clear function failed!";
}
FileArrayList<string> b("b.bin");
b.push_back("ayy");
b.push_back("rofl");
b.push_back("lmao");
string test = b[1];
if(test != "rofl"){
  cout << "erase function failed!";
}
FileArrayList<int> c("c.bin");
for(int i = 0; i < 50000; ++i){
  c.push_back(i);
}
long long sum = 0;
for(auto i:c) sum += i;
if(sum != 1249975000){
  cout << "big test failed!!!";
}

};
