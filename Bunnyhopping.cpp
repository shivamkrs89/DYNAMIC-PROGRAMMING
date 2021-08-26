You are given a list of integers nums and an integer k. The nums list represents the costs of landing at each index. You must start at index 0 and end at the last index of nums. In each step you can move from some position X to any position up to k steps away.

You want to minimize the sum of the costs of the positions you land at. What is this minimum sum?

Constraints

    n ≤ 100,000 where n is the length of nums
    1 ≤ k ≤ 100,000

Example 1
Input

nums = [1, 2, 3, 4, 5]

k = 2

Output

9

Explanation

We pick 1 + 3 + 5 to get a minimum cost of 9.
//code
  approach 1 DP approach O(n*k)
  int solve(vector<int>& nums, int k) {
    int n=nums.size(),i,j;
    if(n==0)
    return 0;
    int sum[n];
    sum[0]=nums[0];

    for(i=1;i<n;i++)
    {
     sum[i]=1e9+7;
    }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<=i+k;j++)
        {
            if(j>=n)
            break;
          sum[j]=min(sum[i]+nums[j],sum[j]);
        
    } 

    return sum[n-1];
}
  
  //Approach 2 heap approach O(n*logk)
  
  
  
  int solve(vector<int>& nums, int k) {
    int n=nums.size(),i,j;
    if(n==0)
    return 0;
    int sum[n];
    sum[0]=nums[0];

priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
pq.push({nums[0],0}); 
//dp solution with O(n*k) looks to previous k elements
//we do the same here but smartly
//we look minimum in previous k elements and add that to
//current and add that to priority queue itself
    for(i=1;i<n;i++)
    {
    
    while(!pq.empty() && i-pq.top().second>k)//its for ensuring that we don't get elemnts beyond previous k
    pq.pop();
    
    sum[i]=nums[i]+pq.top().first;
    pq.push({sum[i],i});

        
    } 

    return sum[n-1];

  
}
