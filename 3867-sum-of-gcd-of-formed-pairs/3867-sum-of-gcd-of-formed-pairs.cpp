class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);

        int mx = 0;

        // Construct prefixGcd array
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(nums[i], mx);
        }

        // Sort the prefixGcd array
        sort(prefixGcd.begin(), prefixGcd.end());

        // Form pairs and calculate GCD sum
        long long ans = 0;
        for (int i = 0; i < n / 2; i++) {
            ans += gcd(prefixGcd[i], prefixGcd[n - 1 - i]);
        }

        return ans;
    }
};