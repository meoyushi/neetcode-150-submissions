class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>a(n,0);

        stack<int>s;

        for(int i=0; i<n; i++){

            while(!s.empty() && temperatures[i]>temperatures[s.top()]){
                int j=s.top();
                s.pop();
                a[j]=i-j;
        
            }
            s.push(i);

        }
        return a;
    }
};