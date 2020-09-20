/*
Given two strings str1 and str2, find the length of the smallest string which has both, str1 and str2 as its sub-sequences.
Note: str1 and str2 can have both uppercase and lowercase letters.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains two space-separated strings.

Output:
For each testcase, in a new line, output the length of the required string.

Expected Time Complexity: O(Length(str1) * Length(str2)).
Expected Auxiliary Space: O(Length(str1) * Length(str2)).

Constraints:
1 <= T <= 100
1<= |str1|, |str2| <= 100

Example:
Input:
2
abcd xycd
efgh jghi
Output:
6
6
Explanation:
Test Case 1: One of the shortest answer can be abxycd, which is of length 6.
*/

//code goes here
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define loop(i,a,n) for(i=a;i<n;i++)
#define fir(i,n) loop(i,0,n)
#define pb push_back()

//Code 2 Conquer
int lcs(string &s1,string &s2)
{
    int m=s1.size();
    int n=s2.size();
    
    int i,j;
    int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));

    
    loop(i,1,m+1)
    {
        loop(j,1,n+1)
        {
            if(s1[i-1]==s2[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

        }
  
    }
    
    return dp[m][n];
}

int main() {
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
	    string s1,s2;
	    cin>>s1>>s2;
	    
	    int lcslen=lcs(s1,s2);
	    
	    cout<<s1.size()+s2.size()-(lcslen)<<'\n';
	}
	
	return 0;
}
