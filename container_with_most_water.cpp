// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int n = height.size();
        
        int l=0, r=n-1;
        while(l<r) {
            int area = min(height[l], height[r]) * (r-l);
            if(area > maxArea) {
                maxArea = area;
            }
            
            if(height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        
        return maxArea;
    }
};