#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[6]= {1 ,1 ,2 ,2 ,1 ,1 };
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> ans;
    int maxCount = 1;
    for(int i = 1; i < n; i++) {
        if(arr[i] == arr[i-1]) {
            ans.push_back(arr[i]);
            maxCount++;
        } else if(arr[i] != arr[i-1] ){
            maxCount--;
        }
        if(maxCount == 0) {
            ans.clear();
            ans.push_back(arr[i]);
            maxCount = 1;
        }
    }
    if(maxCount > 0) {
        cout << "Majority element is: " << ans[0] << endl;
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] == ans[0]) {
                count++;
            }
        }
        cout << "Count is: " << count << endl;
        
        
    } else {
        cout << "No majority element found" << endl;
    }
}
