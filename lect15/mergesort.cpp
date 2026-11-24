//mergesort.cpp
#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

void merge(vector<int>& result, vector<int>& left, vector<int> & right){
    // Complexity analysis:  Assume left.size() is l , right.size() is m 
    // Every iteration of the while loop, one element is placed into the result vector
    // until all the elements of teh left and right vectors are placed. So in total l + m placements
    // So l + m iterations and every iteration takes constant time.
    // O(l + m)
    int i = 0; // index of the leading element of left
    int j = 0; // index of the leading element of right
    int k = 0; // index of the leading element of result

    while ( i < left.size() && j < right.size()) {
        // left and right leading elements compete
        if (left[i] < right[j]){
            // winner is left leading element
            result[k] = left[i];
            i++;
            k++;
        } else{
            result[k] = right[j];
            j++;
            k++;

        }
    }
    while (i < left.size()){
        result[k] = left[i];
        i++;
        k++;
    }
    while (j < right.size()){
        result[k] = right[j];
        j++;
        k++;

    }
}

void mergeSort(vector<int>& v){ // input of size n
    if (v.size() <= 1) return; // base case

    int mid = v.size() / 2 ;
    vector<int> left(v.begin(), v.begin() + mid);  // copy n/2 elements
    vector<int> right(v.begin() + mid, v.end()); // copy n/2  elements
    mergeSort(left); 
    mergeSort(right);
    merge(v, left, right); // what is the running time if left.size() is l , m elements in riht half

}


int main(int argc, char const *argv[])
{
  
    vector<int> v1 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> v2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v3 = {1, 9, 2, 8, 3, 7, 4, 6, 5};
    vector<int> v4 = {5, 4, 6, 3, 7, 2, 8, 1, 9};
    vector<int> w  = {5, 4, 6, 3, 7, 2, 8, 1};
    vector<int> x;
    vector<int> exp_v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> exp_w = {1, 2, 3, 4, 5, 6, 7, 8};
  
    mergeSort(v1);
    mergeSort(v2);
    mergeSort(v3);
    mergeSort(v4);
    mergeSort(w);
    mergeSort(x);
    cout << "Run mergesort tests" << endl;
    assert(v1 == vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
    cout << "Passed odd list 1 " << endl;
    assert(v2 == vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
    cout << "Passed sorted list " << endl;
    assert(v3 == vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
    cout << "Passed odd list 2  " << endl;
    assert(v4 == vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
    cout << "Passed odd list 3 " << endl;
    assert(w == vector<int>({1, 2, 3, 4, 5, 6, 7, 8}));
    cout << "Passed even list  " << endl;
    assert(x == vector<int>{});
    cout << "Passed empty list " << endl;

    return 0;
}
