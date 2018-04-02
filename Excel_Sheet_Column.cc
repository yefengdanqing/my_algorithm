#include"common.h"
 string convertToTitle(int n) {
        if(n==0)
            return "";
        string ret;
        while(n>0)
        {
            ret=(char)('A'+(n-1)%26)+ret;
            n=(n-1)/26;
        }
        return ret;
        
    }
int ConvertTitle(string& s)
{
	int len=s.size();
	if(len<=0)
		return 0;
	int ret=0;
	int j=1;
	for(int i=len-1;i>=0;i--,j*=26)
	{
		ret=(s[i]-'A'+1)*j+ret;
	}
	return ret;
}
int main()
{
	//731
	int input;
	cin>>input;
	string result=convertToTitle(input);
	cout<<result;
	cout<<endl;
	cout<<flush;
	cout<<ConvertTitle(result);
}
