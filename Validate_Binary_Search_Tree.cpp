//Time Complexity: O(N)
//Space Complexity: O(N)

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validBST(root, LONG_MIN, LONG_MAX);
    }

public:
    bool validBST(TreeNode* root, long long min, long long max) {
        if(root == NULL) return true;

        if(root->val <= min || root->val >= max) return false;

        return validBST(root->left, min, root->val) && validBST(root->right, root->val, max);
    }
};