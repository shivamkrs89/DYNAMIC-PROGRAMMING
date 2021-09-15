You are given an integer n. In one operation you can either

    Decrement n by one
    If n is even, decrement by n / 2
    If n is divisible by 3, decrement by 2 * (n / 3)

Return the minimum number of operations required to decrement n to zero.

Constraints

    n ≤ 10 ** 9

Example 1
Input

n = 15

Output

5

Explanation

Since n = 15 is divisible by 3 we decrement by 10 = 2 * (15 / 3) to get 5. Then we decrement by one to get 4. Then we decrement by 2 since n is even. Then we decrement n by one twice to get 0

  //code
  int solveutil(int n,unordered_map<int,int> &dp) {
    
   if (n == 0) return 0;

    if (n == 1) return 1;


    if (dp[n]) return dp[n];

    int md3 = n % 3;
    int md2 = n % 2;

    dp[n] = min(md2 + 1 + solveutil((n - md2) / 2,dp), md3 + 1 + solveutil((n - md3) / 3,dp));
    //eleiminating cases of doing -1 by adding it as 1+md2 and 1+md3 this was the key
    return dp[n];
}

int solve(int n)
{
 unordered_map<int,int> dp;
 return solveutil(n,dp);   
}
