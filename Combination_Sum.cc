 void help(const vector<int>& candidates, int target,vector<int>& result,vector<vector<int>>& data,int pos)
    {
        if(target==0)
        {
            data.push_back(result);
            return;
        }
        //不能从0开始，不然会出现从后面的开始，然后选择了前面比较小的数的情况
        for(int i=pos;i<candidates.size();i++)
        {
            if(candidates[i]>target) break;
            result.push_back(candidates[i]);
            help(candidates,target-candidates[i],result,data,i);
            //对于当前不管是否满足都要删掉，保证回溯到上一个状态。
            result.pop_back();
        }
    
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int len=candidates.size();
        if(len==0)
            return {};
        sort(candidates.begin(),candidates.end());
        vector<int> result;
        vector<vector<int>> data;
        help(candidates,target,result,data,0);
        return data;
        
    }
//元素不可重复利用
class Solution {
public:
    void help(const vector<int>& candidates, int target,vector<int>& result,vector<vector<int>>& data,int pos)
    {
        if(target<0)
            return;
        else if(target==0)
        {
            data.push_back(result);
            return;
        }else{
        //不能从0开始，不会出现从后面的开始，然后选择了前面比较小的数
        for(int i=pos;i<candidates.size();i++)
        {
            //处理当前元素与前一个重复，前一个元素的情况以后列举，不需要重复考虑
            if(i>pos&&candidates[i]==candidates[i-1]) continue;
            result.push_back(candidates[i]);
            //递归的元素起始位置，
            help(candidates,target-candidates[i],result,data,i+1);
            result.pop_back();
        }
        }
    
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int len=candidates.size();
        if(len==0)
            return {};
        
        sort(candidates.begin(),candidates.end());
        
        vector<int> result;
        vector<vector<int>> data;
        help(candidates,target,result,data,0);
        return data;
        
    }
};
