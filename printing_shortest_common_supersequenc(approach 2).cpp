/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.  If multiple answers exist, you may return any of them.

(A string S is a subsequence of string T if deleting some number of characters from T (possibly 0, and the characters are chosen anywhere from T) results in the string S.)

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.

 

Note:

    1 <= str1.length, str2.length <= 1000
    str1 and str2 consist of lowercase English letters
    */
    
    class Solution {
public:
    string shortestCommonSupersequence(string S1, string S2) {
        int m=S1.size();
        int n=S2.size();
        int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));
    int i,j;
   
   
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
           
            if(S1[i-1]==S2[j-1]){
            dp[i][j]=1+dp[i-1][j-1];
               
            }
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
        else          //same as printing lcs but here if we don't get same alpha we print it then               {              //traverse in table do some observation
        
            if(dp[i-1][j]>dp[i][j-1])
            {S+=S1[i-1];i--;}
            else{         
            S+=S2[j-1];j--;}
        }
        
        
    }
        
    
        
        while(i>0)
            S+=S1[--i]; 
        
        while(j>0)  
            S+=S2[--j];
            
            reverse(S.begin(),S.end());
        
        return S;
    }
};
