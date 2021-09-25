You are given a list of sorted integers stones representing the positions of stones on a river you are trying to cross. To cross the river, you must end up on the last stone.

At every step, you can jump k - 1, k, or k + 1 units ahead where k is the distance of your last jump.

Assuming you start on the first stone and your first jump must have a distance of 1, return whether you can cross the river.

Constraints

    2 ≤ n ≤ 1,000 where n is the length of stones.

Example 1
Input

stones = [0, 1, 3, 4, 5, 6, 8, 9, 12]

Output

true

Explanation

Starting from the first stone, we can jump 1 unit to 1, then 2 units to 3, then 2 units to 5, then 3 units to 8, then 4 units to 12.
//code
  bool reach(vector<int> &stones,int u, int jump,int n,vector<vector<int>> &dp){
        if(stones[u]+jump == stones[n-1] || u==n-1) return true;

        if(dp[u][jump]!=-1) return dp[u][jump];
        
        bool res=false;
        for(int v=u+1;v<n;v++){//look for forward three psssibilities
            if(stones[u]+jump-1 == stones[v]){
                res = res || reach(stones,v,jump-1,n,dp);//jump always changes as jum+1,jum,jump-1
            }
            if(stones[u]+jump == stones[v]){
                  res = res || reach(stones,v,jump,n,dp);
            }
            if(stones[u]+jump+1 == stones[v]){
                  res = res || reach(stones,v,jump+1,n,dp);
            }
        }
        
     dp[u][jump]=res;
     return res;
    }
    
    bool solve(vector<int>& stones) {
        if(stones[1]!=1) return false;//as mentioned in problem
        int n=stones.size();
        
        vector<vector<int>> dp(1001,vector<int>(1001,-1));
  
        
        return reach(stones,1,1,n,dp);
    }
