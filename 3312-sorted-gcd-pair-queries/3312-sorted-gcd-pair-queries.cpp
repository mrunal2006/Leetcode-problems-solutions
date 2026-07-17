class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        vector<long long> gcdCnt(mx + 1, 0);

        // Count pairs having exact gcd = i
        for (int i = mx; i >= 1; i--) {
            long long cnt = 0;

            for (int j = i; j <= mx; j += i) {
                cnt += freq[j];
                gcdCnt[i] -= gcdCnt[j];
            }

            gcdCnt[i] += cnt * (cnt - 1) / 2;
        }

        // Prefix sum
        for (int i = 2; i <= mx; i++)
            gcdCnt[i] += gcdCnt[i - 1];

        vector<int> ans;

        for (long long q : queries) {
            int idx = upper_bound(gcdCnt.begin(), gcdCnt.end(), q) - gcdCnt.begin();
            ans.push_back(idx);
        }

        return ans;
    }
};