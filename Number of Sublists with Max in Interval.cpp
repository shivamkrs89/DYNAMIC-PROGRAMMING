You are given a list of integers nums and integers lo and hi. Return the number of sublists A such that lo ≤ max(A) ≤ hi.

Constraints

    0 ≤ n ≤ 100,000 where n is the length of nums

Example 1
Input

nums = [1, 5, 3, 2]

lo = 1

hi = 4

Output

4

Explanation

We have the following sublists where 1 ≤ max(A) ≤ 4

    [1]
    [3]
    [3, 2]
    [2]

//code
int getsum(int n)
{
  return n*(n+1)/2;
}


int solve(vector<int>& nums, int lo, int hi) {
    int n=nums.size();
    int i,j;
    
    int inc1=0,inc2=0;//inc1 for nums less thna lo and inc2 for nums less than hi
    int s1=0;
    for(i=0;i<n;i++)
    {
      if(nums[i]<lo)//nums which are less than low are less than both lo and hi
      {
        inc1++;
        inc2++;
      }
      else if(nums[i]<=hi && nums[i]>=lo) //nums in between is less than hi and all nums which causes subarray only consist of negatives are subtracted.
      {
        inc2++;
        s1-=(getsum(inc1));//at times s1 may be negative but it will be balanced later 
        inc1=0;
      }
      else
      {
       s1+=(getsum(inc2)-getsum(inc1));//when nums is larger we take all sum upto hi -sum upto low and reintialise inc1,inc2
       inc1=0;inc2=0;
      }
    }
     s1+=(getsum(inc2)-getsum(inc1));

     return s1;
}



//nums = [3, -5, 2, -4]
//lo = 1
//hi = 4
//nums = [-3, 5, -2, 4]
//lo = 1
//hi = 4

