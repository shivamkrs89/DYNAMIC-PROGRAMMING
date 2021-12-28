//question
You are given an integer height and a list of integers blacklist. You are currently standing at height height and you are playing a game to move a small ball down to height 0.

In even rounds (0, 2, 4, 6 etc.) you can move the ball down 1, 2, or 4 stairs down. In odd rounds, you can move the ball down 1, 3, or 4 stairs. There are some levels of the stairs where if the ball lands there, it will die as labelled in blacklist. Return number of ways you can move the ball down to height 0. Mod the result by 10 ** 9 + 7.

Constraints

1 ≤ height ≤ 100,000
0 ≤ b ≤ 100,000 where b is the length of blacklist
Example 1
Input
height = 4
blacklist = [2]
Output
2
Explanation
We can move 4 stairs down on round 0.
We can move 1 stair down on round 0 and then 3 stairs down on round 1.
Example 2
Input
height = 5
blacklist = [0]
Output
0
Explanation
There's no way to reach height 0 since it's on the blacklist.
  
  //code
  long long int md=1000000007;
long long int solveutil(int height,int round,unordered_map<int,bool> &mblack,vector<vector<long long int>>&dp)
{
    if(height<0 || mblack[height])
    return 0;
   
    if(height==0)
    return 1;
  
    if(round%2==0){ 
           if(dp[height][0]!=0)
    return dp[height][0];
        long long int x1,x2,x4;
        x1=solveutil(height-1,round+1,mblack,dp);
        
        x2=solveutil(height-2,round+1,mblack,dp);
        x4=solveutil(height-4,round+1,mblack,dp);
        dp[height][0]+=(x1+x2+x4)%md;
        return dp[height][0];
    }
    else
    {
           if(dp[height][1]!=0)
    return dp[height][1];
        long long int x1,x3,x4;
        x1=solveutil(height-1,round+1,mblack,dp);
        
        x3=solveutil(height-3,round+1,mblack,dp);
        x4=solveutil(height-4,round+1,mblack,dp);
        dp[height][1]+=(x1+x3+x4)%md;
        return dp[height][1];
    }

    
}

//divide and conquer+ Dp
//can think without any blacklist constraint first
int solve(int height, vector<int>& blacklist) {
    vector<vector<long long int>>dp(height+1,vector<long long int>(2,0)); //2d dp array for case when round is odd and even in particular height

    unordered_map<int,bool> mblack;
    int n=blacklist.size();
    int i,j;

    for(i=0;i<n;i++)
    {
        mblack[blacklist[i]]=1; //blacklisting using map
    }
    if(mblack[height] || mblack[0])
    return 0;
   long long res=(solveutil(height-1,1,mblack,dp)+solveutil(height-2,1,mblack,dp)+solveutil(height-4,1,mblack,dp))%md;
   

    return res;

}
