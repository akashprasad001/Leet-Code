class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>runningsummation(n);
        for(int i=0;i<n;i++){
            if(i==0){
                runningsummation[i] = nums[0];
            }else{
            runningsummation[i] = runningsummation[i-1] + nums[i];
            }
        }
        return runningsummation;
    }
};