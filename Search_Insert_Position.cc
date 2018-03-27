class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       /* int len=nums.size();
        if(len==0)
            return -1;
        int low=0,right=len-1;
        int middle=0;
        while(low<right)
        {
            middle=(low+right)/2;
            if(nums[middle]==target)
                return middle;
            else if(nums[middle]>target)
            {
                right=middle;
                
            }if(nums[middle]<target)
            {
                low=middle+1;
            }
        }
        return low;*/
        if (nums.back() < target) return nums.size();
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return right;
        
    }
};
