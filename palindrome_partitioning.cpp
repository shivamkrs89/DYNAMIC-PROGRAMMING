Given a lowercase alphabet string s, split it into as few strings as possible such that each string is a palindrome and return the number of strings.

Constraints

    0 ≤ n ≤ 1,000 where n is the length of s

Example 1
Input

s = "amanaplanacanalpanama"

Output

1

Explanation

The whole string is a palindrome.
Example 2
Input

s = "racecarannakayak"

Output

3

Example 3
Input

s = "abc"

Output

3

Example 4
Input

s = "atabatab"

Output

2

Explanation

This can be split into ["ata", "batab"] or ["atabata", "b"].

  
  //code
  
int solve(string a) {
    int n=a.size();
    if(n==0)
    return 0;
    int cut[n];
   bool palindrome[n][n];
    memset(palindrome, false, sizeof(palindrome));
   int i,j;
    for(i=0;i<n;i++)
    {
        palindrome[i][i]=1;//same 1 letter word as palindrome true
    }
    //to check for palindromes only
    for (int L = 2; L <= n; L++)
    {
        for (int k=0;k<n-L+1;k++)
        {
            i=k,j=k+L-1;//start and end index

            if(L==2)
            palindrome[i][j]=(a[i]==a[j]);
            else
         palindrome[i][j]=((a[i]==a[j]) && palindrome[i+1][j-1]);
        }
        
    }

//to check for fewest palindromes or cuts to make
    for(i=0;i<n;i++)
    {
        if(palindrome[0][i]==1)//best case when palindrome starts from 0th index
        cut[i]=0;//no need of cuts
        else
        {
            cut[i]=1e9+7;//initailsing as large num
            for(j=0;j<i;j++)
            {
                if(palindrome[j+1][i] && 1+cut[j]<cut[i])//if strinf[j+1....i] is palindrome and cuts made upto i is greater than 1+cuts upto j th index then we use lesser value 
                {
                      cut[i]=1+cut[j];
                }
            }
        }
       
    }

    // at he end we return total number of cuts upto last index +1 asnumber of palindromes
     return cut[n - 1]+1;
}
