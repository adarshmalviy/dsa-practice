class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        
        int ans = 0;
        // int min = INT_MAX;
        
        vector<vector<int>> dp(matrix.size()+1, vector<int>(matrix[0].size()+1));
        
        for(int i =1;i<=matrix.size();i++)
            for(int j=1;j<=matrix[0].size();j++)
            {
                if(matrix[i-1][j-1] == '1')
                {
                    int mini = INT_MAX;
                    mini = min(mini,dp[i-1][j]);
                    mini = min(mini,dp[i][j-1]);
                    mini = min(mini,dp[i-1][j-1]);
                    
                    dp[i][j] = mini +1;
                
                    ans = max(dp[i][j], ans);
                }
            }
        
        return ans*ans;
    }
};