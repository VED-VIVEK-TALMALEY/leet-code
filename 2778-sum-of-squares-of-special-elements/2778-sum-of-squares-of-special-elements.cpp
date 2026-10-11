class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        long long mul_sum = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                mul_sum += (long long)(nums[i - 1] * nums[i - 1]);
            }
        }
        return mul_sum;
    }
};