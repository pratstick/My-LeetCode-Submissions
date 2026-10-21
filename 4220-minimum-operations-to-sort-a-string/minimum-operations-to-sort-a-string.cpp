class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string sortedS = s;
        sort(sortedS.begin(), sortedS.end());
        char mn = sortedS[0];
        char mx = sortedS[n-1];
        if(sortedS == s) return 0;
        if(n==2){            
            return -1;
        }
        if(s[0]==mn || s[n-1]==mx) return 1;
        for(int i = 1; i < n-1 ; i++){
            if(s[i]==mx || s[i] == mn) return 2;
        }
        return 3;


    }
};