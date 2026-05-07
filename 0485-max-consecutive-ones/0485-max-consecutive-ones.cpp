class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = nums.size();
        int count =0 ; 
        int i = 0 ; 
        int j = 0 ;
        int sum =0 ; 
        
        for (int v = 0 ; v < len ; v++){
            if(nums[v]!=0){
                sum +=1;
            }
            else{
                count = max(count,sum);
                sum = 0 ;
                

            }
        }
        

        return max(count,sum);
          
    }
  
};