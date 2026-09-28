class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        
        int len = s.length();
        for (int z = 0; z < len; z++) {
            if (s == goal) return true;
            
            char temp = s[0];
            for (int i = 0; i < len - 1; i++) {
                s[i] = s[i + 1];
            }
            s[len - 1] = temp;
        }
        
        return false;
    }
};