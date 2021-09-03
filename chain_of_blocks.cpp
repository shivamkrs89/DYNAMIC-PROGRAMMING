You are given a list blocks where each block contains two integers [start, end] where start < end. You can join two blocks if the end of one is equal to the start of another. Return the length of the longest chain of blocks.

Constraints

    0 ≤ n ≤ 100,000 where n is the length of blocks.

Example 1
Input

blocks = [
    [3, 4],
    [4, 5],
    [3, 7],
    [0, 1],
    [1, 3]
]

Output

4

Explanation

We can form the following chain: [0, 1], [1, 3], [3, 4], [4, 5]


*//test case
0 1
0 2
2 3
*
1 4
4 6
4 7
6 8
7 8
7 9
9 11
  
  //code
  bool comp(vector<int> &v1,vector<int> &v2)
{
    if(v1[0]==v2[0])
    return v1[1]<v2[1];

    return v1[0]<v2[0];
}


int solve(vector<vector<int>>& blocks) {
    int n=blocks.size();
    if(n==0)
    return 0;
    if(n==1)
    return 1;
    sort(blocks.begin(),blocks.end(),comp);

    int maxi=0;
    int i,count=1;
    
    unordered_map<int,int> m1;
    m1[blocks[0][1]]=1;
    for(i=0;i<n-1;i++)
    {
        int f1=blocks[i][0],l1=blocks[i][1];
        int f2=blocks[i+1][0],l2=blocks[i+1][1];

            m1[l2]=max(m1[l2],m1[f2]+1);
       // cout<<m1[l2]<<'\n';
        maxi=max(maxi,m1[l2]);
    }
    return maxi;

}
  
