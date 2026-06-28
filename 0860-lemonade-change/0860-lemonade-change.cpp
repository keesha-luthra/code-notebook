class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5) mpp[5]++;
            else if(bills[i] == 10) {
                if(mpp.find(5) != mpp.end()){
                    mpp[5]--;
                    if(mpp[5] == 0) mpp.erase(5);
                    mpp[10]++;
                }
                else return false;
            }
            else{
                if(mpp[10] > 0 && mpp[5] > 0){
                    mpp[10]--;
                    if(mpp[10] == 0) mpp.erase(10);
                    mpp[5]--;
                    if(mpp[5] == 0) mpp.erase(5);
                    mpp[20]++;
                }
                else if (mpp[5] >= 3){
                    mpp[5] -= 3;
                    if(mpp[5] == 0) mpp.erase(5);
                    mpp[20]++;
                }
                else return false;
            }
        }
        return true;
    }
};