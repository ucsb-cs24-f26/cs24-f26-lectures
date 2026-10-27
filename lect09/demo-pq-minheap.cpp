#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

/*
 * Activity: Emergency Room Triage System
 *
 * You're a software engineer at a hospital. The ER needs a patient
 * management system. Patients arrive at different times but must be
 * treated in order of medical severity — not arrival order.
 *
 * Severity:  1 = Critical (life-threatening)
 *            2 = Urgent   (serious condition)
 *            3 = Moderate (needs attention)
 *            4 = Minor    (can wait)
 */

struct Patient {
    string name;
    int severity;    // 1 = most critical
    int arrivalTime;
};
vector<Patient> waiting_room = {
    {"Alice",  3,  1},   // Moderate,  arrived at t=1
    {"Bob",    1,  2},   // Critical,  arrived at t=2
    {"Carol",  4,  3},   // Minor,     arrived at t=3
    {"Dave",   2,  4},   // Urgent,    arrived at t=4
    {"Eve",    1,  5},   // Critical,  arrived at t=5
    {"Frank",  3,  6},   // Moderate,  arrived at t=6
    {"Grace",  2,  7},   // Urgent,    arrived at t=7
};
template <class T>
class Cmp{
    public:
    // job of this class is simply to compare two things of type T
    // Usage is if Cmp(a, b) is True then a has less priority than b
    // overload the function operator to compare two objects of type T
    bool operator()(const T& a, const T&b) const{
        return a > b;
    } 
};

int main(int argc, char const *argv[])
{
    priority_queue<int, vector<int>, greater<int>> ERTriage; // minimum element has highest priority
    //priority_queue<int, vector<int>, less<int>> ERTriage; // max element has highest priority
    //priority_queue<int, vector<int>, Cmp<int>> ERTriage; // Use custom comparator
                  
    // smallest value has teh highest priority
    ERTriage.push(3);
    ERTriage.push(1);
    ERTriage.push(4);
    ERTriage.push(2);
    ERTriage.push(1);

    while(!ERTriage.empty()){
        cout << "Highest priority value: " << ERTriage.top() << endl;
        ERTriage.pop();
        cout << "Deleted Highest priority value: " << endl;

    }

    return 0;
}