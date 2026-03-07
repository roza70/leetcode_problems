#include <vector>
#include <algorithm>  // for std::swap, std::reverse
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Find pivot (rightmost i where nums[i] < nums[i+1])
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        // If pivot found
        if (i >= 0) {
            // Step 2: Find rightmost successor > nums[i]
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            // Swap pivot with successor
            swap(nums[i], nums[j]);
        }
        
        // Step 3: Reverse suffix after pivot (or whole if no pivot)
        reverse(nums.begin() + i + 1, nums.end());
    }
};
