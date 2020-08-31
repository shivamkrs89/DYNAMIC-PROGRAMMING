/*
Count number of hops

A frog jumps either 1, 2, or 3 steps to go to the top. In how many ways can it reach the top. As the answer will be large find the answer modulo 1000000007.

Example 1:

Input:
N = 1
Output: 1

Example 2:

Input:
N = 4
Output: 7
Explanation:Below are the 7 ways to reach
4
1 step + 1 step + 1 step + 1 step
1 step + 2 step + 1 step
2 step + 1 step + 1 step
1 step + 1 step + 2 step
2 step + 2 step
3 step + 1 step
1 step + 3 step

Your Task:
Your task is to complete the function countWays() which takes 1 argument(N) and returns the answer%(10^9 + 7).

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 105
*/
//code goes here
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 
long long countWays(int);
 
int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		cout << countWays(n) << endl;
	}
    
    return 0;
    
}
// } Driver Code Ends


// function to count number of ways to reach top of the stair
long long countWays(int n){
    
    // your code here
    long long  j1=1,j2=2,j3=4,i;
    long long mod=1000000007;
    if(n==1)
    return 1;
    if(n==2)
    return j2;
    if(n==3)
    return 4;
    for(i=4;i<=n;i++)
    {
        long long t=(j3+j2+j1)%mod;
        j1=j2;j2=j3;j3=t;
    }
    
    return j3%mod;
}
