bool compare(int a, int b){
    return to_string(a)+to_string(b) > to_string(b)+to_string(a);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        string res = "";
        for(int value : nums){
            res += to_string(value);
        }
        return res[0] == '0' ? "0":res;
    }
};
