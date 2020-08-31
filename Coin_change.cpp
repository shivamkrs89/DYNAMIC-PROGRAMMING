/*
Coin Change - Minimum number of coins

You are given an amount denoted by value. You are also given an array of coins. The array contains the denominations of the give coins. You need to find the minimum number of coins to make the change for value using the coins of given denominations. Also, keep in mind that you have infinite supply of the coins.

Example 1:

Input:
value = 5
numberOfCoins = 3
coins[] = {3,6,3}
Output: Not Possible
Explanation:We need to make the change for
value = 5 The denominations are {3,6,3}
It is certain that we cannot make 5 using
any of these coins.

Example 2:

Input:
value = 10
numberOfCoins = 4
coins[] = {2 5 3 6}
Output: 2
Explanation:We need to make the change for
value = 10 The denominations are {2,5,3,6}
We can use two 5 coins to make 10. So
minimum coins are 2.

Your Task:
You only need to complete the function minimumNumberOfCoins() that take array of coins, size of array, and value as parameters. You need to return the minimum number of coins required. If it is not possible to make the exact value out of the given coin denominations, return -1 ("Not Possible" will be printed by the driver's code in this case).

Expected Time Complexity: O(N*V).
Expected Auxiliary Space: O(V)

Constraints:
1 <= value <= 103
1 <= numberOfCoins <= 103
1 <= coinsi <= 1000
*/
//code goes here
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//Complete this function
long long minimumNumberOfCoins(int coins[],int numberOfCoins,int value)
{
    // your code here
    int minvalue[value+1];
    int i,c;
    for(i=0;i<=value;i++)
    minvalue[i]=10000;
    sort(coins,coins+numberOfCoins);
    
    for(i=1;i<=value;i++)
    {
        for(c=0;c<numberOfCoins;c++)
        {
           
            if(coins[c]==i)
            {
               minvalue[i]=1;
        
            }
            else if(coins[c]>i)
            {
                break;
            }
            else
            {
                 minvalue[i]=min(minvalue[i],minvalue[i-coins[c]]+minvalue[coins[c]]);
            } 
        }
      
    }
    
    if(minvalue[value]>=10000)
    return -1;
    return minvalue[value];
}

// { Driver Code Starts.



int main() {
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    int value;
	    cin>>value;
	    int numberOfCoins;
	    cin>>numberOfCoins;
	    int coins[numberOfCoins];
	    
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    
	    int answer=minimumNumberOfCoins(coins,numberOfCoins,value);
	    if(answer==-1)
	    cout<<"Not Possible"<<endl;
	    else
	    cout<<answer<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends
