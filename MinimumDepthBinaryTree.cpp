class Solution {
public:
    int minDepth(TreeNode* root) {

        static int level = 0;
       if (root == NULL)
            return level;
        level++;
   
        return min(minDepth(root->left),
                minDepth(root->right));
    }

};
