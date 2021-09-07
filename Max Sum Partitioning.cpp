You are given a list of integers nums and an integer k. You must partition nums into contiguous groups of size at most k each, and then set each element in nums to the maximum value of its group.

Return the maximum possible sum of the resulting list after partitioning.

Constraints

    n ≤ 1,000 where n is the length of nums
    1 ≤ k ≤ n

Example 1
Input

nums = [1, 6, 3, 2, 2, 5, 1]

k = 3

Output

35

Explanation

We can partition the list into [1, 6, 3] + [2] + [2, 5, 1] to get [6, 6, 6, 2, 5, 5, 5].
  
  //code
  int solve(vector<int>& nums, int k) {
    int n=nums.size();
 int i,j;
 int dp[n+1];
 memset(dp,0,sizeof(dp));

      for(i=1;i<=n;i++)
    {
        int mx=0;
        for(j=i;j<i+k && j<=n ;j++)
        {
           mx=max(mx,nums[j-1]);
           dp[j]=max(dp[j],dp[i-1]+(j-i+1)*mx);//checking for current possibility and adding previous into it like if current end at j then we see for ith(start)+curr is lesser more than dp[j] 
          
        }
        
    }

    return dp[n];
}
