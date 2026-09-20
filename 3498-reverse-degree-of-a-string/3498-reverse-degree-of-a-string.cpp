class Solution {
public:
    int reverseDegree(string s) {
        int pos[26];
        for (int i = 0; i < 26; ++i) {
            pos[i] = 26 - i;
        }

        int total = 0;
        for (int i = 0; i < s.length(); ++i) {
            total += pos[s[i] - 'a'] * (i + 1);
        }

        return total;
    }
};