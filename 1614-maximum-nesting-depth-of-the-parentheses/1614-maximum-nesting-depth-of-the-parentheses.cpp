class Solution {
public:
    int maxDepth(string s) {
        int right_counter = 0 ; 
        int left_counter = 0 ; 
        int max_counter = 0 ; 
        int diff = 0;
        for (int i = 0 ; i <s.length(); i++){
            if (s[i]=='('){
            left_counter++;
            }
            else if (s[i]==')'){
            right_counter ++;
            }
            diff=left_counter-right_counter ; 
            if (diff >max_counter)
            max_counter = diff ; 
        }
        return max_counter ; 
    }
};