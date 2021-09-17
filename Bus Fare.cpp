You are given a list of sorted integers days , where you must take the bus for on each day. Return the lowest cost it takes to travel for all the days.

There are 3 types of bus tickets.

    1 day pass for 2 dollars
    7 day pass for 7 dollars
    30 day pass for 25 dollars

Constraints

    n ≤ 100,000 where n is the length of days

Example 1
Input

days = [1, 3, 4, 5, 29]

Output

9

Explanation

The lowest cost can be achieved by purchasing a 7 day pass in the beginning and then a 1 day pass on the 29th day.
Example 2
Input

days = [1]

Output

2
//code
//case
//[1,3,4,5,16,23,29,30,31,32,33,34,35,36,37,38,39,40] 25
int search(vector<int>&arr,int k)//checking index less than equal to k
{
    int n=arr.size();
    int low=0,hi=n-1;
    if(k<arr[low])
    return -1;
    while(low<hi)
    {
     int mid=(hi+low)/2;
    if(k==arr[mid])
    return mid;
     if(mid>0  && k>=arr[mid-1] && k<arr[mid])
     {
         return mid-1;
     }
     else if(mid<n-1 && k>=arr[mid] && k<arr[mid+1])
     return mid;

     else if(k<arr[mid])
     {
       hi=mid;
     }
     else 
     low=mid+1;

    }
    return -1;
}


int solve(vector<int>& days) {
    
    int n=days.size(),i;
    int m=days[n-1];
    map<int,int> dp;
    
   
  
    int v0,v1=7,v2=25;
    int curr,prev=0;
    for(int j=0;j<n;j++)
    {
        i=days[j];
//search for number which is less than equals to i-1/i-7/i-30 if it doen't eist we find for previous existing day and try adding 2/7/25 to that
        v0=search(days,i-1);
        v1=search(days,i-7);
        v2=search(days,i-30);
        dp[j]=min(dp[v0]+2,min(dp[v1]+7,dp[v2]+25));//trying to book for 1/7/30 dayas after v0,v1,v2 days respectively.
    }

    return dp[n-1];

}
