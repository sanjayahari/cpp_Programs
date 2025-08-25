#include <iostream>
#include <vector>
using namespace std;

// Function to perform binary search
int main(){
    int n, target;
    cout<< "Enter the number of elements in the array: ";
    cin >> n;
    vector<int>arr(n); // Initialize a vector of size n with all elements as 0

    cout<< "Enter the elements of the array in sorted order: ";
    // Input elements into the vector
    for(int i = 0; i < n; i++){
        cin >> arr[i];

    }
    // Ensure the array is sorted
    cout<< "The array is: ";
    for(int i=0; i<n; i++){
        cout<< arr[i] << " ";
    }

    cout<< " Enter the target element to  search: ";
    cin >> target;

    int s=0, e=n-1;
    int mid;
    while(s <= e){
        mid = s + (e - s) / 2; // To avoid overflow
        if(arr[mid]==target){
            cout<< "Element found at index: " << mid << endl;
            return 0; // Element found, exit the program
        }
        else if(arr[mid] < target){
            s = mid + 1; // Search in the right half
        }
        else{
            e = mid - 1; // Search in the left half
        } 

    }
    return cout << "Element not found in the array." << endl, 0; // Element not found
    
}