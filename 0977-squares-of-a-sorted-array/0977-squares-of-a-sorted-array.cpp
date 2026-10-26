class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int siz=nums.size();
        for(int i=0;i<siz;i++){
            nums[i]=nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};