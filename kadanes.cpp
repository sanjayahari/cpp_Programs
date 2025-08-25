#include <iostream>
using namespace std;

int main(){
    int arr[4] = {1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int st=0; st<n; st++){
        for(int en=0; en<n; en++){
            int sum = 0;
            for(int i=st; i<en+1; i++){
                cout<<arr[i] ;
            }
            cout<<" " ;
           
    } 
    cout<<endl ;
        }
        return 0;
    }

