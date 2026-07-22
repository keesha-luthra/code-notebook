class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income){
        double prev = 0;
        double tax = 0;
        for(auto it : brackets){
            int upper = it[0];
            double percent = it[1];

            int taxable = min(upper, income) - prev;
            if(taxable <= 0){
                break;
            }
            
            tax += taxable * percent/100.0;
            prev = upper;
        }
        return tax;
    }
};