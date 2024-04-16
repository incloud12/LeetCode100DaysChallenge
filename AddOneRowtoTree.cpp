class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth == 1)
            return new TreeNode(val, root, NULL);

        if(depth > 2)
        {
            if(root->left) root->left = addOneRow(root->left, val, depth - 1);
            if(root->right) root->right = addOneRow(root->right, val, depth - 1);

            return root;
        }
        else
        {
            root->left = new TreeNode(val, root->left, NULL);
            root->right = new TreeNode(val, NULL, root->right);
            return root;
        }

    }
};
