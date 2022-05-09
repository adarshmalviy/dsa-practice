class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int index1 =0;
        int index2 = nums.size()-1;
        int  i=0;
        while(i<= index2)
        {
            if(nums[i]==0)
            {
                swap(nums[i], nums[index1++]);
                i++;
            }
            else if(nums[i] == 2)    swap(nums[i], nums[index2--]);
            
            else    i++;
            
            
        }
        // return nums;
    }
};