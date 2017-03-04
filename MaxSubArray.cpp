// MaxSubArray.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <climits>
#include <iostream>
#include <ctime>

using namespace std;

struct MaxSubArray
{
	int data;
	int left;
	int right;	
};
vector<MaxSubArray> recursionresult,result;
//暴力
MaxSubArray FindMaxSubArray1(vector<int>& arr,int low,int high)
{
	MaxSubArray maxarray,temp;
	int i = 0, j = 0;
	int left_sum = 0, right_sum = 0;
	//int left_sum = INT_MIN, right_sum = INT_MIN;
	int sum = 0;
	for (i = low; i <= high; i++)
	{
		left_sum = INT_MIN, right_sum = INT_MIN;
		//左边
		sum = 0;
		for (j = i; j >=low; j--)
		{
			sum += arr[j];
			if (sum > left_sum)
			{
				left_sum = sum;
				temp.left = j;
			}
		}
		sum = 0;
		for (j = i; j <= high; j++)
		{
			sum += arr[j];
			if (sum > right_sum)
			{
				right_sum = sum;
				temp.right = j;
			}
		}
		temp.data = left_sum + right_sum - arr[i];
		result.push_back(temp);
	}
	int value = INT_MIN,ncount=0;
	for (int m = 0; m < result.size(); m++)
	{
		if (result[m].data > value)
		{
			value = result[m].data;
			ncount=m;
		}
	}
	return result[ncount];
}
//分治思想-递归
MaxSubArray FindCrossingSubArray(vector<int>& arr, int low, int mid, int high)
{
	int left_sum = INT_MIN, right_sum = INT_MIN,sum=0;
	sum = 0;
	MaxSubArray temp;
	for (int i = mid; i >= low; i--)
	{
		sum += arr[i];
		if (sum > left_sum)
		{
			temp.left = i;
			left_sum = sum;
		}
	}
	sum = 0;
	for (int j = mid + 1; j <= high; j++)
	{
		sum += arr[j];
		if (sum > right_sum)
		{
			temp.right = j;
			right_sum = sum;
		}
	}
	temp.data = left_sum + right_sum;
	return temp;
}
MaxSubArray FindMaxSubArray2(vector<int>& arr, int low, int high)
{
	MaxSubArray node,leftarr,rightarr,midarr;
	if (low == high)
	{
		node.data = arr[low];
		node.left = low;
		node.right = high;
		return node;
	}
	else
	{
		int mid = (low + high) / 2;
		leftarr = FindMaxSubArray2(arr, low, mid);
		rightarr = FindMaxSubArray2(arr, mid + 1, high);
		midarr = FindCrossingSubArray(arr, low,mid, high);
		if (leftarr.data >= rightarr.data&&leftarr.data >= midarr.data)
			return leftarr;
		else if (rightarr.data >= leftarr.data&&rightarr.data >= midarr.data)
			return rightarr;
		else
			return midarr;
	}
}

int main()
{
	vector<int> arr = { 0, 13, -3, -25, 20, -3, -16, -23, 18,
		20, -7, 12, -5, -22, 15, -4, 7 };
	vector<int> numvect;
	//numvect.push_back(0);
	int MAX = 100001;
	for (int i = 0; i < MAX; i++)
	{
		numvect.push_back(rand() % 1000 - 500);
	}
	cout << numvect.size() << endl;
	MaxSubArray value;
	clock_t start_t = clock();
	//value = FindMaxSubArray(numvect, 1, 16);
	//value = FindMaxSubArray1(arr, 1, 16);
	clock_t end_t = clock();

	
	value = FindMaxSubArray2(arr, 1, 16);
	cout << "running time:" << static_cast<double>(end_t - start_t) / 1000 << "s" << endl;
	cout << value.data << " " << value.left << "-" << value.right << endl;
}
