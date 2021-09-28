A person is placed on a list of length length, at index 0, and on each step, they can move right one index or left one index (without going out of bounds), or stay on that index.

Given that the person can take exactly n steps, how many unique walks can the person take and reach back to index 0? Mod the result by 10 ** 9 + 7.

Constraints

    length ≤ 1,000
    n ≤ 500

Example 1
Input

length = 5

n = 3

Output

4

Explanation

The four actions are:

    stay at index 0 3 times in a row.
    right, stay, left.
    right, left, stay.
    stay, right, left.

//code
      
      int solveutil(int nmoves,int pos,int sz,vector<vector<long long>> &dp)
{

    if(pos<0 || nmoves<0 || pos>=sz)//if pos becomes less than 0 or greater than size 
    return 0;
    if(nmoves==0 && pos==0)
    return 1;
    long long ways=0,md=1e9+7;
    //cout<<ways<<'\n';
    if(nmoves-1>=0 && pos+1<sz){
        if(dp[nmoves-1][pos+1]==-1){
    dp[nmoves-1][pos+1]=solveutil(nmoves-1,pos+1,sz,dp);//check for nmoves-1 with position as right of curr
        }
        ways+=dp[nmoves-1][pos+1]%md;
    }
     if(nmoves-1>=0 && pos-1>=0){
        if(dp[nmoves-1][pos-1]==-1){
    dp[nmoves-1][pos-1]=solveutil(nmoves-1,pos-1,sz,dp);
        }
        ways+=dp[nmoves-1][pos-1]%md;
    }
     if(nmoves-1>=0){
        if(dp[nmoves-1][pos]==-1){
    dp[nmoves-1][pos]=solveutil(nmoves-1,pos,sz,dp);
        }
        ways+=dp[nmoves-1][pos]%md;
    }

    return ways%md;
}

int solve(int sz, int n) {
    vector<vector<long long>> dp(n,vector<long long>(sz+1,-1));
return solveutil(n,0,sz,dp);

}
