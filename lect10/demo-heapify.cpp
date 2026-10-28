#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v = {3,1,6,5,2,4,11};
    priority_queue<int> pq; 

    while(!pq.empty()){
        cout << "Highest priority value: " << pq.top() << endl;
        pq.pop();
        cout << "Deleted Highest priority value: " << endl;

    }

    return 0;
}