//Time Complexity: O(N)
//Space Complexity: O(N)

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPath(root, maxi);
        return maxi;
    }

    int maxPath(TreeNode* node, int &maxi) {
        if (node == nullptr)
            return 0;
        int left = max(0, maxPath(node->left, maxi));
        int right = max(0, maxPath(node->right, maxi));

        maxi = max(maxi, left + right + node->val);

        return max(left, right) + node->val;
    }
};