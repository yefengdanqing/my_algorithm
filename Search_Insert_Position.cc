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
                right=middle-1;
                
            }if(nums[middle]<target)
            {
                low=middle+1;
            }
        }
        return low;*/
        
        
       /*  int low = 0, high = nums.size()-1;

        // Invariant: the desired index is between [low, high+1]
        while (low <= high) {
            int mid = low + (high-low)/2;

            if (nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
         return low;*/
        // (1) At this point, low > high. That is, low >= high+1
        // (2) From the invariant, we know that the index is between [low, high+1], so low <= high+1. Follwing from (1), now we know low == high+1.
        // (3) Following from (2), the index is between [low, high+1] = [low, low], which means that low is the desired index
        //     Therefore, we return low as the answer. You can also return high+1 as the result, since low == high+1
      
        
        
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
