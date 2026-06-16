#include <iostream>
using namespace std;
int main() {
    int currentSize = 2;
    int* oldArr = new int[currentSize];

    oldArr[0] =3;
    oldArr[1] =7;

    // Step 1: Allocate a new, larger array
    int newSize = 4;
    int* newArr = new int[newSize]();

    // Step 2: Copy old data over
    for (int i = 0; i < currentSize; ++i) {
        newArr[i] = oldArr[i];
    }

    // Step 3: Delete the old array and reassign the pointer
    delete[] oldArr;
    oldArr = newArr; // oldArr now points to the larger array space
      
    newArr[currentSize] =23;
    newArr[currentSize+1] =77;

    for (int i = 0; i < newSize; ++i) {
        cout<<"Element"<<i+1<<":"<<newArr[i]<<endl;

    }
}