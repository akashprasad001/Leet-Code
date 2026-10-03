class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int lp=0; 
        int rp=n-1;
        while(lp < rp ){
            int wd = rp-lp;
            int ht = min(height[lp],height[rp]);
            int Area = wd*ht;
            ans = max(ans,Area);

            height[lp]<height[rp] ? lp++ : rp--;
        }
        return ans;
    }
};