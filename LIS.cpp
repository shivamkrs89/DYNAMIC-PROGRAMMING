/*
Given an unsorted list of integers nums, return the longest strictly increasing subsequence of the array.
*/

//code
int solve(vector<int>& arr) {
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
