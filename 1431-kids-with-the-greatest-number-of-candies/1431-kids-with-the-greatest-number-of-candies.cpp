class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector <bool> results ; 
       int annn=*max_element(candies.begin(),candies.end());
       results.reserve(candies.size());
       for (int i :candies){
        
            results.push_back(i+extraCandies>=annn);
       }
        return results ;
    }
};