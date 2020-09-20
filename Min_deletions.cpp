/*
Given a string of S as input. Your task is to write a program to remove or delete minimum number of characters from the string so that the resultant string is palindrome.

Note: The order of characters in the string should be maintained.

Input:
First line of input contains a single integer T which denotes the number of test cases. Then T test cases follows. First line of each test case contains a string S.

Output:
For each test case, print the deletions required to make the string palindrome.

Constraints:
1<=T<=100
1<=length(S)<=10000

Example:
Input:
2
aebcbda
geeksforgeeks
Output:
2
8
*/

//code goes here
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define loop(i,a,n) for(i=a;i<n;i++)
#define fir(i,n) loop(i,0,n)
#define pb push_back()
int minOperations(string S1, string S2) 
	{ 
	    // Your code goes here
	    int m=S1.size(),n=S2.size();
	      int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));
    int i,j;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(S1[i-1]==S2[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    
    int totalop=S1.size()-dp[m][n]; //then we do rearrangement using deletion and insertion 
    
    return totalop;
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
	    string S;
	    cin>>S;
	    string Sr=S;
	    reverse(Sr.begin(),Sr.end());
	    cout<<minOperations(S,Sr)<<'\n';
	}
	
	return 0;
}
