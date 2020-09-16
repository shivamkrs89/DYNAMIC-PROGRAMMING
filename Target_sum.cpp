/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:

Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.

 

Constraints:

    The length of the given array is positive and will not exceed 20.
    The sum of elements in the given array will not exceed 1000.
    Your output answer is guaranteed to be fitted in a 32-bit integer.

*/

//code goes here
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int s=0,i,j;
        int n=nums.size();
        S=abs(S);             //as it gives same result by observation
        for(i=0;i<n;i++)
            s+=nums[i];
        if(S>s)            //if reqd sum is greater than total sum
            return 0;
        if((s+S)%2==1)
            return 0;
       int subsum=(s+S)/2;   //subset sum which we need to find out
       s=subsum; 
        int dp[n+1][s+1];
        
        memset(dp,0,sizeof(dp));
        
        for(i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=s;j++)
            {
                if(nums[i-1]<=j && nums[i-1]!=0){
                    dp[i][j]=dp[i-1][j] + dp[i-1][j-nums[i-1]];
               
            }
                else
                    dp[i][j]=dp[i-1][j];
                
             
            }
        
           
        }
   int zeros=1; 
        for(i=0;i<nums.size();i++) //cases for considering zeros as +0 or -0 are additional ways
            if(nums[i]==0)
            {
               zeros*=2; 
            }
        return dp[n][subsum]*zeros;
    }
};
