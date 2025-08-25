#include <iostream>
using namespace std;

int main(){
    int m;
    int arr[10]={9,8,9,9,9,9,9,9,9,9};
    for(int i=1; i< 10; i++){
        m=arr[i];
        int t=9;
        for(int j=i; j< 10; j++){
            if(arr[j] >= (t-i  && arr[j]<=arr[i]) ){
                m = min(arr[j], m);
                
            }
           

        }
        
        

    }
    for(int i=0; i < 10; i++){
        cout<< arr[i] ;

    }

    

}