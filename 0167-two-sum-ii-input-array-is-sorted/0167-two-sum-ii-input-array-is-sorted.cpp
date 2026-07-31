class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n.size(); i++) {
            int complement = target - n[i];
            
          
            if(mp.find(complement) != mp.end()) {
               
                return {mp[complement] + 1, i + 1};
            }
            
            
            mp[n[i]] = i;
        }
        
        return {};
    }
};