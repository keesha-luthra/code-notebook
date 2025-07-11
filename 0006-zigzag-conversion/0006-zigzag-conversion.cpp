class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) return s;

        vector<string> rows(min(numRows, int(s.length())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;

            // Change direction at the top or bottom
            if (curRow == 0 || curRow == numRows - 1)
                goingDown = !goingDown;

            curRow += goingDown ? 1 : -1;
        }

        // Combine all rows
        string result;
        for (string row : rows)
            result += row;

        return result;
    }
};
