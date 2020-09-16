/*
Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference

Example 1:

Input: N = 4, arr[] = {1, 6, 11, 5} 
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11   

Example 2:

Input: N = 2, arr[] = {1, 4}
Output: 3
Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {4}, sum of Subset2 = 4


Your Task:  
You don't need to read input or print anything. Complete the function minDifference() which takes N and array arr as input parameters and returns the integer value

Expected Time Complexity: O(N*|sum of array elements|)
Expected Auxiliary Space: O(N*|sum of array elements|)

Constraints:
1 ≤ N*|sum of array elements| ≤ 106
*/

//code solution
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{

	public:
	int minDiffernce(int a[], int n) 
	{ 
	    // Your code goes here
	    int i,j,s=0;
	    for(i=0;i<n;i++)
	    s+=a[i];
	     bool dp[n+1][s+1];
    memset(dp,0,sizeof(dp));
    
    for(i=0;i<=n;i++)
    dp[i][0]=1;
    
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=s;j++)
        {
            if(a[i-1]<=j)
            {
                dp[i][j]= dp[i-1][j] || dp[i-1][j-a[i-1]];
            }
            else 
            dp[i][j]=dp[i-1][j];
        }
    }
    int mini=s;
        
        for(j=0;j<=s;j++)
        {
       if(dp[n][j]==1 && s-2*j>=0)
       {
           mini=min(s-2*j,mini);
       }
        }
    }
    return mini;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDiffernce(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
