class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int cnt = 0;
        map<long long, int> mpp;
        mpp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            sum = sum + nums[i];
            int req = sum - k;
            cnt = cnt + mpp[req];
            mpp[sum]++;
        }
        return cnt;
    }
};