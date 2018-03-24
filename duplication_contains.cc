class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len=nums.size();
        if(len==0)
            return false;
        unordered_map<int,int> hash;
        unordered_map<int,int>::iterator it;
      
        for(int i=0;i<len;i++)
        {
            it=hash.find(nums[i]);
            if(it!=hash.end())
            {
                return true;
            }
            hash[nums[i]]=1;
        }
        return false;
        
    }
};
