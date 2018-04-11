class Solution {
public:
    void helper(vector<string>& result,int left,int right,string s)
    {   
        if(left>right)
        //思考这个条件的限制于整个
        
            return;
        if(left==0&&right==0)
        {
            result.push_back(s);
            return;
        }
        if(left>0)
            helper(result,left-1,right,s+'(');
        if(right>0)
            helper(result,left,right-1,s+')');
       /* if(left<right)
            return;
        if(left==n&&right==n)
        {
            result.push_back(s);
        }
        if(left<n)
            helper(result,left+1,right,s+'(',n);
        if(right>n)
            helper(result,left,right+1,s+'(',n);*/
            
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n==0)
          return result;
        helper(result,0,0,"");
        return result;
    }
};
