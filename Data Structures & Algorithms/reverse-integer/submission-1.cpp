class Solution {
public:
    int reverse(int x) {
        long long ans=0;

        while(x){
            int digit=x%10;
            ans=ans*10+digit;

            if(ans<INT_MIN || ans>INT_MAX) return 0;

            x/=10;
        }

        return (int)ans;
    }
};