Given a 2D matrix M of dimensions RxC. Find the maximum sum submatrix in it.

Example 1:

Input:
R=4
C=5
M=[[1,2,-1,-4,-20],
[-8,-3,4,2,1],
[3,8,10,1,3],
[-4,-1,1,7,-6]]
Output:
29
Explanation:
The matrix is as follows and the
blue rectangle denotes the maximum sum
rectangle.
Thumbnail
Example 2:

Input:
R=2
C=2
M=[[-1,-2],[-3,-4]]
Output:
-1
Explanation:
Taking only the first cell is the 
optimal choice.

Your Task:
You don't need to read input or print anything. Your task is to complete the function maximumSumRectangle() which takes the number R, C, and the 2D matrix M as input parameters and returns the maximum sum submatrix.


Expected Time Complexity:O(R*R*C)
Expected Auxillary Space:O(R*C)
  
  
  //code
  
  //{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int getKadaneSum(int *arr,int n)
   {
       int max0=0,max1=0;
       bool flag=0;
       for(int i=0;i<n;i++)
       {
           max1+=arr[i];
           if(max1<0)
           max1=0;
           
           if(max1>max0)
           {max0=max1;flag=1;}
           
       }
       
       if(flag==0)
       {
           max0=arr[0];
           for(int i=0;i<n;i++)
           max0=max(max0,arr[i]);
       }
       
       return max0;
   }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        int i,j,k,l;
        int maxsum=INT_MIN;
        int currsum;
        
        
        for(i=0;i<C;i++)
        {
            int tempColSum[R];
            for(j=0;j<R;j++)
            {
                tempColSum[j]=0;
            }
            
            for(int rp=i;rp<C;rp++)
            {
                for(j=0;j<R;j++)
                {
                    tempColSum[j]+=M[j][rp];
                   //cout<<tempColSum[j]<<' ';
                }
                
                currsum=getKadaneSum(tempColSum,R);
                if(currsum>maxsum)
                maxsum=currsum;
                //cout<<'\n'<<currsum<<'\n';
                
            }
            
            
        }
        
        return maxsum;
     
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends
