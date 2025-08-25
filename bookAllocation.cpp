#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(int arr, int n, int mid, int m){
    int studentCount = 1;
    int currentSum = 0,i;

    for(i=0; i<n; i++){
        if(arr[i] > mid) return false; // If a single book is greater than mid, it's not possible
        if(currentSum + arr[i] > mid){
            studentCount++;
            currentSum = arr[i];
        }
        if(studentCount > m) {
            return false; 
        } else {
            return true;
        }

}
}

int main(){
    int s=0,en,n,m;
    
    cout<<"Enter the number of students: ";
    cin>> m; // n is the number of books, m is the number of students;

    int  arr[4]= {12, 34, 67, 90}; // Example book sizes
    n = sizeof(arr) / sizeof(arr[0]); // Calculate number of books
    int sum=0;
    for(int i=0;i<n;i++){
        cin>> arr[i];
        sum += arr[i];

    }
    en = sum;
    while(s <= en){
        int mid = (s + en) / 2;
        if(isValid(arr[4],n, mid,m)){
            
            en = mid - 1;
        } else {
            s = mid + 1;
        }
    
}
}