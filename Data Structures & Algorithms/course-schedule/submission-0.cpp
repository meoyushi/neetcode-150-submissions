class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);

        for(auto &it : prerequisites){
            int a=it[0];
            int b=it[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;

        for(int i=0; i<n; i++){
            if(indegree[i]==0) q.push(i);
        }//like starting points

        int c=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            c++;

            for(auto neigh : adj[node]){
                indegree[neigh]--;

                if(indegree[neigh]==0) q.push(neigh);
            }
        }
        return c==n;//If count == numCourses, all courses can be finished; otherwise, there is a cycle.
    }
};