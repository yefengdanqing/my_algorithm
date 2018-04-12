 void help(const vector<int>& candidates, int target,vector<int>& result,vector<vector<int>>& data,int pos)
    {
        if(target==0)
        {
            data.push_back(result);
            return;
        }
        //不能从0开始，不会出现从后面的开始，然后选择了前面比较小的数
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
