/*


Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is S.

Output:

Print the minimum number of characters.

Constraints:

1 ≤ T ≤ 50
1 ≤ S ≤ 40

Example:

Input:
3
abcd
aba
geeks

Output:
3
0
3
*/

//code goes here
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define loop(i,a,n) for(i=a;i<n;i++)
#define fir(i,n) loop(i,0,n)
#define pb push_back()
int form(string S1,string S2)
{
    int n=S1.size();
    
    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    int i,j;
 
        for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(S1[i-1]==S2[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            
           
        }
      
    }
    
    return n-dp[n][n];
}
//Code 2 Conquer
int main() {
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
	    
	    string s;
	    cin>>s;
	    string s1=s;
	    reverse(s1.begin(),s1.end());
	    
	    cout<<form(s,s1)<<'\n';
	}
	
	return 0;
}
