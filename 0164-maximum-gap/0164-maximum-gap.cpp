class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int len=nums.size();
        if (len<2)
        return 0;
        sort(nums.begin(),nums.end());
        int depletion =0 ;
        int max_depletion = 0 ; 
        int i = 0;
        

        while (i<len-1){
        depletion=nums[i+1]-nums[i];
        if(max_depletion<depletion)
         max_depletion=depletion; 

        ++i;
        }
        return max_depletion;   
    }
};