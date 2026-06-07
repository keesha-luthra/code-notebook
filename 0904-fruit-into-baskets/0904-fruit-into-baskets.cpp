class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right = 0;
        unordered_map<int, int>mpp;
        int ans = 0;
        while(right < fruits.size()){
            mpp[fruits[right]]++;
            while(mpp.size() > 2){
                mpp[fruits[left]]--;
                if( mpp[fruits[left]] == 0) mpp.erase(fruits[left]);
                left++;
            }
            // mpp[fruits[right]]++;
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};