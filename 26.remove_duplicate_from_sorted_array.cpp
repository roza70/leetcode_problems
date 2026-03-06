class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;         // Handle empty array
        
        int slow = 0;                       // Points to next position for unique element
        
        for (int fast = 1; fast < nums.size(); ++fast) {  // fast scans from index 1
            if (nums[fast] != nums[slow]) { // Found new unique value
                ++slow;                     // Move slow to next write position
                nums[slow] = nums[fast];    // Copy unique value to slow position
            }
            // Skip duplicates (fast keeps moving)
        }
        
        return slow + 1;                    // Number of unique elements
    }
};
