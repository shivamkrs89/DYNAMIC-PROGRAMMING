/*
Maximize The Cut Segments

Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.

Example 1:

Input:
N = 4
x = 2, y = 1, z = 1
Output: 4
Explanation:Total length is 4, and the cut
lengths are 2, 1 and 1.  We can make
maximum 4 segments each of length 1.

Example 2:

Input:
N = 5
x = 5, y = 3, z = 2
Output: 2
Explanation: Here total length is 5, and
the cut lengths are 5, 3 and 2. We can
make two segments of lengths 3 and 2.

Your Task:
You only need to complete the function maximizeTheCuts() that takes n, x, y, z as parameters and returns max number cuts.

Expected Time Complexity : O(N)
Expected Auxiliary Space: O(N)

Constraints
1 <= N, x, y, z <= 10^4
*/
//code goes here
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z);

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        
        int x,y,z;
        cin>>x>>y>>z;
        
        cout<<maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}// } Driver Code Ends


//Complete this function
int maximizeTheCuts(int n, int x, int y, int z)
{
    //Your code here
    int i,j;
    int seg[3]={x,y,z};
    sort(seg,seg+3);
    x=seg[0];y=seg[1];z=seg[2];
    int a[n+1];
    for(i=0;i<=n;i++)
    a[i]=0;
    
    a[x]=1;
    for(i=1;i<=n;i++)
    {
   for(j=0;j<3;j++)
   {
       if(i==seg[j])
       {
           a[i]=max(a[i],1);
       }
     else if(i>seg[j])
     {
         if(a[i-seg[j]]!=0 && a[seg[j]]!=0)
         a[i]=max(a[i],a[i-seg[j]]+a[seg[j]]);
     }
   }
    }
    
    return a[n];
}
