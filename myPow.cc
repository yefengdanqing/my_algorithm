class Solution {
public:
    double myPow(double x, int n) {
      /*  if(n==0)
            return 1;
        else if(n<0)
            return 1/x*myPow(1/x,-(n+1));
        double half=myPow(x,n/2);
        if(n%2==1)
            return half*half*x;
        if(n%2==0)
            return half*half;*/
        if(n==0)
            return 1;
        if(n<0)
            //return 1/myPow(x,-n);
            //n为最小负数的时候，-n超过了其整数的最大值
            return 1/x*myPow(1/x,-(n+1));
        if(n==2)
            return x*x;
        if(n%2==1)
           // return myPow(myPow(x,n/2),2)*x;
            return x*myPow(x,n/2)*myPow(x,n/2);
        if(n%2==0)
            return myPow(myPow(x,n/2),2);
    }
};
