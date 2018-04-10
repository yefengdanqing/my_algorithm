// Lowest Common Ancestor of a Binary Search Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//有错
class Solution {
public:
    int FindCountNode(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL)
            return 0;
        if(root==p||root==q)
            return 1;
        else
            return FindCountNode(root->left,p,q)+FindCountNode(root->right,p,q);
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(FindCountNode(root->left,p,q)==2)
            return lowestCommonAncestor(root->left,p,q);
        else if(FindCountNode(root->right,p,q)==2)
            return lowestCommonAncestor(root->right,p,q);
        else
            return root;
        
        
    }
};
