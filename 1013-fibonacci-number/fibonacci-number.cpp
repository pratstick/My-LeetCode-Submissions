class Solution {
public:
    int fib(int n) {
        vector<int> dp(n+1,0);
        if(n<0) return -1;
        if(n<=1) return n;
        int p1 = 1;
        int p2 = 0;
        int curr = 1;
        for(int i=2;i<=n;i++){
            curr = p1 + p2;
            p2 = p1;
            p1 = curr;
        }
        return curr;
    }
};