/*


Given two strings 'str' and a wildcard pattern 'pattern' of length N and M respectively,  You have to print '1' if the wildcard pattern is matched with str else print '0' .

The wildcard pattern can include the characters ‘?’ and ‘*’
‘?’ – matches any single character
‘*’ – Matches any sequence of characters (including the empty sequence)

Note: The matching should cover the entire str (not partial str).

 

Example 1:

Input:
pattern = "ba*a?"
str = "baaabab"
Output: 1
Explanation: replace '*' with "aab" and '?' with 'b'. 


â€‹Example 2:

Input:
pattern = "a*ab"
str = "baaabab"
Output: 0
Explanation: Because of'a' at first position,
pattern and str can't be matched. 


Your Task:
You don't need to read input or print anything. Your task is to complete the function wildCard() which takes the two strings 'pattern' and 'str' as input parameters and returns the answer.

 

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(N*M)

Constraints:
1 <= length of(str,pat) <= 200
*/

//code starts here
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int wildCard(string pattern,string str);
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           cout<<wildCard(pat,text)<<endl;
   }
}
// } Driver Code Ends


/*You are required to complete this method*/
int wildCard(string pattern,string str)
{
    int m=pattern.size();
    int n=str.size();
    int i,j;
    
    
    bool dp[m+1][n+1];
    memset(dp,0,sizeof(dp));
    
    dp[0][0]=1;
    for(i=1;i<=m;i++)
    {
        if(pattern[i-1]=='*') //only true when stars from begining form empty sequence
        dp[i][0]=dp[i-1][0];
    }
    for(i=1;i<=m;i++)
    {
         
        for(j=1;j<=n;j++)
        {
          if(pattern[i-1]=='*')        //ignore(make it empty) or not ignore the *
          dp[i][j]=dp[i-1][j] || dp[i][j-1];
          else if(pattern[i-1]=='?' ||pattern[i-1]==str[j-1])
          dp[i][j]=dp[i-1][j-1];
           
           
        }
        
      
    }
    
    return dp[m][n]; 
}
