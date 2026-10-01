class Solution {
public:
    stack<char> st;
    bool isValid(string s) {  
        if (s.size()&1) return 0;
        unordered_map<char, char> bracket_open;
        bracket_open[')']='(';
        bracket_open['}']='{';
        bracket_open[']']='[';
        for (char c: s){
            switch(c){
                case '(':
                case '{':
                case '[':
                    st.push(c);
                    break;
                case ')': 
                case '}':
                case ']':
                    if (st.empty() || st.top()!=bracket_open[c])
                        return 0;
                    else st.pop();
                    break;
            }
        }
        if (st.empty())
            return 1;
        else 
            return 0;
    }
};