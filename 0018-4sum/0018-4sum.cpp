class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;
      
        // Need at least 4 numbers to form a quadruplet
        if (n < 4) {
            return result;
        }
      
        // Sort the array to enable two-pointer technique
        sort(nums.begin(), nums.end());
      
        // First number: iterate through possible values
        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicate values for the first number
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
          
            // Second number: iterate through possible values
            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicate values for the second number
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
              
                // Use two pointers for the remaining two numbers
                int left = j + 1;
                int right = n - 1;
              
                while (left < right) {
                    // Use long long to prevent integer overflow
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[left] + nums[right];
                  
                    if (sum < target) {
                        // Sum is too small, move left pointer to increase sum
                        ++left;
                    } else if (sum > target) {
                        // Sum is too large, move right pointer to decrease sum
                        --right;
                    } else {
                        // Found a valid quadruplet
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                      
                        // Move both pointers and skip duplicates
                        ++left;
                        --right;
                      
                        // Skip duplicate values for the third number
                        while (left < right && nums[left] == nums[left - 1]) {
                            ++left;
                        }
                      
                        // Skip duplicate values for the fourth number
                        while (left < right && nums[right] == nums[right + 1]) {
                            --right;
                        }
                    }
                }
            }
        }
      
        return result;
    }
};