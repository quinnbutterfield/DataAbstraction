#include <cstdio>
#include <iostream>
using namespace std;
template<typename T>
class FileArrayList {
    private:
        FileArrayList(const FileArrayList<T> &that) = delete;
        FileArrayList<T> operator=(const FileArrayList<T> &that) = delete;
        

        T Read(int index, FILE * f) const{
          fseek(f, sizeof(int)+ (index * sizeof(T)) , SEEK_SET);
          T tmp;
          fread(&tmp, sizeof(T), 1, f);
          return tmp;
        }
        void Write(int index, FILE * f, T val) const{
          fseek(f, sizeof(int)+ (index * sizeof(T)), SEEK_SET);
          fwrite(&val, sizeof(T), 1, f);
        }
        int getSize(FILE * f) const{
          fseek(f, 0, SEEK_SET);
          int tmp;
          fread(&tmp, sizeof(int), 1, f);
          return tmp;
        }
        void setSize(int size){
          fseek(f, 0, SEEK_SET);
          fwrite(&size, sizeof(int), 1, f); 
        }
        FILE * f;
    public:
        typedef T value_type;

        class const_iterator {
            private:
                int index;
                FILE * file;
            public:
                const_iterator(int i,FILE *fi){
                  index = i;  
                  file = fi;
                }
                const_iterator(const const_iterator &i){
                  index = i.index;
                  file = i.file;
                }
                T operator*(){
                  //basically just reading 
                  fseek(file, sizeof(int)+ (index * sizeof(T)) , SEEK_SET);
                  T tmp;
                  fread(&tmp, sizeof(T), 1, file);
                  return tmp;

                }
                bool operator==(const const_iterator &i) const{
                  return index == i.index;
                }
                bool operator!=(const const_iterator &i) const{
                  return index != i.index;
                }
                const_iterator &operator=(const const_iterator &i){
                  index = i.index;
                  file = i.file;
                  return *this;
                }
                const_iterator &operator++(){
                  index++;
                  return *this;
                }
                const_iterator &operator--(){
                  index--;
                  return *this;
                }
                const_iterator operator++(int){
                    auto tmp = *this;
                    index++;
                    return tmp;
                }
                const_iterator operator--(int){
                    auto tmp = *this;
                    index--;
                    return tmp;
                }

                friend class FileArrayList;
        };

        // General Methods
        FileArrayList(const std::string &fname){
          f = fopen(fname.c_str(), "r+");
          if(f == NULL){
            f = fopen(fname.c_str(), "w+");
            setSize(0);
          }
        }

        template<typename I>  // The type I will be an iterator.
        FileArrayList(I begin,I end,const std::string &fname) {
            f = fopen(fname.c_str(), "w+");
            for(auto i = begin; i != end; i++){
              push_back(*i);
            }
        }
        ~FileArrayList(){
          fclose(f);
        }
        void push_back(const T &t){
            insert(end(), t);
        }
        void pop_back(){
          setSize(getSize(f)-1);
        }
        int size() const{
          return getSize(f);
        }
        void clear(){
          setSize(0);
        }
        const_iterator insert(const_iterator position, const T &t){
          for(auto i = end(); i != position; --i){
            T prev = Read(i.index-1, f);  
            Write(i.index, f, prev); 
          }
          Write(position.index, f, t);
          setSize(size()+1);
          return const_iterator(position.index, f);
        }

        T operator[](int index) const{
          Read(index, f);
        }
        const_iterator erase(const_iterator position){
          for(auto i = position; i != end(); ++i){
            T next = Read(i.index+1, f);
            Write(i.index, f, next);
          }
          setSize(size()-1);
          return const_iterator(position.index, f);
        }
        void set(const T &value,int index){
          Write(index, f, value);
        }

        const_iterator begin(){
          return const_iterator(0, f);
        }
        const_iterator begin() const{
          return const_iterator(0, f);
        }
        const_iterator end(){
          return const_iterator(size(), f);
        }
        const_iterator end() const{
          return const_iterator(size(), f);
        }
        const_iterator cbegin() const{
          return const_iterator(0, f);
        }
        const_iterator cend() const{
          return const_iterator(size(), f);
        }
};

