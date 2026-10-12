class Solution {
public:
   const int MOD = 1e9 + 7;

int maxSum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> bitcnt(31, 0);

    // 1. count frequency of each bit
    for (int x : nums)
        for (int b = 0; b <= 30; b++)
            if (x & (1 << b))
                bitcnt[b]++;

    // 2. build the largest possible numbers
    vector<long long> vals(n, 0);
    for (int b = 30; b >= 0; b--) {
        int cnt = bitcnt[b];
        for (int i = 0; i < n && cnt > 0; i++, cnt--)
            vals[i] |= (1LL << b);
    }

    // 3. sum of squares of the k largest
    long long ans = 0;
    for (int i = 0; i < k; i++) {
        ans = (ans + vals[i] * vals[i]) % MOD;
    }
    return ans;
}
};