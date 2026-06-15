#include <iostream>
#include <string>

void checkSystemMemory(int);

// 1. Define the user-defined structure for errors
struct SystemError {
    int errorCode;
    std::string message;
};
SystemError error={503, "Critical Error: System memory limit exceeded!"};

// 2. A process that validates requirements and throws the struct
void checkSystemMemory(int usagePercentage) {
    // System Requirement: Memory usage must be under 95%
    if (usagePercentage >= 95) {
        // Construct and throw the user-defined struct instantly
        throw error;
    }
    std::cout << "Memory status healthy: " << usagePercentage << "%\n";
}

int main() {
    try {
        checkSystemMemory(98); // This will fail the requirement
    }
    // 3. Catch the exception variable as a reference to your custom struct
    catch (const SystemError& err) {
        std::cerr << "[Handler] Code: " << err.errorCode << "\n";
        std::cerr << "[Handler] Msg:  " << err.message << "\n";
    }
    return 0;
}