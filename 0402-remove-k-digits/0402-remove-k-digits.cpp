class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        int n = num.length();
        
        for (int i = 0; i < n; i++) {
            while (k > 0 && !ans.empty() && ans.back() > num[i]) {
                ans.pop_back();
                k--;
            }
            ans.push_back(num[i]);
        }
        
       
        while (k > 0) {
            ans.pop_back();
            k--;
        }
        
     
        int i = 0;
        while (i < ans.length() && ans[i] == '0') {
            i++;
        }
        ans = ans.substr(i);
        
        return ans.empty() ? "0" : ans;
    }
};