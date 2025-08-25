#include <iostream>
#include <vector>
using namespace std;

int main(){
    int arr[6]= {5, -6, 3, 4, -1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> ans;
    ;
    int maxSum=INT16_MIN;
    int currSum=0;
    for(int i=0; i<n; i++){
        currSum +=arr[i];
        ans.push_back(arr[i]);
        maxSum = max(maxSum, currSum);
        if(currSum < 0){
            currSum = 0;
            ans.clear(); // Clear the current subarray if the sum is negative
        }

    }
    cout << "Maximum subarray sum is: " << maxSum << endl;
    cout << "Subarray with maximum sum: ";
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    

}
