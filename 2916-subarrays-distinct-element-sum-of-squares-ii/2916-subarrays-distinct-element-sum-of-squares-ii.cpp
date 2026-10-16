#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    struct Node {
        long long sum = 0;
        long long sum_sq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;
    int MOD = 1e9 + 7;

    void push(int node, int start, int end) {
        if (tree[node].lazy != 0) {
            int mid = start + (end - start) / 2;
            long long val = tree[node].lazy;
            long long len_left = mid - start + 1;
            long long len_right = end - mid;

            // Update left child
            tree[2 * node].sum_sq = (tree[2 * node].sum_sq + 2 * val * tree[2 * node].sum % MOD + val * val % MOD * len_left % MOD) % MOD;
            tree[2 * node].sum = (tree[2 * node].sum + val * len_left % MOD) % MOD;
            tree[2 * node].lazy = (tree[2 * node].lazy + val) % MOD;

            // Update right child
            tree[2 * node + 1].sum_sq = (tree[2 * node + 1].sum_sq + 2 * val * tree[2 * node + 1].sum % MOD + val * val % MOD * len_right % MOD) % MOD;
            tree[2 * node + 1].sum = (tree[2 * node + 1].sum + val * len_right % MOD) % MOD;
            tree[2 * node + 1].lazy = (tree[2 * node + 1].lazy + val) % MOD;

            tree[node].lazy = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, long long val) {
        if (start > r || end < l) return;
        if (start >= l && end <= r) {
            long long len = end - start + 1;
            tree[node].sum_sq = (tree[node].sum_sq + 2 * val * tree[node].sum % MOD + val * val % MOD * len % MOD) % MOD;
            tree[node].sum = (tree[node].sum + val * len % MOD) % MOD;
            tree[node].lazy = (tree[node].lazy + val) % MOD;
            return;
        }
        push(node, start, end);
        int mid = start + (end - start) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        
        tree[node].sum = (tree[2 * node].sum + tree[2 * node + 1].sum) % MOD;
        tree[node].sum_sq = (tree[2 * node].sum_sq + tree[2 * node + 1].sum_sq) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree.resize(4 * n + 1);
        unordered_map<int, int> last_pos;
        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            int left = 0;
            if (last_pos.count(nums[i])) {
                left = last_pos[nums[i]] + 1;
            }
            
            // Increment the distinct counts for intervals [left, i]
            update(1, 0, n - 1, left, i, 1);
            
            // Add the total sum of squares for subarrays ending at index i
            ans = (ans + tree[1].sum_sq) % MOD;
            
            last_pos[nums[i]] = i;
        }

        return ans;
    }
};