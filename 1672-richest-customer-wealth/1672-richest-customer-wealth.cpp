class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        
        for (const auto& customer : accounts) {
            int currentSum = 0;
            for (int money : customer) {
                currentSum += money;
            }
            
            if (currentSum > maxWealth) {
                maxWealth = currentSum;
            }
        }
        
        return maxWealth;
    }
};