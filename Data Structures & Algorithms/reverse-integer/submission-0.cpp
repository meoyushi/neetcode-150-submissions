class Solution {
public:
    int reverse(int x) {
        bool sign=false;
        if(x<0) sign=true;

        long long num=abs((long long)x);

        string s=to_string(num);
        std::reverse(s.begin(), s.end());

        long long ans=stoll(s);

        if(sign) ans=(-1)*ans;

        if(ans<INT_MIN || ans>INT_MAX) return 0;

        return (int)ans;
    }
};