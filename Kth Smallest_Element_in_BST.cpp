//Time Complexity: O(N)
//Space Complexity: O(1)

class Solution {
public:
    void kthSmallestTree(TreeNode* root, int& count, int& result, int k) {
        if(root == NULL) return;

        kthSmallestTree(root->left, count, result, k);
        count++;
        if(count == k) {
            result = root->val;
            return;
        }
        kthSmallestTree(root->right, count, result, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result = 0;
        kthSmallestTree(root, count, result, k);
        return result;
    }
};