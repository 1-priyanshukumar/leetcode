class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
      unordered_set<string> st;
      for(auto &path : paths){
        string source = path[0];
        st.insert(source);

      } 
      for(auto &path : paths){
        string dest =path[1];
        if(st.find(dest)==st.end()){
        return dest;
        }
      } 
    
    return "";
    }
};