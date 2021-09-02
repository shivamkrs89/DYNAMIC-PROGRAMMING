Given the mapping a = 1, b = 2, ... z = 26, as well as "*" which can be mapped anything from 1 to 9, and an encoded message message (as a string), count the number of ways it can be decoded.

Mod the result by 10 ** 9 + 7.

Constraints

    n ≤ 100,000 where n is the length of message

Example 1
Input

message = "1*"

Output

18

Explanation

The "*" can represent anything from 1 to 9, so this can be decoded as:

    ["aa", "ab", "ac", "ad", "ae", "af", "ag", "ah", "ai"] - (1, 1), (1, 2), ..., (1, 9)`
    ["k", "l", "m", "n", "o", "p", "q", "r", "s"] (11), (12), ..., (19)

Example 2
Input

message = "22"

Output

2

Explanation

This can represent "bb" or "v"
Example 3
Input

message = "*00"

Output

0

Explanation

There's no valid decoding

      cases: ***,1**,0**,**0,123*2
        
        //code
        int solve(string message) {
int mod=1e9+7;
int i,j;
int n=message.size();
if(n==0)
return 1;
int c=0;

if(message[0]=='0')
return 0;


long long dp[n+1];
dp[0]=1,dp[1]=1;
if(message[0]=='*')
dp[1]=9;
//taking last along with and taking last alone are two things which we need to look after 
//i also took care of lot of different test cases  
//taking modulus in order to avoid avoerflow
for(i=2;i<=n;i++)
{
 dp[i]=0;
 if(message[i-1]=='*')//cases where we get * in last
 {
    //  dp[i]=dp[i-1];
    if(message[i-2]=='1')
    {
       dp[i]=((dp[i-1]*9)%mod+(dp[i-2]*9)%mod)%mod;
    }
    else if(message[i-2]=='2')
    {
        dp[i]=((dp[i-1]*9)%mod +(dp[i-2]*6)%mod)%mod;
    }
    else if(message[i-2]>'2')
    {
        dp[i]=(dp[i-1]*9)%mod;
    }
    else if(message[i-2]=='0')
    dp[i]=(dp[i-1]*9)%mod;
    else if(message[i-2]=='*') //making two units in different ways 
    dp[i]=((dp[i-1]*9)%mod + (dp[i-2]*15)%mod)%mod;

 }
 else{
  if(message[i-1]!='0'){
    dp[i]=dp[i-1]%mod;
    
  }
  if(message[i-1]=='0' && message[i-2]=='*')
  {
      dp[i]=(dp[i-2]*2)%mod;
  }
     //same if as decode message question
    else if(message[i-2]=='1' ||(message[i-2]=='2' && message[i-1]<'7'))
     dp[i]=(dp[i]+dp[i-2])%mod;

     else if(message[i-2]=='*')
     {
         if(message[i-1]>'6')
         //dp[i-1] says that it doesn't care where as dp[i-2]*2 says that it takes messages[i-3] as one unit and next two as one where next two can  form only one unitthat along with * as '1' as second char is greater than 6 so dp[i-2]*1
         dp[i]=(dp[i-1]+dp[i-2])%mod;
         else
         //dp[i-1] says that it doesn't care where as dp[i-2]*2 says that it takes messages[i-3] as one unit and next two as one where next two can form only two combinations so     dp[i-2]*2 
         dp[i]=(dp[i-1]+(dp[i-2]*2)%mod)%mod;
     }
    dp[i]=dp[i]%mod;
 }

 dp[i]=dp[i]%mod;
}





return dp[n]%mod;
}
