Given a list of integers nums, which contains either -1 or 1, return the length of the longest sublist that sums to 0.

Constraints

    n ≤ 100,000 where n is the length of nums.

Example 1
Input

nums = [1, 1, 1, 1, -1, -1, 1, -1]

Output

6

Explanation

The longest sublist that sums to 0 is [1, 1, -1, -1, 1, -1] which has length 6.
//code
  //cases 1 -1 -1
  // -1
  //1 -1 1 -1
  //-1 -1 1 -1 -1 -1
  int solve(vector<int>& nums) {
    
    int n=nums.size();
    if(n<=1)
    return 0;
    // vector<int> dp(n,0);
    unordered_map<int,int> dp;//map for maintaining first index heere sum appears
    int i,j;
    
    dp[0]=-1;
    dp[nums[0]]=-2;
    int sum=nums[0],mxlen=0;
    for(i=1;i<n;i++)
    {
          sum+=nums[i];
          if(dp[sum]) //if sum has occured before we need to take diference of current and first appeared position
          {
              int first;
              if(dp[sum]==-2) //case here value is 0 as in mao we can store it as 0 so we store as -2 and wherever -2 appears we make it back to 0
              {
                first=0;
              }
              else
              first=dp[sum];
              mxlen=max(mxlen,i-first);
              //cout<<i<<' '<<i-first<<'\n';
          }
          else
          dp[sum]=i;
    }

return mxlen;
}
