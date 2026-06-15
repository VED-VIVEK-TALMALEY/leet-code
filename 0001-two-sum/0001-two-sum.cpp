class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len  = nums.size();
        vector<int> result;
        result.reserve(2); 
        int a =0,b=0;
        for (int i=0;i<len; i++  ){
            a =nums[i];
            for (int j=i+1;j<len;j++){
                b = nums[j];
                if (target-a==b){
                result.push_back(i);
                result.push_back(j);
                break ;
                }
            }

        }
        return result;
    }

};