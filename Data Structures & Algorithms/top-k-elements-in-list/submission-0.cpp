class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int n=nums.size();

        for(int num : nums) freq[num]++;

        vector<vector<int>>buc(n+1);

        for(auto &[num,count] : freq){
            buc[count].push_back(num);
        }

        //the below loop limits are imp
        vector<int>ans;
        for(int i=n; i>=0 && ans.size()<k; i--){
            for( auto m : buc[i]){
                ans.push_back(m);
                if(ans.size()==k) return ans; 
            }
        }

        return ans;

    }
};
