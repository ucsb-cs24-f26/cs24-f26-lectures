//stack-demo.cpp
// Application scenario: Back button Browser --- most recent "thing" availabile first
// More recent weblinks matter more, access those quickly! Last weblink visited first weblink 
// accessed 
// Browser is using a data structure to store all the webslinks (browsing history)
// stack!! operations insert, delete (most recent entry), examine the most entry.

#include <stack>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    stack<int> s; //empty stack
    s.push(70);
    s.push(50);
    s.push(80); // O(1)
    cout << s.top() << endl; //O(1)
    while(!s.empty()){
          cout << s.top() << endl; //O(1)
          s.pop(); //deletes the top element
    }

    return 0;
}
