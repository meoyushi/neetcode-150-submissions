class Solution {
public:

    vector<int>adj[26];
    vector<int>vis;
    stack<int>ans;
    vector<bool>present;

    bool dfs(int node){
        vis[node]=1;//visiting

        for(int it : adj[node]){
            if(vis[it]==1)return true;//cycle
            if(vis[it]==0 && dfs(it)) return true;//the child is not visited and cycle is present ahead
        }

        vis[node]=2;//visited
        ans.push(node);
        return false;
    }

    string foreignDictionary(vector<string>& words) {
        //we will make a graph using prece
        //then start dfs from every unvisited node
        //if it is a cycle then return ""

        vis.assign(26,0);
        present.assign(26,false);

        //mark existing characters
        for(string &word : words){
            for(char c:word){
                present[c-'a']=true;
            }
        }

        for(int i=0; i<words.size()-1; i++){
            string &a =words[i];
            string &b=words[i+1];

            int len=min(a.size(),b.size());
            int j=0;

            //find first different character
            while(j<len && a[j]==b[j])j++;

            //invalid prefix case
            if(j==len){
                if(a.size()>b.size()) return "";
            }
            else{
                adj[a[j]-'a'].push_back(b[j]-'a');
            }
        }

        //topological sort
        for(int i=0; i<26; i++){
            if(present[i] && vis[i]==0){
                if(dfs(i)) return "";
            }
        }

        string ans1;

        while(!ans.empty()){
            ans1+=char(ans.top()+'a');
            ans.pop();
        }

        return ans1;


    }
};
