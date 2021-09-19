Given a list of positive integers nums, find a minimum sum subsequence from the list such that at least one integer for all groups of three consecutive integers is picked. Note that if the length of nums is less than 3, a number should still be picked.

Constraints

    

    n ≤ 100,000 where n is length of nums

Example 1
Input

nums = [1, 2, 3, 4, 5, 6]

Output

5

Explanation

We can pick 1 and 4.

  //code
  

int solve(vector<int>& nums) {
      int n = nums.size();
    if (n <= 3) {
        return *min_element(nums.begin(), nums.end());
    }
    int first = nums[0], second = nums[1], third = nums[2], current = 0;
    for (int i = 3; i < n; i++) {
        current = nums[i] + min({first, second, third});//checking minimum of previous three
        first = second;
        second = third;
        third = current;
    }
    return min({first, second, third});
}
//case
//[1,3,0,0] 0
