You are looking to paint a row of N fences that can be of K different colors. You have a goal of minimizing cost while ensuring that no two neighboring fences are of the same color.

Given an N by K matrix where the nth row and kth column represents the cost to paint the nth fence with kth color, return the minimum cost which achieves this goal.

Note: All costs will be integers greater than or equal to 0, and there is guaranteed to be at least 2 possible colors.

Bonus: solve in O(1)\mathcal{O}(1)O(1) space.

Constraints

    N, K ≤ 500

Example 1
Input

matrix = [
    [5, 3, 4],
    [2, 1, 6],
    [2, 3, 4],
    [4, 3, 3]
]

Output

10

Explanation

Choose the following color indices (starting from the first fence): 4 -> 1 -> 2 -> 3.
Example 2
Input

matrix = [
    [1, 1, 1],
    [1, 1, 1],
    [1, 1, 1],
    [1, 1, 1],
    [1, 1, 1]
]

Output

5

Explanation

It doesn't matter which colors we paint since they're all cost 1.
Example 3
Input

matrix = [
    [1, 5, 1],
    [1, 5, 1],
    [1, 5, 1],
    [1, 5, 1],
    [1, 5, 1]
]

Output

5

Explanation

Alternate between the first and the third color which each cost 1.
Example 4
Input

matrix = [
    [1, 2, 3],
    [4, 1, 8],
    [2, 3, 4],
    [3, 3, 1],
    [4, 2, 3]
]

Output

7

Explanation

Choose the following colors: 1 -> 1 -> 2 -> 1 -> 2.

  
  //code
  void findmin(vector<int> &v1,int &min1,int &min2)
{
    int mini=1e9+7,mini2=1e9+7;
    int n=v1.size();
    for(int i=0;i<n;i++){//finding min1
    if(v1[i]<mini)
    {
        mini=v1[i];
        min1=i;
    }
    }

    for(int i=0;i<n;i++)//finding min2
    {
         if(i!=min1)
         {
             if(v1[i]<mini2){
             mini2=v1[i],min2=i;
             }
         }
    }

}
int solve(vector<vector<int>>& matrix) {   
int n=matrix.size();
int k=matrix[0].size();
int i,j;
i=0,j=0;

//using no space by using existing matrix as dp matrix
for(i=1;i<n;i++)
{
  
    int min1=-1, min2=-1;
    findmin(matrix[i-1],min1,min2);//finding 2 minimum indices of the given row
    for(j=0;j<k;j++)
    {                       //checking if coulumn is same of not to that of min1 and min2 indices
 matrix[i][j]=matrix[i][j]+ (j!=min1?matrix[i-1][min1]:matrix[i-1][min2]);

    }
  
}
vector<int> v2=matrix[n-1];
int mans1=-1,mans2=-1;
findmin(v2,mans1,mans2);
return v2[mans1]; 
}
