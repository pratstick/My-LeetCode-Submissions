class Solution {
public:
    int countCommas(int n) {
        if(n < 1000) return 0;
        else if(n<10000) return n - 1000 + 1;
        else if(n < 100000) return n - 10000 + 1 + 9000;
        else return 99001;  
    }
};