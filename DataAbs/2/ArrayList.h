#include <stdexcept>
#include <iostream>
using namespace std;
template<typename T>
class ArrayList {
    public:

        typedef T value_type;
        class iterator {
          public:  
            iterator(T *l){
              current = l;
            }
            iterator(){
              current = nullptr;
            }
            iterator(const iterator &i){
              current = i.current;
            }
            T &operator*(){
              return *current;
            }
            bool operator==(const iterator &i) const{
              return current == i.current;
            }
            bool operator!=(const iterator &i) const{
              return current != i.current;
            }
            iterator &operator=(const iterator &i){
              current = i.current;
              return *this;
            }
            iterator &operator++(){
              current++;
              return *this;
            }
            iterator &operator--(){
              current--;
              return *this;
            }
            iterator operator++(int){
              auto tmp = *this;
              current++;
              return tmp;
            }
            iterator operator--(int){
              auto tmp = *this;
              current--;
              return tmp;
            }
          private:
            T* current;
        };
       
        class const_iterator{
          
          public:  
            const_iterator(T *l){
              current = l;
            }
            const_iterator(){
              current = nullptr;
            }
            const_iterator(const const_iterator &i){
              current = i.current;
            }
            T &operator*(){
              return *current;
            }
            bool operator==(const const_iterator &i) const{
              return i.current == i.current;
            }
            bool operator!=(const const_iterator &i) const{
              return i.current != i.current;
            }
            const_iterator &operator=(const const_iterator &i){
              current = i.current;
              return *this;
            }
            const_iterator &operator++(){
              current++;
              return *this;
            }
            const_iterator &operator--(){
              current--;
              return *this;
            }
            const_iterator operator++(int){
              auto tmp = *this;
              current++;
              return tmp;
            }
            const_iterator operator--(int){  
              auto tmp = *this;
              current--;
              return tmp;
            }
          private:
              T* current;
        };

        ArrayList(){
          sz = 10;
          elem = new T[sz];
          back = 0;
        }
        ArrayList(const ArrayList &that){
          elem = new T[that.back];
          sz = that.sz;
          back = that.back;
          for(int i =0; i < back; i++){
            elem[i] = that.elem[i];
          }
        }
        ArrayList<T> &operator=(const ArrayList<T> &al){
          delete[] elem;
          elem = new T[al.sz];
          back = al.back;
          sz = al.sz;
          for(int i=0; i <back; i++){
            elem[i] = al.elem[i];
          }
          return *this;
        }

        ~ArrayList(){
          delete[] elem;
        }
        void push_back(const T &t){
          if(back == sz-1){
            T* tmp = new T[sz*2];
            for(int i = 0; i<=back;++i){
              tmp[i]=elem[i];
            }
            delete[] elem;
            elem = tmp;
            sz *= 2;
          }
          elem[back] = t;
          back++;
        }
        void pop_back(){
         if(back == 0){
             throw std::underflow_error("nothing in the list!");
         }
         back--;

        }
        int size() const{
          return back;
        }
        void clear(){
          back = 0;
        }
        void insert(const T &t, int index){
          if(index > back || index < 0){
            throw std::out_of_range("index out of range!");
          }
          if(back == sz-1){
            T* tmp = new T[sz*2];
            for(int i = 0; i<=back;++i){
                tmp[i]=elem[i];
            }
            delete[] elem;
            elem = tmp;
            sz*= 2;
            back++;
          }
          for(int i = back; i > index; --i){
            elem[i] = elem[i-1];
          }
          elem[index] = t;
          back++;
        }
        const T &operator[](int index) const {
          
          if(index >= back || index < 0){
            throw std::out_of_range("index out of range!");
          }
          return elem[index];
        }
        T &operator[](int index){
          if(index >= back || index < 0){
            throw std::out_of_range("index out of range!");
          }
          //cout << "value at index " << index << " is " << elem[index] << "\n";

          return elem[index];
        }
        void remove(int index){
          //cout << "removing " << elem[index] << "at index " << index << "\n";
          for(int i = index; i < back-1; ++i){
            //cout << "setting " << elem[i] << " equal to " << elem[i+1] << "\n";
            elem[i] = elem[i+1];
          }
          back--;
        }
        
        iterator begin(){
          return iterator(&elem[0]);
        }
        const_iterator begin() const{
          return const_iterator(&elem[0]);

        }
        iterator end(){
          return iterator(elem+back);
        }
        const_iterator end() const{
          return iterator(&elem[0]);

        }
        const_iterator cbegin() const{
          return const_iterator(&elem[0]);
        }
        const_iterator cend() const{
          return const_iterator(elem+back);
        }
    private:
        int sz;
        T* elem;
        int back;

    
};


