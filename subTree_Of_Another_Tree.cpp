//Time Complexity: O(N)
//Space Complexity: O(N)

class Solution {
public:
    bool isSameTree(TreeNode* r, TreeNode* s) {
        if(r == nullptr && s == nullptr)
            return true;

        if(r == nullptr || s == nullptr)
            return false;

        if(r->val != s->val)
            return false;

        return isSameTree(r->left, s->left) && isSameTree(r->right, s->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == nullptr)
            return true;

        if(root == nullptr)
            return false;

        if(isSameTree(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};