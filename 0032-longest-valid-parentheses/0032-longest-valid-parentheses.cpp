class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); 
        int maxLen = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    // Reset boundary if an unmatched ')' breaks continuity
                    st.push(i); 
                } else {
                    // Current valid length is current index minus top of stack
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }
};