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
    str1 and str2 consist of lowercase English letters.

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
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            i--;
            else
            j--;
        }
        
        
    }
        reverse(S.begin(),S.end());//this is lcs
        //traversing one by one to insert uncommon in between
        string sr="";
        int i1=1,i2=1;
        if(S[0]!=S1[0])
        {
            i=0;
            while(S[0]!=S1[i])
            {
                sr+=S1[i];
                i++;
            }
            i1=i+1;
        }
         if(S[0]!=S2[0])
        {
            i=0;
            while(S[0]!=S2[i])
            {
                sr+=S2[i];
                i++;
            }
             i2=i+1;
        }
        sr+=S[0];
        i=1;
        
        while(i<S.size())
        {
            
            for(int it=i1;it<S1.size();it++)
            {
                if(S[i]!=S1[it])
                {
                    sr+=S1[it];
                }
                else{
                    i1=it;
                    break;
                }
            }
            for(int it=i2;it<S2.size();it++)
            {
              if(S[i]!=S2[it])
                {
                    sr+=S2[it];
                } 
                else
                {
                     i2=it;
                    break;
                }
            }
            
            sr+=S[i];
            i1++;i2++;i++;
            
        }
        
        while(i1<S1.size())
            sr+=S1[i1++]; 
        
        while(i2<S2.size())  
            sr+=S2[i2++];
            
            
        
        return sr;
    }
};
