// https://leetcode.com/problems/k-diff-pairs-in-an-array/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> umap;
        
        for(int i=0; i<n; i++) {
            umap[nums[i]]++;
        }
        
        if(k==0) {
            for(auto a: umap) {
                if(a.second > 1) {
                    count++;
                }
            }
        } else {
            for(auto a: umap) {
                int x = a.first + k;
                if(umap.count(x) > 0) {
                    count++;
                }
            }
        }
        
        return count;
        
    }
};