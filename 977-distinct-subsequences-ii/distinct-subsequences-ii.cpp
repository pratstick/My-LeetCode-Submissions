class Solution {
public:
    int distinctSubseqII(string s) {
        int mod=1e9+7;
        vector<long long>last(26,0);
        long long res=1;
        for(char ch:s){
            int x=ch-'a';
            long long temp=res;
            res=(2*res-last[x]+mod)%mod;
            last[x]=temp;

        }
        return  (res-1+mod)%mod;
    }
};