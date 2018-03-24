//
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0,j=0;
        int max_pro=0;
        int len=prices.size();
        if(len==0||prices.empty())
             return max_pro;
         int min_price=prices[0];
        /*for(int m=0;m<len;m++)
        {
            for(int n=m+1;n<len;n++)
            {
                if(prices[n]-prices[m]>max_pro)
                {
                    i=m;
                    j=n;
                    max_pro=prices[n]-prices[m];
                }
            }
        }*/
        for(int i=0;i<len;i++)
        {
            if(min_price>prices[i])
            {
                min_price=prices[i];
            }else if(max_pro<prices[i]-min_price)
            {
                max_pro=prices[i]-min_price;
            }
            
        }
         return max_pro;
    }
};
