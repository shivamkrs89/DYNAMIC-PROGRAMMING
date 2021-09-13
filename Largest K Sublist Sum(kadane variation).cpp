You are given a list of integers nums, and an integer k, which represents a large list of nums concatenated k times. Return the sum of the sublist with the largest sum. The sublist can be empty.

Constraints

    0 ≤ n ≤ 100,000 where n is the length of nums.
    0 ≤ k ≤ 10,000

Example 1
Input

nums = [1, 3, 4, -5]

k = 1

Output

8

Explanation

We can take the sublist [1, 3, 4]
Example 2
Input

nums = [1, 3, 4, -5]

k = 2

Output

11

Explanation

We can take the sublist [1, 3, 4, -5, 1, 3, 4]

//code
int solve(vector<int>& nums, int k) {
    int n = nums.size();

    if (n == 0 || k == 0) {
        return 0;
    }

    int maxi = nums[0];
    int i, j;
    int sum = 0;
    int index = 0;
    vector<int> index2;
    for (i = 0; i < n; i++) {
        sum += nums[i];
        if (sum >= maxi) {
            index = i; //finding index to end for second array
            maxi = sum;
        }
    }
    if (sum > 0 && k > 1) {   //using index to end for second array and index to start for first 
        int s = 0, i2 = -2, imx = sum, s1 = sum;
        sum *= (k - 1);  //multiplying k-1 times exvcuding 1st array
        for (i = index + 1; i < n; i++) { //using index to end for second array
            sum -= nums[i];  //subtracting after values of index1
        }

        for (i = 0; i < n; i++) {  //checking for sum from where to start and excluding first few elements
            s += nums[i];
            if (s1 - s > imx) {
                imx = s1 - s;  //getting max value excluding first i elements
            }
        }
        sum += imx;
        if (sum < 0) return 0;
        return sum;
    } else { //using kadane for atmost 2 concatenated array
        int max_till_now = 0, max_so_far = 0;
        if (k > 1) {
            k = 2;
        }
        for (i = 0; i < k * n; i++) {
            max_till_now += nums[i % n];
            if (max_till_now > max_so_far) {
                max_so_far = max_till_now;
            } else if (max_till_now < 0) {
                max_till_now = 0;
            }
        }
        return max_so_far;
    }
}

//[1,3,-100,1,2] 3
//[-1,3,-1,-1,-2] 3
