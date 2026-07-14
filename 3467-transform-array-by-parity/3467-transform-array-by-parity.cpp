// class Solution {
// public:
//     vector<int> transformArray(vector<int>& nums) {
//         int zeroCount=0;
//         int oneCount=0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]&1)
//             oneCount++;
//             else
//             zeroCount++;
//         }

//         for(int i=0;i<nums.size();i++){
//             if(zeroCount!=0){
//                 nums[i]=0;
//                 zeroCount--;
//                 continue;
//             }
//             else{
//                 nums[i]=1;
//             }
//         }
//         return nums;
//     }
// };
class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {

        int n = nums.size() - 1;
        for (int i = 0; i <= n; i++) {
            if (nums[i] % 2 == 0) {
                nums[i] = 0;
            } else {
                nums[i] = 1;
            }
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};