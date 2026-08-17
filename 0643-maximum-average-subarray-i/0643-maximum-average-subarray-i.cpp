class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int current_sum = 0;
        for (int i = 0; i < k; i++) {
            current_sum += nums[i];
        }
        
        int max_sum = current_sum;
        for (int i = k; i < nums.size(); i++) {
            current_sum += nums[i] - nums[i - k];
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
        
        return (double)max_sum / k;
    }
};