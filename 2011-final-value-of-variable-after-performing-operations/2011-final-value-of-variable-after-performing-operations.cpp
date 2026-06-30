class Solution {
public:
    int finalValueAfterOperations(vector<string>& opration) {
        int i = 0;
        for (int j = 0; j < opration.size(); j++) {
            if (opration[j] == "++X" || opration[j] == "X++") {
                i++;
            } else {
                i--;
            }
        }
        return i;
    }
};