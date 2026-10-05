class Solution {
public:
    int titleToNumber(string columnTitle) {
        int columnNumber = 0;

        for (int i = 0; i < columnTitle.length(); i++) {
            int currentColumn = columnTitle[i] - 'A' + 1;
            columnNumber = columnNumber * 26 + currentColumn;
        }

        return columnNumber;
    }
};