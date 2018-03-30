class Solution {
public:
    bool is_same(TreeNode* s,TreeNode* t)
    {
        if( s==NULL &&t ==NULL)
            return true;
        
        if(s==NULL||t==NULL)  return false;
        if(t->val!=s->val)  return false;
        
        return is_same(s->left,t->left) && is_same(s->right,t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        //为空的是t补位空，
        if(s==NULL)
            return false;
        if(is_same(s,t))
        {
            return true;
        }
        return isSubtree(s->left,t)||isSubtree(s->right,t);
        
    }
};
