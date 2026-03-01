class Solution {
public:
    int characterReplacement(string s, int k) {
        
        vector<int> occurrence(26, 0);
        int left = 0;
        int maxOccurrence = 0;
        int ans = 0;

        for(int right = 0; right < s.length(); right++) {
            
            maxOccurrence = max(maxOccurrence, ++occurrence[s[right] - 'A']);
            
            if((right - left + 1) - maxOccurrence > k) {
                occurrence[s[left] - 'A']--;
                left++;
            }
            
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};