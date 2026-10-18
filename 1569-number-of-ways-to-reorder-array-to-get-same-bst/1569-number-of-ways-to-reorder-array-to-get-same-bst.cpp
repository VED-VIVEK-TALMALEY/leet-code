class Solution {
    long long MOD = 1e9 + 7;
    vector<vector<long long>> table;
    
    long long dfs(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1; // Base case: arrays of length 0, 1, or 2 have only 1 valid ordering
        
        vector<int> left, right;
        int root = nums[0];
        
        // Split into left and right subtrees based on the root
        for (int i = 1; i < n; ++i) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }
        
        // Calculate the number of ways for left and right subtrees
        long long left_ways = dfs(left) % MOD;
        long long right_ways = dfs(right) % MOD;
        
        // Interleave the left and right elements: combinations of (left.size() + right.size()) choose left.size()
        long long ways = table[n - 1][left.size()];
        ways = (ways * left_ways) % MOD;
        ways = (ways * right_ways) % MOD;
        
        return ways;
    }
    
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        
        // Precompute combinations (Pascal's triangle) modulo 1e9 + 7
        table.resize(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            table[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % MOD;
            }
        }
        
        // Subtract 1 at the end to exclude the original array itself
        return (dfs(nums) - 1 + MOD) % MOD;
    }
};