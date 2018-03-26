class Solution {
public:
    int binary_search(vector<int>& numbers,int value,int index)
    {
        int low=index,high=numbers.size()-1;
        int middle=0;
        while(low<=high)
        {
            middle=low+(high-low)/2;
            if(numbers[middle]==value)
            {
                return middle;
            }else if(numbers[middle]>value)
            {
            //尤其注意下标计算，防止发生死循环
                high=middle-1;
            }else if(numbers[middle]<value)
            {
            //尤其注意下标计算，防止发生死循环
                low=middle+1;
            }
        }
        return -1;    
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len=numbers.size();
        vector<int> tmp(2,0);
        if(len<=0)
            return tmp;
        int index1=0,index2=0;
        for(int i=0;i<len;i++)
        {
            index1=i+1;
            int ret=binary_search(numbers,target-numbers[i],i+1);
            if(ret!=-1)
            {
                index2=ret+1;
                break;
            }   
        }
        tmp[0]=index1<index2?index1:index2;
        tmp[1]=index1>index2?index1:index2;
        return tmp; 
    }
     vector<int> twoSum(vector<int>& numbers, int target) {
        int len=numbers.size();
        if(len<=0)
            return {};
        int i=0,j=len-1;
        int t;
        while(i<=j)
        {
            t=numbers[i]+numbers[j];
            if(t>target)
            {
                --j;
            }else if(t<target)
            {
                ++i;
            }else if (t==target)
            {
                return {i+1,j+1};
            }
        }
        
    }
};
