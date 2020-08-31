/*
Max length chain

You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. You have to find the longest chain which can be formed from the given set of pairs. 
 

Example 1:

Input:
N = 5
P[] = {5  24 , 39 60 , 15 28 , 27 40 , 50 90}
Output: 3
Explanation: The given pairs are { {5, 24}, {39, 60},
{15, 28}, {27, 40}, {50, 90} },the longest chain that
can be formed is of length 3, and the chain is
{{5, 24}, {27, 40}, {50, 90}}


​Example 2:

Input:
N = 2
P[] = {5 10 , 1 11}
Output: 1
Explanation:The max length chain possible is only of
length one.

 

Your Task:
You don't need to read input or print anything. Your task is to Complete the function maxChainLen() which takes a structure p[] denoting the pairs and n as the number of pairs and returns the length of the longest chain formed.

 

Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(N)

Constraints:
1<=N<=100
*/
//code goes here
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/
bool sortbyfirst(struct val a,struct val b) 
{ 
    return (a.first < b.first); 
} 
/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
//Your code here
sort(p,p+n,sortbyfirst);
int i,j;
int dp[n];
for(i=0;i<n;i++)
{
    cout<<p[i].first<<' '<<p[i].second<<'\n'; 
    dp[i]=1;
}


for(i=n-1;i>=0;i--)
{
    int X=p[i].first,index=i;
    for(j=i-1;j>=0;j--)
    {
        if(X>p[j].second && dp[index]+1>dp[j])
        {
            dp[j]=dp[index]+1;
            index=j;
            X=p[j].first;
          
        }
    }
}
int maxi=0;
for(i=0;i<n;i++)
{
   
    if(dp[i]>maxi)
    maxi=dp[i];
}
return maxi;
}
