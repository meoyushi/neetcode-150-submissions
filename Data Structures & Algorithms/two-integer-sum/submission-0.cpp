class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 2pointer but n^2
        unordered_map<int,int>s;
        int n=nums.size();
        for(int i=0; i<n ;i++){
            int dif=target-nums[i];
            if(s.find(dif)!=s.end()) return {s[dif], i};
            s.insert({nums[i],i});

        }
        return {-1};
    }
};
