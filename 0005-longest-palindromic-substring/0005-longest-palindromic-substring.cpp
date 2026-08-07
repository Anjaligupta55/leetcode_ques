class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        
        int start = 0, maxLen = 1;
        
        // Helper function to expand around the center
        auto expandFromCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            // Update the longest palindrome found
            if (right - left - 1 > maxLen) {
                maxLen = right - left - 1;
                start = left + 1;
            }
        };
        
        for (int i = 0; i < n; i++) {
            // Check for odd-length palindromes
            expandFromCenter(i, i);
            // Check for even-length palindromes
            expandFromCenter(i, i + 1);
        }
        
        return s.substr(start, maxLen);
    }
};