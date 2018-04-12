class Solution {
public:
    void help(const vector<int>& nums,vector<bool>& cur,vector<vector<int>>& result, vector<int> tmp)
    {
        if(tmp.size()==nums.size())
        {
            result.push_back(tmp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(cur[i]==false)
            {
                tmp.push_back(nums[i]);
                cur[i]=true;
                help(nums,cur,result,tmp);
                cur[i]=false;
                tmp.pop_back();
            }
        }
    }
    
    void PermuteRecursive(vector<int>& nums,int begin,vector<vector<int>>& result)
    {
        if(begin>=nums.size())
        {
            result.push_back(nums);
            return;
        }
        for(int i=begin;i<nums.size();i++)
        {
            swap(nums[i],nums[begin]);
            PermuteRecursive(nums,begin+1,result);
            swap(nums[i],nums[begin]);
        }
    }
        
    vector<vector<int>> permute(vector<int>& nums) {
        int len=nums.size();
        if(len<=0)
            return {};
        vector<vector<int>> result;
        vector<int> tmp;
        vector<bool> cur(nums.size(),false);
        //help(nums,cur,result,tmp);
        PermuteRecursive(nums,0,result);
        return result;
        
    }
};
