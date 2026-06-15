#include <iostream>
using namespace std;

int main() { 
    int i=10;
    char a='b';
    try {
        
        //throw a; // Throwing an exception
        throw i; // Throwing an exception
    }
    catch (int e) {
        cout << "Integer exception caught: " << e << endl;
    }
    catch (char e) {
        cout << "Character exception caught: " << e << endl;
    }
    catch (...) {//catch all
        cout << "Default exception handler" << endl;
    }
    
    return 0;
}
