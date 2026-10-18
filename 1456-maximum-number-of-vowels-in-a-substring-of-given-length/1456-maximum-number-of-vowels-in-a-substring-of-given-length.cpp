class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int current_vowels = 0, max_vowels = 0;
        
        // Count vowels for the first window
        for (int i = 0; i < k; ++i) {
            if (isVowel(s[i])) current_vowels++;
        }
        max_vowels = current_vowels;
        
        // Slide the window across the rest of the string
        for (int i = k; i < s.length(); ++i) {
            if (isVowel(s[i])) current_vowels++;     // Add incoming char
            if (isVowel(s[i - k])) current_vowels--; // Remove outgoing char
            
            max_vowels = max(max_vowels, current_vowels);
            if (max_vowels == k) return k; // Early exit optimization
        }
        
        return max_vowels;
    }
};