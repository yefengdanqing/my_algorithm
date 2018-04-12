class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        /*int row=n;
        int col=matrix[0].size();
        //注意循环的边界条件
        for(int i=0;i<n/2;i++)
        {
            for(int j=i;j<n-i-1;j++)
            {
                int tmp=matrix[i][j];
                matrix[i][j]=matrix[n-1-j][i];
                matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
                matrix[j][n-1-i]=tmp;
                
                
                
            }
            
        }*/
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        for(int i=0;i<n;i++)
            for(int j=0;j<n/2;j++)
            {
                swap(matrix[i][j],matrix[i][n-j-1]);
            }
        
    }
};
