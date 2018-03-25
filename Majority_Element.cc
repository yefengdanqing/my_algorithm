class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len=nums.size();
        if(len==0)
            return 0;
        int count=0,k=nums[0];
        for(int i=1;i<len;i++)
        {
            if(k==nums[i])
            {
                count++;
            }else
            {
                if(count>0)
                    count--;
                else
                    k=nums[i];
            }
        }
        return k;
        
    }
};
