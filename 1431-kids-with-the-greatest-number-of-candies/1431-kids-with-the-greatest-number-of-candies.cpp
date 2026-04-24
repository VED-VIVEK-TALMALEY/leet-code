class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector <bool> results ; 
       int annn=*max_element(candies.begin(),candies.end());
       int len = candies.size();
       for (int i = 0 ;i<len ;i++){
        if (candies[i]+extraCandies>=annn){
            results.push_back(true);
        }
        else {
             results.push_back(false);
        }
        cout << results[i];
       }
        return results ;
    }
};