


#include <stdlib.h>
#include <iostream>
#include <assert.h>

using namespace std;



class int_vec {
private:
    int capacity; 
    int* arr;    
    int size;     
public:

  
    int_vec()
        : capacity(10), arr(new int[capacity]), size(0)
    { }

    int_vec(int sz, int fill_value)
        : capacity(10), size(sz)
    {
        if (size < 0) cout<<("can't construct int_vec of negative size");
        if (size > capacity) capacity += size;
        arr = new int[capacity];
        for (int i = 0; i < size; ++i) {
            arr[i] = fill_value;
        }
    }

    // Copy constructor
    int_vec(const int_vec& other)
        : capacity(other.capacity), arr(new int[capacity]), size(other.size)
    {
        for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }

    //Copy assigment operators

      int_vec& operator=(const int_vec& other) {
          SetCapacity(other.capacity);
          SetArr(other.arr);
          SetSize(other.size);
          return *this;
    }
      int_vec& operator+(const int_vec& other) {
          SetCapacity(other.capacity);
          SetArr(other.arr);
          SetSize(other.size);
          return *this;
      }
      int_vec& operator-(const int_vec& other) {
          SetCapacity(other.capacity);
          SetArr(other.arr);
          SetSize(other.size);
          return *this;
      }



    ~int_vec() {
        delete[] arr;
    }

    int get_size() const {
        return size;
    }

    int get_capacity() const {
        return capacity;
    }

    int get(int i) const {
        if (i < 0 || i > size) cout<<("get: index out of range");
        return arr[i];
    }

    void SetCapacity(int capacity) {
        this -> capacity = capacity;
    }
    void SetArr(int *arr) {
        this->arr = arr;
    }
    void SetSize(int size) {
        this->size = size;
    }

    void set(int i, int x) {
        if (i < 0 || i > size) cout << ("get: index out of range");
        arr[i] = x;
    }


        void addElementToStart(int elem) {
        int* temp = new int[size + 1];
        temp[0] = elem;
        for (int i = 0; i < size; i++) {
            temp[i + 1] = arr[i];
        }
        temp[size] = elem;
        delete[] arr;
        arr = temp;
        temp = nullptr;
        size++;
    }
        void addElementToEnd(int elem) {
            int* temp = new int[size + 1];
            for (int i = 0; i < size; i++) {
                temp[i] = arr[i];
            }
            temp[size] = elem;
            delete[] arr;
            arr = temp;
            temp = nullptr;
            size++;
        }


        void AddElementByIndex(int elem,int index) {
           
            int *temp = new int[size + 1];
            for (size_t i = 0; i < size; i++)
            {
                temp[i] = arr[i];
            }
            temp[index] = elem;
            delete[]arr;
            arr = temp;
            temp = nullptr;
            size++;

        }



        //void DeleteElementByIndex( int elem) {
        //    int index = -1;

        //    for (size_t i = 0; i < size; i++)
        //    {
        //        if (i == index) {
        //            index = i;
        //            break;
        //        }
        //    }
        //    if (index != -1) {
        //        int_vec** temp = new int_vec * [size - 1];
        //        for (size_t i = 0; i < index; i++)
        //        {
        //            temp[i] = arr[i];
        //        }

        //        for (size_t i = index; i < size; i++) {
        //            temp[i - 1] = arr[i + 1];
        //        }
        //        delete[]arr;
        //        arr = temp;
        //        size--;
        //        temp = nullptr;
        //    }
        //}


    void print() const {
        if (size == 0) {
            cout << "{}";
        }
        else {
         
            cout << arr[0];
            for (int i = 1; i < size; ++i) { 
                cout << ", " << arr[i];
            }
      
        }
    }

    void println() const {
        print();
        cout << "\n";
    }

    void append(int x) {
        if (size >= capacity) {
            capacity = 2 * capacity;          
            int* new_arr = new int[capacity]; 
        

            for (int i = 0; i < size; ++i) {  
                new_arr[i] = arr[i];          
            }

            delete[] arr;                     

            arr = new_arr;                    
        }
        assert(size < capacity);
        arr[size] = x;
        size++;
    }

}; 

int main() {
    cout << "Array : " << endl;
    int_vec v;
    v.println();
    cout << endl;
    cout << "Array after append elements : " << endl;
    for (int i = 0; i < 25; ++i) {
        v.append(i);
    }
    v.println();
    cout << "Adding element to end : " << endl;
    v.addElementToEnd(15) ;
    v.println();
    cout << "Adding element to start : " << endl;
    v.addElementToStart(15);
    v.println();

    cout << "Add element by index : " << endl;
    v.AddElementByIndex(150,9);
    v.println();

/*    cout << "Delete element by index : " << endl; 
    v.DeleteElementByIndex(3);
    v.println()*/;
}
 









