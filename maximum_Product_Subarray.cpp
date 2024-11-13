//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod = 1;
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            prod *= nums[i];
            maxi = max(prod, maxi);
            if(prod == 0)
                prod = 1;
        }
        prod = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            prod *= nums[i];
            maxi = max(prod, maxi);
            if(prod == 0)
                prod = 1;
        }
        return maxi;
    }
};