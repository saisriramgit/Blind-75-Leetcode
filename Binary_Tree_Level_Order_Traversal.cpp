//Time Complexity: O(N)
//Space Complexity: O(N)

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int levelSize = q.size();
            vector<int> currLevel;
            for(int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                currLevel.push_back(node->val);
                if(node->left != NULL) {
                    q.push(node->left);
                }
                    
                if(node->right != NULL) {
                    q.push(node->right);
                }
            }
            result.push_back(currLevel);
        }
        return result;
    }
};