class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT_MAX;
        int mid = INT_MAX;
        for (int n :nums ){
            if (n<=small){
                small=n ; 

            }
            else if (n<=mid){
                mid=n;
            }
            else {
                return true; 
            }
        }
        return false ;
        
    }
};