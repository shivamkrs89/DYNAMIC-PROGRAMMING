You are given a list of integers nums representing tasks that you must get through in order. Each value represents the amount of time it takes to finish that task. Given that you can skip tasks as long as you don’t skip twice in a row, return the minimum time it takes to get through all the tasks.

Constraints

    n ≤ 100,000 where n is the length of nums.

Example 1
Input

nums = [10, 5, 7, 15]

Output

12

Explanation

We can skip the first and last tasks.
Example 2
Input

nums = [10, 20]

Output

10

Explanation

We can skip the last task.

  //code
  
//we find maximum non consecutive sum and subtract it with total sum
int solve(vector<int>& nums) {
   int p1,p2,p3;

   int sum=0,i;
   int n=nums.size();

   for(i=0;i<n;i++)
   {
      sum+=nums[i];
   } 
   if(n<=2)
   {
if(n<=1)
return 0;
else
return min(nums[0],nums[1]);
   }
   else
   {
       p1=nums[0],p2=nums[1];
       for(i=2;i<n;i++)
       {
         p3=nums[i]+p1;
         p1=max(p1,p2);
         p2=p3;
       }
       return sum-max(p1,p3); 
   }
   
}
