// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> result;
        vector<int> tmp;
        recrSum(candidates, result, tmp, 0, target, n);
        
        return result;
        
    }
    
    void recrSum(vector<int>& candidates, vector<vector<int>> &result, vector<int> tmp, int index, int target, int n) {
            if(target == 0) {
                result.push_back(tmp);
                return;
            }
        
        if(target < 0 || index >= n) {
            return;
        }
        
        tmp.push_back(candidates[index]);
        
        recrSum(candidates, result, tmp, index, target-candidates[index], n);
        
        tmp.pop_back();
        
        recrSum(candidates, result, tmp, index+1, target, n);
        
    }
};