/*
LCS with permutations

Given two strings in lowercase, find the longest string whose permutations are subsequence of given two strings. The output longest string must be sorted.

Examples:

Input  :  str1 = "pink", str2 = "kite"
Output : "ik" 
The string "ik" is the longest sorted string 
whose one permutation "ik" is subsequence of
"pink" and another permutation "ki" is 
subsequence of "kite". 

Input  : str1 = "working", str2 = "women"
Output : "now"

Input  : str1 = "geeks" , str2 = "cake"
Output : "ek"

Input  : str1 = "aaaa" , str2 = "baba"
Output : "aa"

Input:
First line of the input contains no of test cases  T, then T test cases follow. Each test case consist of 2 space separated integers n and m denoting the size of string str1 and str2 respectively. The next two lines contains the 2 string str1 and str2 .


Output:
For each test case print the output string in sorted order.


Constraints:
1 <= T <= 30
1 <= size(str1),size(str2)<= 100


Example:
Input:
2
6 6
abcdef
edgfhr
3 2
abc
ca

Output:
def
ac
*/
//code goes here
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define loop(i,a,n) for(i=a;i<n;i++)
#define fir(i,n) loop(i,0,n)
#define pb push_back()
string lcs(string S1,string S2,int m,int n)
{
    int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));
    int i,j;
    for(i=0;i<=n;i++)
    dp[0][i]=1;
    sort(S1.begin(),S1.end());
     sort(S2.begin(),S2.end());
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
    i=m;j=n;
    string S="";
    while(i>0 && j>0)
    {
        if(S1[i-1]==S2[j-1])
        {
            S+=S1[i-1];
            i--;j--;   
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            i--;
            else
            j--;
        }
        
        
    }
    sort(S.begin(),S.end());
    
return S;
    
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
	    int m,n;
	    cin>>m>>n;
	    string S1,S2;
	    cin>>S1>>S2;
	    
	   cout<<lcs(S1,S2,m,n)<<'\n';
	}
	
	return 0;
}

