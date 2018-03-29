class Solution {
public:
    bool is_judge(TreeNode* p,TreeNode* q)
    {
        if(p==NULL&&q==NULL)
            return true;
        if(p==NULL||q==NULL)
            return false;
        if(p->val==q->val)
            return is_judge(p->left,q->right)&&is_judge(p->right,q->left);
        else
            return false;
    }
        
    bool isSymmetric(TreeNode* root) {
        if(root!=NULL)
            return is_judge(root->left,root->right);
        return true;
       
        
    }
};
