#include<iostream>
#include <string>
#include <sstream>

// Custom template mimicking C++11 std::to_string
template <typename T>
std::string to_string(const T& value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

class GameServer
{
    const int serverID;
    int maxPlayers;
    std::string& systemLog;
public:
    // Default Constructor
    GameServer() = default;

    //Parameterized Constructor using a Member Initializer List
    GameServer(int id,int maxp,std::string& logRef) : serverID(id),maxPlayers(maxp),systemLog(logRef) {   }

     // A method to log events and print status
    void bootUp() {
        // Replicating std::to_string using an output string stream
        std::ostringstream oss;
        oss << "Server " << serverID << " is online.\n";
        
        // Appending the stream result to our referenced system log
        systemLog += oss.str();
        std::cout << "Server ID: " << serverID << " running with capacity: " << maxPlayers << "\n";
    }
};


int main() {
    std::string globalLog = "--- SYSTEM START ---\n";

    // Creating a server object
    // Passes ID: 101, Capacity: 50 players, and binds it to the globalLog string
    GameServer serverOne(101, 50, globalLog);
    
    serverOne.bootUp();

    // Verify the external log was updated successfully
    std::cout << "\nGlobal System Log Output:\n" << globalLog;

    return 0;
}