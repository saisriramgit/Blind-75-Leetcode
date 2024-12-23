//Time Complexity: O(N)
//Space Complexity: O(N)

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        TreeNode* root = buildTrees(preorder, 0, preorder.size() - 1, inorder, 0, 
        inorder.size() - 1, mp);
        return root;
    }

public:
    TreeNode* buildTrees(vector<int>& preorder, int preStart, int preEnd,
        vector<int>& inorder, int inStart, int inEnd, map<int, int>& mp) {
            if(preStart > preEnd || inStart > inEnd) return NULL;

            TreeNode* root = new TreeNode(preorder[preStart]);

            int inRoot = mp[root->val];
            int numsLeft = inRoot - inStart;

            root->left = buildTrees(preorder, preStart + 1, preStart + numsLeft, inorder,
            inStart, inRoot - 1, mp);
            root->right = buildTrees(preorder, preStart + numsLeft + 1, preEnd, inorder,
            inRoot + 1, inEnd, mp);

            return root;
        }
};