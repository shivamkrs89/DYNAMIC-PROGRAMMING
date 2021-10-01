Given a two-dimensional list of integers matrix, find the largest k × k submatrix such that all of its elements are the same value, and return the k.

Constraints

    n, m ≤ 250 where n and m are the number of rows and columns in matrix.

Example 1
Input

matrix = [
    [1, 1, 3],
    [1, 1, 3],
    [5, 5, 5]
]

Output

2

Explanation

There's a 2 × 2 square of 1s on the top left.
//code
  int solve(vector<vector<int>>& matrix) {
    
   int n=matrix.size();
   if(n==0)
    return 0;
   int m=matrix[0].size();

   int dpm[n][m];
   int i,j;
     for(i=0;i<n;i++)
   {
       for(j=0;j<m;j++)
       {
           dpm[i][j]=1;
       }
   }
int maxi=1;
     for(i=1;i<n;i++)
   {
       for(j=1;j<m;j++)
       {
        if(matrix[i][j]==matrix[i-1][j-1] && matrix[i][j]==matrix[i-1][j] && matrix[i][j]==matrix[i][j-1])//it should be square with atleast 2 size 
        {
            dpm[i][j]=1+min(dpm[i-1][j-1],min(dpm[i-1][j],dpm[i][j-1]));//we check for minimum size square which is possible with it's all adjacent elements
            maxi=max(dpm[i][j],maxi);//we update maimum value of dp[i][j] accordingly
        }
       
      
       }
   }
   return maxi;
}

//[[0,0,0],[0,0,0],[1,0,0]]
