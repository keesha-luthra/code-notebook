class Solution {
public:
struct Transactions{
    string name;
    int time;
    int amt;
    string city;
};
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        vector<Transactions> txns;
        for(auto it : transactions){
            stringstream ss(it);
            string name, time, amt, city;
            getline(ss, name, ',');
            getline(ss, time, ',');
            getline(ss, amt, ',');
            getline(ss, city, ',');
            Transactions t = {name, stoi(time), stoi(amt), city};
            txns.push_back(t);
        }

        vector<bool> invalid(n, false);
        for(int i = 0; i < n; i++){
            if(txns[i].amt > 1000){
                invalid[i] = true;
            }
            for(int j = i + 1; j < n; j++){
                if(txns[i].name == txns[j].name && txns[i].city != txns[j].city && abs(txns[i].time - txns[j].time) <= 60){
                    invalid[i] = true;
                    invalid[j] = true;
                }
            }
        }

        vector<string> ans;
        for(int i = 0; i < n; i++){
            if(invalid[i] == true){
                ans.push_back(transactions[i]);
            }
        }
        return ans;
    }
};