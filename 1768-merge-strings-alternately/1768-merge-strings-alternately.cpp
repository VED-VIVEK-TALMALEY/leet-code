class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int n1 = word1.length();
        int n2 = word2.length();
        for (int i = 0; i < max(n1, n2); i++) {
            if (i < n1) result += word1[i]; 
        if (i < n2) result += word2[i]; 
        }
        
        return result;
    }
};