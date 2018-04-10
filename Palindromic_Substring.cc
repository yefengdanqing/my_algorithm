class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        int len=s.size();
        if(len<=0)
            return res;
        if(len==1)
            return s;
        int max_len=0,cur_len=0,begin=0;
        /*for(int i=0;i<len;i++)
        {
            int left=i-1,right=i+1;
            while(left>=0&&right<len&&s[left]==s[right])
            {
                cur_len=right-left;
                if(cur_len>max_len)
                {
                    max_len=cur_len;
                    begin=left;
                }
                left--;
                right++;
            }
            left=i,right=i+1;
            while(left>=0&&right<len&&s[left]==s[right])
            {
                cur_len=right-left;
                if(cur_len>max_len)
                {
                    max_len=cur_len;
                    begin=left;
                }
                left--;
                right++;
            }
        }*/
        bool dp[len][len]={false};
        for(int i=0;i<len;i++)
            dp[i][i]=true;
        
        for(int l=0;l<len;l++)
        {
            for(int i=0;i<=l;i++)
            {
                //一列一列计算，保证子问题有解
                dp[i][l]=s[l]==s[i]&&(l-i<=2||dp[i+1][l-1]);
                if(dp[i][l])
                {
                    if(l-i+1>max_len)
                    {
                        max_len=l-i+1;
                        begin=i;
                    }
                }
            }
        }
        res=s.substr(begin,max_len);
        return res;
     
};
