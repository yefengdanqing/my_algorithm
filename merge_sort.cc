#include"common.h"

void Merge(vector<int>& nums,int l,int m,int r)
{
	const int len1=m-l+1;
	const int len2=r-m;
	vector<int> tmp1(len1+1,0);
	vector<int>	tmp2(len2+1,0);
	for(int i=0;i<len1;i++)
		tmp1[i]=nums[l+i];
	tmp1[len1]=INT_MAX;
	for(int i=0;i<len2;i++)
		tmp2[i]=nums[m+1+i];
	tmp2[len2]=INT_MAX;
	int i=0,j=0;
	for(int k=l;k<=r;k++)
	{
		if(tmp1[i]<=tmp2[j])
			nums[k]=tmp1[i++];
		else
			nums[k]=tmp2[j++];
	}	
}
void MergeSort(vector<int>& vect,int start,int end)
{
	if(start<end){
		int mid=(end+start)/2;
		MergeSort(vect,start,mid);
		MergeSort(vect,mid+1,end);
		Merge(vect,start,mid,end);
	}
}
int main()
{
	vector<int> array={3,1,2,5,4,6,9,7,10,8};
	int len=array.size();
	MergeSort(array,0,len-1);
	for(auto x: array)
		cout<<x<<" ";
}
