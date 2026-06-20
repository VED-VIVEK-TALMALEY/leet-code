class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        // 1. Add essential constraints
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());
        
        // Ensure the last building is accounted for if not present
        if (restrictions.back()[0] != n) {
            restrictions.push_back({n, n - 1 + restrictions.back()[1] - (restrictions.back()[0] - 1)}); 
            // Actually, just add {n, n-1} and let the backward pass handle it
            restrictions.push_back({n, n - 1});
        }
        
        int k = restrictions.size();
        
        // 2. Forward Pass: h[i] = min(h[i], h[i-1] + dist)
        for (int i = 1; i < k; ++i) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i-1][1] + (restrictions[i][0] - restrictions[i-1][0]));
        }
        
        // 3. Backward Pass: h[i] = min(h[i], h[i+1] + dist)
        for (int i = k - 2; i >= 0; --i) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i+1][1] + (restrictions[i+1][0] - restrictions[i][0]));
        }
        
        // 4. Calculate Max Height between segments
        int maxHeight = 0;
        for (int i = 0; i < k - 1; ++i) {
            int id1 = restrictions[i][0], h1 = restrictions[i][1];
            int id2 = restrictions[i+1][0], h2 = restrictions[i+1][1];
            
            // Formula for peak between two points
            int localMax = (h1 + h2 + (id2 - id1)) / 2;
            maxHeight = max(maxHeight, localMax);
        }
        
        return maxHeight;
    }
};