You are given a list of integers heights that represents the height of plants and another list of integers costs that represents the price needed to increase a plant's height by one.

Find the smallest cost to make each height in the heights list different from adjacent heights.

Constraints

n ≤ 100,000 where n is the length of heights and costs
Example 1
Input
heights = [1, 1, 2]
costs = [3, 1, 7]
Output
2
Explanation
We can increase the second height by 2, which costs 2 * 1 = 2.
  
  //code
  observation is that we can atmost increase height two times to get adjacent different 
  
  int solve(vector<int>& heights, vector<int>& costs) {
int n=heights.size();
int runcost=1e9+7;
int i,j,k;
int dp[n][3];

for(i=0;i<3;i++)
{
    dp[0][i]=costs[0]*i;
}

for(i=1;i<n;i++)
{
for(j=0;j<3;j++)
{
dp[i][j]=INT_MAX;
}

for(j=0;j<3;j++) //for previous plant with 0, 1 or 2 increase at a time
{
      for(k=0;k<3;k++) //for current element with 0, 1, or 2 increase at a time
      {
          if(heights[i-1]+j==heights[i]+k)
          {
              continue;
          }
          else
          {
              dp[i][k]=min(dp[i][k],dp[i-1][j]+costs[i]*k);
          }

      }
}

}

for(i=0;i<3;i++)
{
    runcost=min(runcost,dp[n-1][i]);
}

return runcost;
}
   //[2,1,1] [2,2,3]
   // heights = [1, 1, 1, 1, 1, 1]
//costs = [3, 1, 7, 2, 1, 3]   
           
                                         

       
        


