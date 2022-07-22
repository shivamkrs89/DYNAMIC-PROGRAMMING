Given two strings a and b, find the minimum edit distance between the two. One edit distance is defined as

    Deleting a character or
    Inserting a character or
    Replacing a character

Constraints

    n ≤ 1,000 where n is the length of a
    m ≤ 1,000 where m is the length of b

Example 1
Input

a = "zhello"

b = "helli"

Output

2

Explanation

"z" is removed and the "o" is replaced with "i"
Example 2
Input

a = "dycare"

b = "daycare"

Output

1

Explanation

"a" is inserted into the first string to get "daycare".

  
  int solve(string a, string b) {
    int m=a.size(),n=b.size();
    
    int dp[m+1][n+1];
    int i,j;
    for(i=0;i<=m;i++)
    {
        dp[i][0]=i;
    }

    for(j=0;j<=n;j++)
    {
        dp[0][j]=j;
    }

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=dp[i-1][j-1]; //if cahr are same we don' tdo anything just dp[i][j] is same as dp[i-1][j-1]
            }
            else
            {
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])); //if its differenct we increment by 1 + minvalue possiblity with replace insert and delete respectively
            }
        }
    }

    return dp[m][n];
}
