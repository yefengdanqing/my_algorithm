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
        /*if(root!=NULL)
            return is_judge(root->left,root->right);
        return true;*/
        if(root==NULL)
            return true;
        if(root->right==NULL&&root->left==NULL)
            return true;
        if(root->right==NULL||root->left==NULL)
            return false;
        deque<TreeNode*> dq;
        dq.push_back(root->right);
        dq.push_front(root->left);
        
        TreeNode* lroot=NULL;
        TreeNode* rroot=NULL;
        
        while(!dq.empty())
        {
            lroot=dq.front();
            rroot=dq.back();
            dq.pop_front();
            dq.pop_back();
            if(lroot->val!=rroot->val)
            {
                return false;
            }
            if((lroot->left!=NULL&&rroot->right==NULL)||(lroot->left==NULL&&rroot->right!=NULL))   return false;
           
            if(lroot->left)
            {
                dq.push_front(lroot->left);
                dq.push_back(rroot->right);
            }
             if((lroot->right!=NULL&&rroot->left==NULL)||(lroot->right==NULL&& rroot->left!=NULL))   return false;
             if(rroot->left)//注意入队列的不是节点本身
            {
                dq.push_front(lroot->right);
                dq.push_back(rroot->left);
            }
            
        }
        return true;
        
       
       
        
    }
};
