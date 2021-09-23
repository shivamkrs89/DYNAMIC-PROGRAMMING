Given integers n, faces, and total, return the number of ways it is possible to throw n dice with faces faces each to get total.

Mod the result by 10 ** 9 + 7.

Constraints

    1 ≤ n, faces, total ≤ 100

Example 1
Input

n = 2

faces = 6

total = 7

Output

6

Explanation

There are 6 ways to make 7 with 2 6-sided dice:

    1 and 6
    6 and 1
    2 and 5
    5 and 2
    3 and 4
    4 and 3

//code
      //better expalination refer to https://www.geeksforgeeks.org/dice-throw-dp-30/
      int solve(int n, int faces, int total) {
    
int md=1e9+7;
long long count=0;

long long int dp[n+1][total+1];
memset(dp,0,sizeof(dp));
int i,j;

for(i=1;i<=total;i++)
{
    if(i<=faces)
    dp[1][i]=1;
}
for(i=2;i<=n;i++)
{
    for(j=1;j<=total;j++)
    {
        dp[i][j]=(dp[i-1][j-1]+dp[i][j-1])%md;//fiing a face j-1 to 1 and getting possiblities.
      if(j>=faces+1)
       dp[i][j]-=dp[i-1][j-faces-1];
  
    }
    
}

return dp[n][total]%md;
