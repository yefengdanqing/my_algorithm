#include"../leetcode/common.h"
void Select_Actity(vector<int> start,vector<int> finish,int len,int k,vector<int>& result)
{
	int m=k+1;
	while(m<=len&&start[m]<finish[k])
		m+=1;
	if(m<=len)
	{
		result.push_back(m);
		Select_Actity(start,finish,len,m,result);
	}else
		return;
}
void Select_Actity_Ex(vector<pair<int,int>> activities,vector<int>& result)
{
	int len=activities.size();
	result.push_back(1);
	int k=1;
	for(int i=2;i<len;i++)
	{
		if(activities[i].first>=activities[k].second)
		{
			result.push_back(i);
			k=i;
		}
	}
}
int main()
{
	vector<int> s={0,1,3,0,5,3,5,6,8,8,2,12};
	vector<int> f={0,4,5,6,7,9,9,10,11,12,14,16};
	vector<int> res;
	Select_Actity(s,f,11,0,res);
	for(auto s: res)
		cout<<s<<" ";
	vector<pair<int,int>> activities;
	activities.push_back(pair<int,int>(0,0));
	activities.push_back(make_pair(1,4));
	activities.push_back(pair<int , int>(3,5));
    activities.push_back(pair<int , int>(0,6));
    activities.push_back(pair<int , int>(5,7));
    activities.push_back(pair<int , int>(3,9));
    activities.push_back(pair<int , int>(5,9));
    activities.push_back(pair<int , int>(6,10));
    activities.push_back(pair<int , int>(8,11));
    activities.push_back(pair<int , int>(8,12));
    activities.push_back(pair<int , int>(2,14));
    activities.push_back(pair<int , int>(12,16));
	cout<<"---"<<endl;
	vector<int> a;
	Select_Actity_Ex(activities,a);
	for(auto s: a)
		cout<<s<<" ";
}
