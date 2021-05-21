Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

Example 1:

Input:
N = 16
A[]={0,8,4,12,2,10,6,14,1,9,5
     13,3,11,7,15}
Output: 6
Explanation:Longest increasing subsequence
0 2 6 9 13 15, which has length 6

Example 2:

Input:
N = 6
A[] = {5,8,3,7,9,1}
Output: 3
Explanation:Longest increasing subsequence
5 7 9, with length 3

Your Task:
Complete the function longestSubsequence() which takes the input array and its size as input parameters and returns the length of the longest increasing subsequence.
  
  //code O(n^2) time and O(n) space solution
  
  int longestSubsequence(int n, int a[])
    {
       // your code here
       int arr[n],i,j;
       for(i=0;i<n;i++)
       arr[i]=1;
       int maxlen=1;
       for(i=1;i<n;i++)
       {
           for(j=i-1;j>=0;j--)
           {
               if(a[j]<a[i]){
               arr[i]=max(arr[j]+1,arr[i]);
               }
           }
           
           maxlen=max(arr[i],maxlen);
       }
    
    return maxlen;   
    }
