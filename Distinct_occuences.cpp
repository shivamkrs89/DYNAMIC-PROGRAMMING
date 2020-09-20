/*Distinct occurrences

Given two strings S and T of length n and m respectively. find count of distinct occurrences of T in S as a sub-sequence. 
 

Example 1:

Input:
S = "banana" , T = "ban"
Output: 3
Explanation: There are 3 sub-sequences:
[ban], [ba n], [b an].


​Example 2:

Input:
S = "geeksforgeeks" , T = "ge"
Output: 6
Explanation: There are 6 sub-sequences:
[ge], [ ge], [g e], [g e] [g e] and [ g e].

 

Your Task:
You don't need to read input or print anything.Your task is to complete the function subsequenceCount() which takes two strings as argument S and T and returns the count of the sub-sequences modulo 109 + 7.


Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).

Constraints:
1<=length of(T)<=100
1<=length of(S)<=8000
*/
//code goes here
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 
int subsequenceCount(string S, string T);

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		cout<<subsequenceCount(s,tt)<<endl;
		
		
	}
  
}// } Driver Code Ends


/*You are required to complete this method*/

static int dp[101][8001];
int md=1000000007;
int distinct(string &S,string &T,int x,int y)
{
    if((x==0 && y==0) || y==0)
    return 1;
    if(x<=0)
    return 0;
    
    if(S[x-1]==T[y-1])
{
 
    if(dp[y-1][x-1]==-1)
        dp[y-1][x-1]=(distinct(S,T,x-1,y-1))%md;
    
    if(dp[y][x-1]==-1)
    dp[y][x-1]=(distinct(S,T,x-1,y))%md;
    
    return (dp[y-1][x-1] + dp[y][x-1])%md;
}
else
{
    if(dp[y][x-1]==-1)
    dp[y][x-1]=(distinct(S,T,x-1,y))%md;
    
    return dp[y][x-1];
}
}

int subsequenceCount(string S, string T)
{
  //Your code here
  memset(dp,-1,sizeof(dp));
  return distinct(S,T,S.size(),T.size())%md;
}
 
