class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> opening_indices;
        string res = "";

        for (char c : s) {
            if (c == '(') {
                opening_indices.push_back(res.length());
            } else if (c == ')') {
                int start = opening_indices.back();
                opening_indices.pop_back();
                reverse(res.begin() + start, res.end());
            } else {
                res.push_back(c);
            }
        }

        return res;
    }
};