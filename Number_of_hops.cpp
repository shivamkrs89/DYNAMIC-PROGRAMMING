Given an integer list nums where each number represents the maximum number of hops you can make, return the minimum number of hops it would take to reach the last index starting at index 0. You can assume that you can always reach the last index.

Constraints

    n ≤ 100,000 where n is the length of nums

Example 1
Input

nums = [3, 3, 2, 0, 1]

Output

2

Explanation

We can jump from index 0 to 1 and then jump straight to the last index by jumping 3 steps.

//O(n) time ;

int solve(vector<int>& nums) {
 int n=nums.size();
 if(n==0)
 return 0;
 int dp[n];

int i,j;
 for(i=0;i<n;i++)
 dp[i]=INT_MAX;

dp[0]=0;
int maxi=-1;
 for(i=0;i<n;i++)//we use maxi to make sure that already minimum vertices don't get discovered again as it can't be smaller than what it's previous nodes has done
 {    int x=max(i,maxi)+1;
      int y=i+nums[i]+1; 
      for(j=x;j<y;j++)
      {
          if(j>=n)
          break;
       dp[j]=min(dp[j],1+dp[i]);
       cout<<i<<' '<<j<<'\n';
      }
      maxi=max(maxi,i+nums[i]); //maintaining max var
      if(maxi>=n-1)
              return dp[n-1];         
 }  

 return dp[n-1]; 
}
