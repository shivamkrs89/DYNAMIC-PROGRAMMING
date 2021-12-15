You are given a list of positive integers nums and an integer k. Return whether there exists a combination of integers in nums such that their sum is k and none of those elements are adjacent in the original list.

Constraints

n * k ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [1, 2, 2, 3]
k = 4
Output
true
Explanation
We can pick [1, 3] since they are non-adjacent and sums to 4

Example 2
Input
nums = [1, 3, 1]
k = 4
Output
false
Explanation
We can't pick [1, 3] or [3, 1] since they are adjacent.

//code
bool solve(vector<int>& nums, int k) {
    int n = nums.size(), i, j;
    if (k == 0) return 1;
    if (n == 0) return k == 0;
    bool dp[n + 1][k + 1];
//variation of subset sum
    memset(dp, 0, sizeof(dp));

    for (i = 1; i <= k; i++)
     dp[0][i] = 0; //no element in set

    for (i = 0; i <= n; i++) {  //sum is zero
        dp[i][0] = 1;
    }
//handling case for first element seperately
    for (i = 1; i <= k; i++) {  
        if (nums[0] == i) {
            dp[1][i] = 1;
            
        }
    }
    for (i = 2; i <= n; i++) {
        for (j = 1; j <= k; j++) {
            if (nums[i - 1] > j) { 
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 2][j - nums[i-1]];
                //if we include current element then we look non adjacent element otherwise we can look for adjacent sum as illustrated in above assignment
            }
        
        }
    }

    return dp[n][k];
}
