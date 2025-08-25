#include <iostream>
using namespace std;

int main(){
    int arr[6] = {7,1, 5, 3, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxProfit=0;
    int bestBuy=arr[0];

    // optimized approach to find maximum profit
    for(int st = 0; st < n; st++){
        for(int en = st; en < n; en++){
            maxProfit=max(maxProfit , arr[en] - bestBuy);
            if(arr[en] < bestBuy){
                bestBuy = arr[en];
            }
        }
    }
    cout << "Maximum profit is: " << maxProfit<< endl;
    
    return 0;
}