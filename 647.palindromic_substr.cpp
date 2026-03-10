#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;  // Total palindromic substrings
        
        // Try every position as center
        for (int center = 0; center < n; center++) {
            // ODD length palindromes (center = single char)
            count += expandAroundCenter(s, center, center);
            
            // EVEN length palindromes (center = between two chars)
            count += expandAroundCenter(s, center, center + 1);
        }
        
        return count;
    }
    
private:
    // Helper: Expand from left,right while chars match
    // Returns number of palindromes found from this center
    int expandAroundCenter(string& s, int left, int right) {
        int count = 0;
        
        // While valid indices AND chars match
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;      // Found 1 palindrome
            left--;       // Expand left
            right++;      // Expand right
        }
        
        return count;
    }
};
