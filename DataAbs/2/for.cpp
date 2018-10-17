#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a;
    int b;
    for(int i = a; i <= b; i++){
        if(i <= 9 ){
            switch(i) {
                case 1 : cout << "one";
                case 2 : cout << "two";
                case 3 : cout << "three";
                case 4 : cout << "four";
                case 5 : cout << "five";
                case 6 : cout << "six";
                case 7 : cout << "seven";
                case 8 : cout << "eight";
                case 9 : cout << "nine";
                        
            }
        }
        else{
            if(i % 2 == 0){
                cout << "even";
            }
            else{
                cout << "odd";
            }
        }
    }
    return 0;
}
