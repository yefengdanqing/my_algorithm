class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*int len=nums.size();
        if(len<=0)
            return 0;
        int pos=0;
        for(int i=1;i<len;i++)
        {
            
            if(nums[i]!=nums[pos])
            {
                nums[pos+1]=nums[i];
                pos++;
            }
        }
        return pos+1;*/
        if(nums.empty())
            return 0;
       vector<int>::iterator it_start=nums.begin();
        //在删除之后尤其注意尾后迭代器也是变化，要重新获取,考虑用remove
        while(it_start!=(nums.end()-1))
        {
			if(*it_start == *(it_start+1))
            {
                it_start=nums.erase(it_start+1);
				--it_start;
            }else
            {
                it_start++;
            }
	
        }
        return nums.size();   
        
    }
};
