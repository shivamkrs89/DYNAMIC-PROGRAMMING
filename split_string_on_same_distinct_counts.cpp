You are given a lowercase alphabet string s. Return the number of ways to split the string into two strings such that the number of distinct characters in each string is the same.

Constraints

1 ≤ n ≤ 100,000 where n is the length of s
Example 1
Input
s = "abaab"
Output
2
Explanation
We can split it by "ab" + "aab" and "aba" + "ab"
  
  //code
  int solve(string s) {
    int n=s.size(),i,j;
    int fwd[n];
    int bwd[n];
    int res=0;     
    int alphaf[26],alphab[26];
    memset(alphaf,0,sizeof(alphaf));
    memset(alphab,0,sizeof(alphab));
    int count=0; 
    for(i=0;i<n;i++)
    {
      char alph=s[i]-'a';
      if(alphaf[alph]==0)
      {
          alphaf[alph]=1;
          count++;
      }

      fwd[i]=count;
    }
    count=0;
    for(i=n-1;i>=0;i--)
    {
      char alph=s[i]-'a';
      if(alphab[alph]==0)
      {
          alphab[alph]=1;
          count++;
      }

      bwd[i]=count;
    }
    

    for(i=1;i<n;i++)
    {
       // cout<<fwd[i]<<' '<<bwd[i]<<'\n';
        if(fwd[i-1]==bwd[i])
        res++;

    }

    return res;
}
