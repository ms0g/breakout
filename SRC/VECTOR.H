#ifndef VECTOR_H
#define VECTOR_H

#include <iostream.h>
#include <stdlib.h>
#include <stddef.h>

template <class T>
class vector {
public:
    vector();

    vector(int size);

    ~vector();
    
    int size(void) const;

    int isEmpty(void) const;

    void clear(void);

    T& begin(void);

    T& end(void);

    const T& cbegin(void) const;
    
    const T& cend(void) const;

    T& get(int index) const;

    void set(int index, T& value);

    void insert(int index, T& value);
    
    void remove(int index);

    void push_back(T& value);
    
    T& operator[](int index);
private:
    T* m_pData;
    int m_count;
    int m_capacity;

};

template <class T>
vector<T>::vector() {
    m_pData = NULL;
    m_count = 0;
    m_capacity = 1;
}

template <class T>
vector<T>::vector(int size) {
    m_pData = new T[size];
    m_capacity = size;
    m_count = 0;
}

template <class T>
vector<T>::~vector() {
    if (m_pData != NULL) delete[] m_pData;
}

template <class T>
int vector<T>::size(void) const {
    return m_count;
}

template <class T>
int vector<T>::isEmpty(void) const {
    return m_count == 0;
}

template <class T>
void vector<T>::clear(void){
    if (m_pData != NULL) delete[] m_pData;
    m_count = 0;
    m_capacity = 1;
    m_pData = NULL;
}

template <class T>
T& vector<T>::begin(void) {
    return m_pData[0];
}

template <class T>
T& vector<T>::end(void) {
    return m_pData[m_count - 1];
}

template <class T>
const T& vector<T>::cbegin(void) const {
    return m_pData[0];
}

template <class T>
const T& vector<T>::cend(void) const {
    return m_pData[m_count - 1];
}

template <class T>
T& vector<T>::get(int index) const {
    if (index < 0 || index >= m_count) {
        cout << "get:Index out of bounds";
        exit(1);
    }
    return m_pData[index];
}

template <class T>
void vector<T>::set(int index, T& value) {
    if (index < 0 || index > m_count) {
        cout << "set:Index out of bounds";
        exit(1);
    }
    m_pData[index] = value;
}

template <class T>
void vector<T>::insert(int index, T& value) {
    if (index < 0 || index > m_count) {
        cout << "insert:Index out of bounds";
        exit(1);
    }
    if (m_count == m_capacity) {
        T* temp = new T[2 * m_capacity];
 
        // copying old array elements to new array
        for (int i = 0; i < m_capacity; i++) {
            temp[i] = m_pData[i];
        }
 
        // deleting previous array
        delete[] m_pData;
        m_capacity *= 2;
        m_pData = temp;
    }
   
    m_pData[index] = value;
    m_count++;
}

template <class T>
void vector<T>::remove(int index) {
    if (index < 0 || index > m_count) {
        cout << "remove:Index out of bounds";
        exit(1);
    }
    for (int i = index; i < m_count - 1; i++) {
        m_pData[i] = m_pData[i + 1];
    }
    m_count--;
}

template <class T>
void vector<T>::push_back(T& value) {
    insert(m_count, value);
}

template <class T>
T& vector<T>::operator[](int index) {
    if (index < 0 || index > m_count) {
        cout << "operator[]:Index out of bounds";
        exit(1);
    }
    return m_pData[index];
}

#endif
