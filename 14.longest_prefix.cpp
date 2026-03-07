#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Handle edge case: empty array means no common prefix
        if (strs.empty()) return "";
        
        // Start with first string as candidate prefix
        string prefix = strs[0];
        
        // Compare prefix with each remaining string starting from index 1
        for (int i = 1; i < strs.size(); i++) {
            // Keep shortening prefix until it matches start of current string
            // OR prefix becomes empty (no common prefix exists)
            while (prefix.empty() || strs[i].find(prefix) != 0) {
                // Remove last character from prefix
                prefix = prefix.substr(0, prefix.length() - 1);
                
                // If prefix is now empty, no common prefix exists
                if (prefix.empty()) return "";
            }
        }
        // All strings share this prefix
        return prefix;
    }
};
