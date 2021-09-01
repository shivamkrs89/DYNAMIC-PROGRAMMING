Given the mapping "a" = 1, "b" = 2, ... "z" = 26, and an encoded message message (as a string), count the number of ways it can be decoded.

Constraints

    n ≤ 100,000 where n is the length of message

Example 1
Input

message = "111"

Output

3

Explanation

This can be decoded 3 ways: aaa, ak, and ka.
Example 2
Input

message = "8"

Output

1

Explanation

This can be only decoded one way, as h.
Example 3
Input

message = "12"

Output

2

Explanation

This can be decoded 2 ways: ab or l.
Example 4
Input

message = "60"

Output

0

Explanation

There's no way to decode this message.
Example 5
Input

message = "0012"

Output

0

//solution explained in https://www.geeksforgeeks.org/count-possible-decodings-given-digit-sequence/





//example of 1D variation with different cases

int solve(string message) {

int i,j;
int n=message.size();
if(n==0)
return 0;
int c=0;

if(message[0]=='0')
return 0;

if(n==1)
return 1;
int dp[n+1];
dp[0]=1,dp[1]=1;

for(i=2;i<=n;i++)
{
 dp[i]=0;
  if(message[i-1]!='0')
    dp[i]=dp[i-1];
     
     if(message[i-2]=='1' ||(message[i-2]=='2' && message[i-1]<'7'))
     dp[i]+=dp[i-2];
    

}





return dp[n];


}
