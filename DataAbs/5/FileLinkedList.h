#include <cstdio>
template<typename T>
class FileLinkedList {
		private:
				struct Node{
						T data;
						Node* prev;
						Node* next;
				}
        FileLinkedList(const FileLinkedList<T> &that) = delete;
        FileLinkedList<T> operator=(const FileLinkedList<T> &that) = delete;
        

        int ReadPrev(int node, FILE* file){
            fseek(file, node+sizeof(T), SEEK_SET);
            int ret;
            fread(&ret, sizeof(int), 1, file);
            return ret;
        }
        int WritePrev(int node, int value, FILE* file){
            fseek(file, node+sizeof(T), SEEK_SET);
        }
        int ReadNext(int node, FILE* file){
            fseek(file, node+sizeof(T)+sizeof(int),SEEK_SET);
            int ret;
            fread(&ret, sizeof(int), 1, file);
            return ret;
        }
        T ReadData(int node, FILE* file){
          fseek(file, node, SEEK_SET);
          T ret;
          fread(&ret, sizeof(T), 1, file);
          return ret;
        }
        int AllocateNode(FILE* file){
          int freelist;
          fseek(file, sizeof(Node), SEEK_SET);
          fread(&freelist, sizeof(int), 1, f);
          int ret;
          if(freelist !=-1){
              ret = freelist;
              freelist = ReadNext(freelist, file);
              fseek(file, sizeof(Node), SEEK_SET);
              fwrite(&freelist, sizeof(int), 1, f);
          }
          else{
            ret= 
          }
          return ret;
        }

        // TODO - Your private data.
        // TODO - Private helper functions. (Maybe file IO with an index.)
    public:
        typedef T value_type;

        class const_iterator {
                // TODO - Your private data.
            public:
                const_iterator(int i,FILE *f);
                const_iterator(const const_iterator &i);
                T operator*();
                bool operator==(const const_iterator &i) const;
                bool operator!=(const const_iterator &i) const;
                const_iterator &operator=(const const_iterator &i);
                const_iterator &operator++();
                const_iterator &operator--();
                const_iterator operator++(int);
                const_iterator operator--(int);

                friend class FileLinkedList;
        };

        // General Methods
        FileLinkedList(const std::string &fname);

        template<typename I>  // The type I will be an iterator.
        FileLinkedList(I begin,I end,const std::string &fname) {
            // TODO - Write this one here. It is easier than trying to fight with adding a template below.
        }
        ~FileLinkedList();
        void push_back(const T &t) { insert(end(),t); }
        void pop_back() { erase(--end()); }
        int size() const;
        void clear() { while (size()>0) pop_back(); }
        const_iterator insert(const_iterator position, const T &t);
        T operator[](int index) const{
            auto itr=begin();
            for (int i=0;i<index;++i) ++itr;
            return *itr;
        }
        const_iterator erase(const_iterator position);
        void set(const T &value,int index);
        void set(const T &value,const_iterator position);

        const_iterator begin();
        const_iterator begin() const;
        const_iterator end();
        const_iterator end() const;
        const_iterator cbegin() const;
        const_iterator cend() const;
};
