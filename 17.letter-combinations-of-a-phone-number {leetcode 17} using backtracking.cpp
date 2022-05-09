class Solution {
public:
    void solve(string digits, vector<string> &ans,vector<vector<char>> &v, int pos, string s)
    {
        if(pos == digits.size())
        {
            if(s != "") ans.push_back(s);
            
            return;
        }
        
        int temp = digits[pos] -'0';
        
        for(int i =0;i<v[temp].size();i++)
        {
            
            s.push_back(v[temp][i]);
            solve(digits,ans, v,pos+1,s);
            s.pop_back();
        }
        
        
    }
    
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        vector<vector<char>> v {{},{}, {'a','b','c'}, {'d','e','f'}, {'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'}, {'t','u','v'}, {'w','x','y','z'}};
        
        solve(digits, ans,v, 0, "");
        
        return ans;
    }
};