class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res1 ;
        int i = 0 ;
        for(i=0; i<n;i++){
     res1.push_back(nums[i]);
     res1.push_back(nums[i+n]);
        }
        
           return res1;
    }
};