Given a list of integers nums, find the length of the longest increasing subsequence assuming the subsequence can wrap around to the beginning of the list.

Constraints

    n ≤ 1,000 where n is the length of nums.

Example 1
Input

nums = [5, 4, 7, 1, 2, 3]

Output

5

Explanation

One longest increasing subsequence is [1, 2, 3, 5, 7]

//code
variation of LIS.cpp


int LIS(vector<int> &arr){
   if(arr.size()==0)
   return 0;
    int n=arr.size();
    int nums[n];
    int i,j;
    for(i=0;i<n;i++)
    nums[i]=arr[i];

    int lis[n];
   
    lis[0]=nums[0];
    j=1;
    for(i=1;i<n;i++)
    {
        if(nums[i]>lis[j-1])
        {
             lis[j]=nums[i];
             j++;
        }
        else
        {
            //refer to gfg LIs video
            int index=upper_bound(lis,lis+j,nums[i])-lis;
            if(index>0 && lis[index-1]==nums[i])
            continue;

            lis[index]=nums[i];
        }

      
    }

    return j;
}

int solve(vector<int>& nums) {

int n=nums.size();
int mx=0;
for(int i=0;i<n;i++)
{
    int k=0,j=i;
    vector<int> v1;
    while(k<n)
    {
      j=j%n;
      v1.push_back(nums[j]);
      j++;
      k++;
    }

   mx=max(mx,LIS(v1));
}

return mx;
}
