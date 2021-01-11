/*
 * Program #5
 * Overloaded constructors, operators, and helper functions
 * are used to run through twenty test cases with cpp arrays
 * CS-320 Section 1
 * 11/25/2020
 * @author Dalton Tarde cssc2670
 */ 

#include <iostream> 
#include "intArray.h" 

using namespace std; 

/* 
 * OVERLOADED CONSTRUCTORS 
 * Implemented from intArray.h 
 * Constructors are as follows: 
 * Default constructor, 1D and 2D arrays, 
 * two array inputs, and a destructor 
 */ 

IntArray::IntArray() { // Default constructor
    size = 10; // size of array 
    pA = new int[size]; // default: [10]
    lo = 0; // indexing begins at 0 
    hi = 9; 
}

IntArray::IntArray(int arraySize){ // 1D Array constructor
    if (arraySize <= 0) { // I/O Manipulator exit when array DNE
        cout << "Runtime error: illegal index" << endl; 
    }
    size = arraySize; // redeclared from default constructor
    pA = new int[size];
    lo = 0;
    hi = arraySize - 1;  
}

IntArray::IntArray(int lowerIndex, int upperIndex) { // 2D Array Constructor 
    lo = lowerIndex;
    hi = upperIndex; 
    size = (hi-lo) + 1; // avoids out of bound index

    if (size > 0) { // success case
        pA = new int[size]; 
    } 
    else if (lowerIndex > upperIndex) { // exit case
        cout << "Runtime error: illegal index" << endl; 
    }
    else { // dynamic array will be empty 
        pA = NULL; 
    }
}

IntArray::IntArray(const IntArray& secondIntArray) { // Two Array Constructor
    size = secondIntArray.size; 
    pA = new int[secondIntArray.size];
    lo = secondIntArray.lo; 
    hi = secondIntArray.hi; 
    
    for(int i = 0; i < size; i++) { // compare both arrays
        pA[i] = secondIntArray.pA[i]; 
    }
}

IntArray::~IntArray() { // Destructor
    delete[] pA; 
}

/* 
 * OVERLOADED OPERATORS
 * Implemented from intArray.h
 * Operators are as follows (array comparision): 
 * Equality, inequality, index checking, assignment
 * addition, appending, and outputting arrays 
 */ 

int IntArray::operator==(const IntArray& secondIntArray) { // Equality Operator
    if(size == secondIntArray.size) { // checking sizes
        return 0; 
    }
    for(int i = 0; i < size; i++) { // checking elements
        if (pA[i] != secondIntArray.pA[i]) { 
            return 0; 
        }
    }
    return 1; // arrays are equal 
} 

int IntArray::operator!=(const IntArray& secondIntArray) { // Inequality Operator 
    if(size != secondIntArray.size) { // checking sizes
        return 0; 
    }
    for(int i = 0; i < size; i++) { // checking elements
        if (pA[i] == secondIntArray.pA[i]) { 
            return 0; 
        }
    }
    return 1; // arrays are NOT equal     
}

int& IntArray::operator[](int i) { // Index Checking Operator
    int currIndex = i - lo; 
    if(currIndex >= size || currIndex < 0) {
        return pA[0];
    } 
    return pA[currIndex]; 
}

IntArray& IntArray::operator=(const IntArray& secondIntArray) { // Assignment Operator
    if(size == secondIntArray.size) { 
        for(int i = 0; i < size; i++) { // loop over array, make them equal
            pA[i] = secondIntArray.pA[i]; 
        }
    }
    else { 
        cout << "Runtime error: illegal index" << endl; 
    }
    return *this; 
}

IntArray IntArray::operator+(const IntArray& secondIntArray) { // Addition Operator 
    IntArray arraySum(secondIntArray.size); 
    if(size == secondIntArray.size) { 
        for(int i = 0; i < size; i++) { // add indices from arrays
            arraySum[i] = pA[i] + secondIntArray.pA[i]; 
        }
    }
    return arraySum; 
}

IntArray& IntArray::operator+=(const IntArray& secondIntArray) { // Appending Operator 
    if(size == secondIntArray.size) { 
        for(int i = 0; i <= size; i++) { // iterate to avoid out of bounds
            pA[i] += secondIntArray.pA[i]; 
        }
        return *this; 
    }
    return *this; // different return IF size is not the same
}

ostream& operator<<(ostream& os, const IntArray& secondIntArray) { // Output Operator
    for(int i = 0; i < secondIntArray.size; i++) {
        os << secondIntArray.name << "[" << (i + secondIntArray.lo)
        << "] = " << secondIntArray.pA[i] << endl; 
    }
    return os; 
}

/* 
 * HELPER FUNCTIONS 
 * Implemented from intArray.h
 * Helper functions are as follows: 
 * setName, getName (printed not returned), high and low 
 */  

void IntArray::setName(char *name) { // name char is replaced
    this->name = name; 
}

void IntArray::getName() { // print, not return
    cout << name << endl; 
}

int IntArray::high() { // getter for hi
    return hi; 
}

int IntArray::low() { // getter for lo 
    return lo; 
}