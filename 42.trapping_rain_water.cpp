class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;                           // Left pointer starts at array beginning
        int right = height.size() - 1;          // Right pointer starts at array end
        
        int total = 0;                          // Accumulates trapped water volume
        int leftMax = height[0];                // Max height seen from left side
        int rightMax = height[right];           // Max height seen from right side
        
        while (left < right) {                  // Continue until pointers meet
            if (height[left] < height[right]) { // Process shorter side first (left)
                leftMax = max(leftMax, height[left]);  // Update left max
                if (leftMax - height[left] > 0) {      // If water can be trapped
                    total += leftMax - height[left];   // Add trapped water
                }
                left++;                             // Move left pointer right
            } else {                            // Process right side
                rightMax = max(rightMax, height[right]); // Update right max
                if (rightMax - height[right] > 0) {     // If water can be trapped
                    total += rightMax - height[right];  // Add trapped water
                }
                right--;                            // Move right pointer left
            }
        }
        return total;                           // Return total trapped water
    }
};
