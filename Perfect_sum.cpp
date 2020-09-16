/*
Given an array arr[] of integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

Note: Answer can be very large, so, output answer modulo 109+7

Example 1:

Input: N = 6, arr[] = {2, 3, 5, 6, 8, 10}
       sum = 10
Output: 3
Explanation: {2, 3, 5}, {2, 8}, {10}

Example 2:

Input: N = 5, arr[] = {1, 2, 3, 4, 5}
       sum = 10
Output: 3
Explanation: {1, 2, 3, 4}, {1, 4, 5}, 
             {2, 3, 5}


Your Task:  
You don't need to read input or print anything. Complete the function perfectSum() which takes N, array arr[] and sum as input parameters and returns an integer value

Expected Time Complexity: O(N*sum)
Expected Auxiliary Space: O(N*sum)

Constraints:
1 ≤ N*sum ≤ 106 */
//code goes here
class Solution{

	public:
	 int perfectSum(int a[], int n, int s)
	{
        // Your code goes here
        int i,j;
     int dp[n+1][s+1];


     for(i=0;i<=s;i++)
    dp[0][i]=0;
        for(i=0;i<=n;i++)
    dp[i][0]=1;
   
   long long int md=1000000007;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=s;j++)
        {
            if(a[i-1]<=j)
            {
                dp[i][j]= (dp[i-1][j] + dp[i-1][j-a[i-1]])%md;
            }
            else 
            dp[i][j]=dp[i-1][j]%md;
        }
    }
  
    return dp[n][s]%(md);
	}
	  
};
