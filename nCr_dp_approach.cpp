/*
Finding nCr without multiplication 
we use nCr=n-1Cr + n-1Cr-1;
Find nCr for given n and r.

Example 1:

Input:
n = 3, r = 2
Output: 3

Example 2:

Input:
n = 4, r = 2
Output: 6

Your Task:
Complete the function nCrModp​() which takes two integers n and r as input parameters and returns the nCr mod 109+7.
Note: nCr does not exist when r > n. Hence, return 0 in that case.

Expected Time Complexity : O(N*R)
Expected Auxiliary Space: O(N)

Constraints:
1<= n <= 103
1<= r <= 103
*/

//code solution
// { Driver Code Starts
// A Dynamic Programming based solution to compute nCr % p 
#include<bits/stdc++.h> 
using namespace std; 

const int p = 1e9+7;

int nCrModp(int, int);

// Driver program 
int main() 
{ 
  int t, n, r;
  
  //taking count of testcases
  cin >> t;
  
  while(t--){
      
      //taking n and r
      cin >> n >> r;
      
      //calling method nCrModp()
      cout << nCrModp(n, r) << endl;
  }
  
  return 0; 
}
// } Driver Code Ends


// Returns nCr % p 
 int nCrModp(int n, int r) 
{ 
    if(r>n)
    return 0;
    int i,j;
  long long int p=1000000007;
  long long int dp[2][n+1];
  
  for(i=0;i<=n;i++)
  {
      for(j=0;j<=r;j++)
      {
           if(i<j)
          dp[i%2][j]=0;
          else if(i==0 || j==0)
          {dp[i%2][j]=1;}
         
          else
          {
           dp[i%2][j]=(dp[(i+1)%2][j]+dp[(i+1)%2][j-1])%p;          
          }
    
      }
      
    
  }
  
  return dp[n%2][r]%p;
  
} 
