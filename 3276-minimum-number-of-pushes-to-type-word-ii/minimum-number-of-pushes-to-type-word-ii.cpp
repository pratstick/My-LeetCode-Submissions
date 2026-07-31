class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        int ans = 0;
        sort(freq.rbegin(),freq.rend());
        for(int i=0;i<freq.size();i++){
            if(i<=7) ans+=freq[i];
            else if(i<=15) ans+=(freq[i]*2);
            else if(i<=23) ans+=(freq[i]*3);
            else ans+=(freq[i]*4);
        }
        return ans;

    }
};