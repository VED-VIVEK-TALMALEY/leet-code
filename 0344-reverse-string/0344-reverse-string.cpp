class Solution {
public:
    void reverseString(vector<char>& s) {
        char a ; 
        char b ; 
int len = s.size()/2;
        for (int num = 0 ;num <len; num++ ){
        
            swap(s[num],s[s.size()-1-num]);

        } 
        
    }
};