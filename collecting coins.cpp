You are given a two-dimensional integer matrix where each cell represents number of coins in that cell. Assuming we start at matrix[0][0], and can only move right or down, find the maximum number of coins you can collect by the bottom right corner.

Constraints

    n, m ≤ 100 where n and m are the number of rows and columns in matrix.

Example 1
Input

matrix = [
    [0, 3, 1, 1],
    [2, 0, 0, 4]
]

Output

9


//code 

int solve(vector<vector<int>>& matrix) {
    
    int i,j;
    int n=matrix.size(),m=matrix[0].size();
//calculating for first row separately if moving only right 
    for(i=1;i<m;i++)
    {
            matrix[0][i]+=matrix[0][i-1];
    }
    
    //calculating for first column separately if down moving
    for(i=1;i<n;i++)
    {
            matrix[i][0]+=matrix[i-1][0];
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<m;j++)
        {
            matrix[i][j]+=max(matrix[i-1][j],matrix[i][j-1]);//checking previous calculated value with adjacent cells to up and left
        }
    }

    return matrix[n-1][m-1];
}
