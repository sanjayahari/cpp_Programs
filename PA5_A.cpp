#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(){

    int n;
    cin>> n ;
    cout<< endl;
    char g[n+1] ;

    for(int i=0;i<n;i++){
       cin>>g[i];
    }
    g[n]='\0';
    
    
   vector<vector<string>> dp(n , vector<string>(n,""));
   vector<vector<int>> dp1(n , vector<int>(n,0));

   
//prniting the subgardens 
    for(int i=0; i<n;i++){
      for(int j=i; j<n;j++){
        for(int k=i;k<=j;k++){
           
          //cout<<g[k];
          dp[i][j]+=g[k];
          cout<<dp[i][j][dp[i][j].size()-1];
          

          
        }
        cout<<" ";
        
      }
      cout<<endl;
    }


    for(int i=0; i<n;i++){
      for(int j=i; j<n;j++){
         int m=0,k,l=0;
         string ch=dp[i][j];
         k=ch.size()-1;
       
         //printing the number of replacement ,comparing the subgarden flower 
         while(l<k){
           
           if(ch[l]!=ch[k]){
            
           ch[l]=ch[k];//replacing the different element
           m++;
           
           l++,k--;
           }
           
          
         }
         cout<<m<< " "<<ch<<" ";  //both the replacement and ch printing
         
      }
      cout<<endl;
    }
    return 0;

}