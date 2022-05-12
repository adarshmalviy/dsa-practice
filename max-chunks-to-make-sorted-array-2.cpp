class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
//         generate right-minimum
        
        
        vector<int> rmin(arr.size()+1);
        // rmin[0] = INT_MAX;
        rmin[arr.size()] = INT_MAX;
        for(int i =arr.size()-1; i>=0; i--)
        {
            
            rmin[i] = min(rmin[i+1], arr[i]);
            
        }
        
        int lmax = INT_MIN;
        int count =0;
        
        for(int i=0;i<arr.size();i++)
        {
            lmax = max(lmax, arr[i]);
            
            if(lmax <= rmin[i+1])
                count++;
        }
        return count;
    }
};