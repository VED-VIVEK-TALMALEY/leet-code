class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sq(n);
        for (int i = 0; i < n; i++) {
            sq[i] = 1LL * nums[i] * nums[i];
        }
        
        sort(sq.begin(), sq.end());
        
        int subtract_count = n / 2;
        long long sum = 0;
        
        // Smallest elements are subtracted
        for (int i = 0; i < subtract_count; i++) {
            sum -= sq[i];
        }
        
        // Largest elements are added
        for (int i = subtract_count; i < n; i++) {
            sum += sq[i];
        }
        
        return sum;
    }
};