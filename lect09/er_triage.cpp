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
    // // overload the < operator for type Patient
    // // Remember a < b means a has lower priority than b
    // bool operator<(const Patient& rhs) const{
    //     if(severity!= rhs.severity)  {
    //         return severity > rhs.severity;
    //     }
    //     return arrivalTime > rhs.arrivalTime; // later arrival time has lower priority
    // }
};
template <class T>
class Cmp{
    public:
    // job of this class is simply to compare two things of type T
    // Usage is if Cmp(a, b) is True then a has less priority than b
    // overload the function operator to compare two objects of type T
    bool operator()(const T& a, const T&b) const{
        // overload the < operator for type Patient
        // Remember a < b means a has lower priority than b
        if(a.severity!= b.severity)  {
            return a.severity > b.severity;
        }
        return a.arrivalTime > b.arrivalTime; // later arrival time has lower priority
    } 
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

int main(int argc, char const *argv[])
{
    priority_queue<Patient, vector<Patient>, Cmp<Patient>> ERTriage;  //  If a < b, then a has lower priority than b
    for(auto p: waiting_room){
        ERTriage.push(p); // O(logn)
    }
    
    while(!ERTriage.empty()){
        cout << "Most critical patient: " << ERTriage.top().name << endl; // O(1)
        ERTriage.pop(); // O(log  n)
        cout << "Most critical patient served: " << endl;
    }

    return 0;
}

