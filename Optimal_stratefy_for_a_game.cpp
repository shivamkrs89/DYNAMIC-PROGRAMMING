You are given an array A of size N. The array contains integers and is of even length. The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.

In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.

You need to determine the maximum possible amount of money you can win if you go first.
Note: Both the players are playing optimally.

Example 1:

Input:
N = 4
A[] = {5,3,7,10}
Output: 15
Explanation: The user collects maximum
value as 15(10 + 5)

Example 2:

Input:
N = 4
A[] = {8,15,3,7}
Output: 22
Explanation: The user collects maximum
value as 22(7 + 15)
  
  //code goes here
  // { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    
    // int dputil(int *arr,int itf,int itb)
    // {
    //     if(itb-itf==1)
    //     return max(arr[itf],arr[itb]);
      
      
    //   return max(arr[itf]+min(dputil(arr,itf+2,itb),dputil(arr,itf+1,itb-1)),
    //   arr[itb]+min(dputil(arr,itf,itb-2),dputil(arr,itf+1,itb-1)));
    //   //this thing inside min shows us the way player 2 is trying to minimise the score 
    //   //of player 1 by looking into his possibilities and giveing the smaller score
    //   //but player 1 also being optimal maximises the thing whatever he got
      
    //   //for applying dp we see that we require (itf+2,itb), (itf+1,itb-1) and (itf,itb-2)
    //   //which we need in dp table
      
    // }
    long long maximumAmount(int arr[], int n){ //this is bottom up approach which is different than what we do in normal dp table here we don't calculate all values
                                               //but only those which are possible to calculate and necessary
        // Your code here                   //idea of solution is based on recursive solution up shown in comments
        int sum=0;
        int i,j;
        for(i=0;i<n;i++)
        sum+=arr[i];
        int dp[n][n];
        
        for(i=0;i<n-1;i++)       
        {
            j=i+1;
            dp[i][j]=max(arr[i],arr[j]);  //storing the base case of recursion                                       //where j>i 
        }
        
        
        
        int t=3;
        for(t=3;t<n;t+=2)//initialising by t=3 as t=1 is already adressed in previous for loop
        {          //doing such because for the end value that is dp[0][n-1] we see that we require 
                //values to left diaganol which is next to its adjacent ones 
            
            
            for(i=0;i<n;i++)
            {
                j=i+t;
                if(j>=n)
                break;
                
               dp[i][j]=max(arr[i]+min(dp[i+2][j],dp[i+1][j-1]),arr[j]+min(dp[i][j-2],dp[i+1][j-1]));//following the way recursive function is written
               
            }
    
        }
        
    return dp[0][n-1];    
        
        
        
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends
