//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while(left < right) {
            maxArea = max(maxArea, (right - left) * min(height[left], height[right]));
            if(height[left] < height[right]) {
                left++;
            } else if(height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }
        return maxArea;
    }
};