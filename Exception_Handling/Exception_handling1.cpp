#include <iostream>
using namespace std;

int main() { 
    int a=10;
    int b=0;
    try {
        if (b==0)
            throw "Division by zero!";
        int c=a/b;
        cout<<"Result:"<<c<<endl; 

    }
    catch (const char* e) {
        cout << "Exception caught: " << e << endl;
    }
    catch (...) {//catch all
        cout << "Default exception handler" << endl;
    }
    
    return 0;
}