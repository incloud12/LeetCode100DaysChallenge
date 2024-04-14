class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return !root ? 0 : (root->left && !root->left->left && !root->left->right ? root->left->val : 0) + 
                           sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
}; 
