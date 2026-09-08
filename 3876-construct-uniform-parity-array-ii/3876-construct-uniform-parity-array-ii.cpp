class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min = *min_element(nums1.begin(),nums1.end());

        if(min % 2 == 1){
            return true;
        }else{
            for(int x : nums1){
                if(x % 2 == 1)
                return false;
            }
        }
            return true;
    }
};