class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        vector<int> diff1, diff2;
        
        for (int num : set1) {
            if (set2.count(num) == 0) {
                diff1.push_back(num);
            } else {
                set2.erase(num); 
            }
        }
        
        for (int num : set2) {
            diff2.push_back(num);
        }
        
        return {diff1, diff2};
    }
};