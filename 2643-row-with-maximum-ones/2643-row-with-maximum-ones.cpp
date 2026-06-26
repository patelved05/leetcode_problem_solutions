class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        int rowIndex = 0;
        int maxOnes = 0;

        for (int i = 0; i < mat.size(); i++) {

            int cnt = 0;

            for (int j = 0; j < mat[i].size(); j++) {
                cnt += mat[i][j];
            }

            if (cnt > maxOnes) {
                maxOnes = cnt;
                rowIndex = i;
            }
        }

        return {rowIndex, maxOnes};
    }
};