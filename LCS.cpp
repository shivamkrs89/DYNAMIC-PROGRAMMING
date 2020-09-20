/*
Longest Common Subsequence

Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Example 1:

Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input Sequences
“ABCDGH” and “AEDFHR” is “ADH” of
length 3.

Example 1:

Input:
A = 3, B = 2
str1 = ABC
str2 = AC
Output: 2
Explanation: LCS of "ABC" and "AC" is
"AC" of length 2.

Your Task:
Complete the function lcs() which takes the length of two strings respectively and two strings as input parameters and returns the length of the longest subsequence present in both of them.

Expected Time Complexity : O(|str1|*|str2|)
Expected Auxiliary Space: O(|str1|*|str2|)

Constraints:
1<=size(str1),size(str2)<=100
*/
//code goes here
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t,n,k,x,y;
    
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        
        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends


// function to find longest common subsequence
int lcsmat[1001][1001];
int clcs(int x, int y, string s1, string s2){
  
    // your code here
    if(x==0 || y==0)
    return 0;
    
    if(s1[x-1]==s2[y-1]){
        
        if(lcsmat[x-1][y-1]==-1)
    lcsmat[x-1][y-1]=clcs(x-1,y-1,s1,s2); 
    return 1+lcsmat[x-1][y-1];
    }
    else{
 
        if(lcsmat[x][y-1]==-1)
        lcsmat[x][y-1]=clcs(x,y-1,s1,s2);
        if(lcsmat[x-1][y]==-1)
        lcsmat[x-1][y]=clcs(x-1,y,s1,s2);
 
    return max(lcsmat[x][y-1],lcsmat[x-1][y]);
    }
    
}

int lcs(int x, int y, string s1, string s2){
    
    // your code here
    int i,j;
    for(i=0;i<=x;i++)
    {
        for(j=0;j<=y;j++)
        lcsmat[i][j]=-1;
    }
    
    return clcs(x,y,s1,s2);
}
