#include <cstring>
#include <iostream>

template <class T>
class Vector
{
public:
    Vector();                   // creates an empty vector
    Vector(int size);           // creates a vector for holding 'size' elements
    Vector(const Vector &r);    // the copy ctor
    ~Vector();                  // destructs the vector
    T &operator[](int index);   // accesses the specified element without bounds checking
    T &at(int index);           // accesses the specified element, throws an exception of
                                // type 'std::out_of_range' when index <0 or >=m_nSize
    int size() const;           // return the size of the container
    void push_back(const T &x); // adds an element to the end
    void clear();               // clears the contents
    bool empty() const;         // checks whether the container is empty
private:
    void inflate();  // expand the storage of the container to a new capacity,
                     // e.g. 2*m_nCapacity
    T *m_pElements;  // pointer to the dynamically allocated storage
    int m_nSize;     // the number of elements in the container
    int m_nCapacity; // the total number of elements that can be held in the
                     // allocated storage
};

template <class T>
Vector<T>::Vector() : m_pElements(nullptr), m_nSize(0), m_nCapacity(0) {}

template <class T>
Vector<T>::Vector(int size) : m_nSize(0), m_nCapacity(size)
{
    m_pElements = new T[size];
}

template <class T>
Vector<T>::Vector(const Vector &r) : m_pElements(new T[r.m_nCapacity]), m_nCapacity(r.m_nCapacity), m_nSize(r.m_nSize)
{
    memcpy(m_pElements, r.m_pElements, sizeof(T) * r.m_nSize);
}

template <class T>
Vector<T>::~Vector()
{
    delete[] m_pElements;
}

template <class T>
T &Vector<T>::operator[](int index)
{

    return m_pElements[index];
}

template <class T>
T &Vector<T>::at(int index)
{
    if (index < 0 || index >= m_nSize)
        throw std::out_of_range("Index out of range");

    return m_pElements[index];
}

template <class T>
int Vector<T>::size() const
{
    return m_nSize;
}

template <class T>
void Vector<T>::push_back(const T &x)
{
    if (m_nSize == m_nCapacity)
        inflate();
    m_pElements[m_nSize] = x;
    m_nSize++;
}

template <class T>
void Vector<T>::clear()
{
    m_nSize = 0;
}

template <class T>
bool Vector<T>::empty() const
{
    return m_nSize == 0;
}

template <class T>
void Vector<T>::inflate()
{
    m_nCapacity = (m_nCapacity == 0) ? 1 : m_nCapacity * 2;
    T *temp = new T[m_nCapacity];
    memcpy(temp, m_pElements, sizeof(T) * m_nSize);
    m_nCapacity *= 2;
    delete[] m_pElements;
    m_pElements = temp;
}

int main()
{
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << "Insert result: vec: \n";
    for (int i = 0; i < 3; i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Size: " << vec.size() << std::endl;   // Output: Size: 3
    std::cout << "Empty: " << vec.empty() << std::endl; // Output: Empty: 0

    Vector<int> vec2(vec);
    std::cout << "Size of copied vector: " << vec2.size() << std::endl; // Output: Size of copied vector: 3

    vec.clear();
    std::cout << "Size after clear: " << vec.size() << std::endl;   // Output: Size after clear: 0
    std::cout << "Empty after clear: " << vec.empty() << std::endl; // Output: Empty after clear: 1

    try
    {
        std::cout << "Accessing element at index 3: " << vec2.at(3) << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl; // Output: Exception caught: Index out of range
    }

    return 0;
}