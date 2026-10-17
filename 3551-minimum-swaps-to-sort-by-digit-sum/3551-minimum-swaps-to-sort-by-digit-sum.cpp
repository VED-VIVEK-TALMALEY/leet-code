class Solution {
public:
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        // Stores {{digit_sum, original_value}, original_index}
        vector<pair<pair<int, int>, int>> arr(n);
        
        for (int i = 0; i < n; ++i) {
            arr[i] = {{getDigitSum(nums[i]), nums[i]}, i};
        }
        
        // Sorts primarily by digit_sum, secondarily by original_value
        sort(arr.begin(), arr.end());
        
        vector<bool> visited(n, false);
        int swaps = 0;
        
        for (int i = 0; i < n; ++i) {
            // If already visited or already in the correct position
            if (visited[i] || arr[i].second == i) {
                continue;
            }
            
            int cycle_size = 0;
            int j = i;
            
            // Traverse the cycle
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].second;
                cycle_size++;
            }
            
            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }
        
        return swaps;
    }
};