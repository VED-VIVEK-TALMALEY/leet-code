class Solution {
public:
    string removeStars(string s) {
        string resu="";
        for (char c :s ){
            if (c =='*'&&!resu.empty()){
            resu.pop_back();

            }
            else {
                resu.push_back(c);
            }
        }
        return resu;
    }
};