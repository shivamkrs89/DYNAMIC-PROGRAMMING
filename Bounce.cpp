You are given a list of integers nums and an integer k. Given you start at index k and at any index i, you can go left or right by exactly nums[i] steps. Return whether you can reach the end of the list.

Constraints

    n ≤ 100,000 where n is the length of nums

Example 1
Input

nums = [0, 0, 1, 2, 0, 3]

k = 2
  
  //code
  
bool recsolve(vector<int> &nums,int k,bool *vis)
{
    vis[k]=1;
    if(nums[k]==0){
        if(k==int(nums.size()-1))
        return 1;
        else
        return 0;
    }
   
    if(k==nums.size()-1)
    return 1;
    bool b1=0,b2=0;
    if(k-nums[k]>=0 && !vis[k-nums[k]])
    {
        b1=recsolve(nums,k-nums[k],vis); 
    }
    if(k+nums[k] < int(nums.size()) && !vis[k+nums[k]])
    {
        b2=recsolve(nums,k+nums[k],vis); 
    }


return b1 || b2;


}




bool solve(vector<int>& nums, int k) {
    int n=nums.size();
    bool vis[n];

    memset(vis,0,sizeof(vis));
 return recsolve(nums,k,vis);



}
