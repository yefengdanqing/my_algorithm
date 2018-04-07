#include"../leetcode/common.h"
int CutBar_Re(vector<int> nums,int n)
{
	if(n==0)
		return 0;
	int max_pro=INT_MIN;

	for(int i=1;i<=n;i++)
	{
		max_pro=max(max_pro,CutBar_Re(nums,n-i)+nums[i]);
	}
	return max_pro;

}
int CutBar_Dp(vector<int>& nums)
{
	int len=nums.size();
	vector<int> result(len,0);
	int max_pro=INT_MIN;
	for(int i=1;i<len;i++)
	{
		max_pro=nums[i];
		for(int j=0;j<i;j++)
		{
			max_pro=max((result[j]+result[i-j]),max_pro);
		}
		result[i]=max_pro;
	}
	return result[len-1];

}
int main()
{
	
	vector<int> nums={0,1,5,8,9,10,17,17,20,24,30};
	cout<<CutBar_Dp(nums)<<endl;
	vector<int> nums1={1,5,8,9,10,17,17,20,24,30};
	int n=nums1.size();
	cout<<CutBar_Re(nums,n)<<endl;
	
}
