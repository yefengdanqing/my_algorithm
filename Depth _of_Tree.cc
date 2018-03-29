class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int depth_l = maxDepth(root->left);
        int depth_r = maxDepth(root->right);

        return  depth_l > depth_r  ? depth_l + 1:depth_r + 1;
        //这样写返回不了结果？？why？
       // return maxDepth(root->left)>maxDepth(root->right)?(maxDepth(root->left)+1):(maxDepth(root->right)+1);
        
        /*if(root!=NULL)
        {
            return (maxDepth(root->left)+1)>(maxDepth(root->right)+1)?(maxDepth(root->left)+1):(maxDepth(root->right)+1);
        }
        return 0;*/
        
    }
};
