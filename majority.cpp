#include <iostream>
#include <vector>
using namespace std;

int main() {
    //if the array is sorted 
    int arr[8] = {2,2,2,2,3,3,3,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count = 1;
    vector<int> ans;
    ans.push_back(arr[0]);
    for(int i = 1; i < n; i++) {
        if(ans[0] == arr[i]) {
            count++;
        }
        else {
            if(count > n/2){
                cout<< "Majority element is: " << ans[0] << endl;
                cout<< "Count is: " << count << endl;
                return 0;
            }else {
                ans.clear();
                ans.push_back(arr[i]);
                count = 1;
                    }
            }
    }
    cout << "No majority element found" << endl;
    return -1; // No majority element found




}
    