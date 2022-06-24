#include <iostream>

class MyInt
{
    int *_p; // pointer to heap data
public:
    MyInt(int *p = NULL) { _p = p; }
    // When the destructor of a MyInt object is called, the resource is deleted from memory
    ~MyInt()
    {
        std::cout << "resource " << *_p << " deallocated" << std::endl;
        delete _p;
    }
    // the * operator is overloaded which enables us to dereference MyInt objects in the same manner as with raw pointers
    int &operator*() { return *_p; } // // overload dereferencing operator
};

int main()
{
    double den[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    for (size_t i = 0; i < 5; ++i)
    {
        // allocate the resource on the stack
        // The part new int(i) creates a new block of memory on the heap and initializes it with the value of i. The returned result is the address of the block of memory.
        // The part MyInt en(…)calls the constructor of class MyInt, passing the address of a valid memory block as a parameter.
        MyInt en(new int(i));

        // use the resource
        std::cout << *en << "/" << den[i] << " = " << *en / den[i] << std::endl;
    }

    return 0;
}