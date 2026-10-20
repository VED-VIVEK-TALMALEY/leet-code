#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> s = nums;
        sort(s.begin(), s.end());
        
        vector<int> divisors;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i * i != n) {
                    divisors.push_back(n / i);
                }
            }
        }
        
        int total_sum = 0;
        
        for (int k : divisors) {
            bool sortable = true;
            for (int b = 0; b < n / k; ++b) {
                int start = b * k;
                
                // Build the KMP pi array for the target pattern (the sorted block)
                vector<int> pi(k, 0);
                int j = 0;
                for (int i = 1; i < k; ++i) {
                    while (j > 0 && s[start + i] != s[start + j]) {
                        j = pi[j - 1];
                    }
                    if (s[start + i] == s[start + j]) {
                        j++;
                    }
                    pi[i] = j;
                }
                
                // Search for the sorted block pattern within the concatenated original block
                j = 0;
                bool match = false;
                for (int i = 0; i < 2 * k - 1; ++i) {
                    int current_val = nums[start + (i % k)];
                    while (j > 0 && current_val != s[start + j]) {
                        j = pi[j - 1];
                    }
                    if (current_val == s[start + j]) {
                        j++;
                    }
                    if (j == k) {
                        match = true;
                        break;
                    }
                }
                
                if (!match) {
                    sortable = false;
                    break;
                }
            }
            if (sortable) {
                total_sum += k;
            }
        }
        
        return total_sum;
    }
};