#include <iostream>
#include <stdexcept>

template <typename T> class Vector{
    public:
        Vector(const int newSize); // throws std::out_of_range("Vector")
        ~Vector();
        int size() const {return actualSize;};
        void resize(const int newSize); // throws std::out_of_range("Vector")
        T& at(const int index); // throws std::out_of_range("Vector")
    private:
        T* data;
        int actualSize;
        int capacity;
};

template <typename T> Vector<T>::Vector(const int newSize){
  if (newSize < 0)
  {
    throw(std::out_of_range("Vector"));
  }
  
  data = new T[newSize];
  capacity = newSize;
  actualSize = 0;
}

template <typename T> T& Vector<T>::at(const int index){
  if (index < 0 or capacity <= 0 or index+1 > capacity)
  {
    throw(std::out_of_range("Vector"));
  }
  return data[index];
}

template <typename T> Vector<T>::~Vector(){}

template <typename T> void Vector<T>::resize(const int newSize){
  if (newSize < 0)
  {
    throw(std::out_of_range("Vector"));
  }
  else{
    T* temp = new T[capacity+(newSize-capacity)];
    actualSize = newSize;
    for (int i = 0; i < capacity; i++) {
      data[i] = temp[i];
    }
    capacity = capacity+(newSize-capacity);
    temp = data;
    delete[] temp;
  }
}