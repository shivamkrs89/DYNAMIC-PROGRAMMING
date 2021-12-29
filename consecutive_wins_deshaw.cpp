You are given integers n and k. Given that n represents the number of games you will play, return the number of ways in which you win k or less games consecutively. Mod the result by 10 ** 9 + 7.

Constraints

n ≤ 10,000
k ≤ 10
Example 1
Input
n = 3
k = 2
Output
7
Explanation
Here are the ways in which we can win 2 or fewer times consecutively:

"LLL"
"WLL"
"LWL"
"LLW"
"WWL"
"LWW"
"WLW"
  
  //code
  
long long int dp[10001][11];

class Solution
{
public:
int n,k;

long long md=1000000007;

Solution(int n,int k)
{
    this->n=n;
    this->k=k;
}
  long long solveutil(int consec,int index)
  {

     if(consec>k) //if we have won more than k times consecutively then we no longer go on
     {             
      return 0;
     }

     if(index==n) //if we reach end of number of games than it is a way so return 1
     return 1;

     long long int res=dp[index][consec];
     if(res==0)
     {
        res= dp[index][consec]=(solveutil(consec+1,index+1)+solveutil(0,index+1))%md;
        //for given instance think about what can we do next if we win then consec+1 or if we lose than consec=0 as streak is broken 
     }
     return res;
  }
};
int solve(int n, int k) {
    int consec_wins=0;
    memset(dp,0,sizeof(dp));
    Solution s1(n,k);
    return  s1.solveutil(consec_wins,0);
}
