class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // int n=strs.size();
        // vector<vector<string>> ans;
        // for(string s : strs){
        //     sort(s.begin(),s.end());
        // }
        // sort(strs.begin(),strs.begin());

        unordered_map<string, vector<string>>m;
        for(string k : strs){
            string s=k;
            sort(s.begin(),s.end());
            m[s].push_back(k);
        }

        vector<vector<string>>ans;
        for(auto &it : m){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};
