class Solution {
public:
    int FindSubArray(vector<int>& nums,int left,int right)
    {
        if(left==right)
            return nums[left];
        int mid=(left+right)/2;
        
        int leftmax=FindSubArray(nums,left,mid);
        int rightmax=FindSubArray(nums,mid+1,right);
        int leftsum=nums[mid];
        int sum=nums[mid];
        for(int i=mid-1;i>=left;i--)
        {
            sum+=nums[i];
            if(sum>leftsum)
                leftsum=sum;
        }
        int rightsum=nums[mid+1];
        sum=nums[mid+1];
        for(int i=mid+2;i<=right;i++)
        {
            sum+=nums[i];
            if(sum>rightsum)
                rightsum=sum;
        }
        return max(max(leftmax,rightmax),leftsum+rightsum);
    }
    int maxSubArray(vector<int>& nums) {
        int sum_max=INT_MIN,sum=0;
        int len=nums.size();
        if(len<=0)
            return 0;
        /*for(int i=0;i<len;i++)
        {
            sum=0;
            for(int j=i;j<len;j++)
            {
                
                sum+=nums[j];
                
                if(sum>sum_max)
                {
                    sum_max=sum;
                }
               
            }
        }*/
        /*for(int i=0;i<len;i++)
        {
            sum+=nums[i];
            if(sum>sum_max)
            {
                sum_max=sum;
            }
            if(sum<0)
            {
                sum=0;
            }
        }*/
        /*for(int i=0;i<len;i++)
        {
            sum=max(sum+nums[i],nums[i]);
            if(sum>sum_max)
                sum_max=sum;
        }*/
        /*for(int i=0;i<len;i++)
        {
            if(sum<0)
            {
                sum=nums[i];
            }else
            {
                sum+=nums[i];
            }
            if(sum>sum_max)
                sum_max=sum;
        }
        return sum_max;*/
        return FindSubArray(nums,0,nums.size()-1);
    }
};
