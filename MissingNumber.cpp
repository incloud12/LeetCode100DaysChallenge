class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int actual_sum = accumulate(nums.begin(),nums.end(),0);
        int req_sum = n*(n+1)/2;
        return req_sum - actual_sum;
    }
};
