Given an array nums of n positive integers. The task is to find the longest Zig-Zag subsequence problem such that all elements of this are alternating (numsi-1 < numsi > numsi+1 or numsi-1 > numsi < numsi+1).
 

Example 1:

Input: nums = {1,5,4}
Output: 3
Explanation: The entire sequenece is a 
Zig-Zag sequence.

Examplae 2:

Input: nums = {1,17,5,10,13,15,10,5,16,8}
Ooutput: 7
Explanation: There are several subsequences
that achieve this length. 
One is {1,17,10,13,10,16,8}.

 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function ZigZagMaxLength() which takes the sequence  nums as input parameter and returns the maximum length of alternating sequence.
  
  //code
  
  int ZigZagMaxLength(vector<int>&nums){
		    // Code here
		    int n=nums.size();
            int i;
            int len=1;
            int sign,lastsign=0;
            for(i=1;i<n;i++)
            {
                if(nums[i]-nums[i-1]<0)
                sign=1;
                else if(nums[i]-nums[i-1]>0)
                sign=-1;
                else
                sign=0;
                
                if(sign!=0 && sign!=lastsign)//if sequence pattern not matches then append them
                {len++;lastsign=sign;}
                
                
            }
		    
		   return len; 
		}
