Given two strings a and b of digits, find a way to delete digits in the strings so that:

    The two strings are equal
    The sum of the digits deleted is minimized

And return this minimized sum.

Constraints

    n ≤ 500 where n is the length of a
    m ≤ 500 where m is the length of b

Example 1
Input

a = "01291"

b = "191"

Output

2

Explanation

We can delete "0" and "2" from the first string to reach "191".
Example 2
Input

a = "111"

b = "222"

Output

9

Explanation

We have to delete all characters from both strings so they become equal.

      //code
      int solve(string S1, string S2) {
    int m=S1.size(),n=S2.size();
    int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));
    int i,j;
   
//here we follow variation of LCS where we find the cost of LCS in line X
        for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(S1[i-1]==S2[j-1])            //line X
            dp[i][j]=dp[i-1][j-1]+2*(S1[i-1]-'0');
            
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    int lcscost=dp[m][n];
    int sum1=0,sum2=0;
    for(i=0;i<m;i++)//calculate cost if we remove all lettersfrom s1 and s2
    {
sum1+=(S1[i]-'0');
    }
    for(j=0;j<n;j++)
    {
sum2+=(S2[j]-'0');
    }


//now minimum cost would be sum1+sum2-lcscost as lcs cost is considered maximum and in this way only digits which are deleted their cost will be remaining cost which is minimum

    return sum1+sum2-lcscost;
}
