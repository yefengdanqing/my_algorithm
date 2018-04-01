class Solution {
public:
    void TreePahts(TreeNode* root,string tmp,vector<string>& result)
    {
         if(root->left==NULL&& root->right==NULL)
        {
            result.push_back(tmp);
            return;
        }
        if(root->left!=NULL)TreePahts(root->left,tmp+"->"+to_string(root->left->val),result);
        if(root->right!=NULL)TreePahts(root->right,tmp+"->"+to_string(root->right->val),result); 
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string tmp;
        vector<string> result;
        if(root!=NULL)
        {
            tmp=to_string(root->val);
            TreePahts(root,tmp,result);
        }
        return result;
        
    }
};
//在遍历前后需要之前的信息，由于之前的值已经遍历过了，可以通过参数传值，有时候也得借助引用
