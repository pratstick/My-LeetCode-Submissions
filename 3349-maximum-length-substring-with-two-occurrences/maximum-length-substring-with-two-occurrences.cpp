class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> mpp;
        int len = 0;
        int curr = 0;
        int start = 0;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
            while(mpp[s[i]]>2){
                mpp[s[start]]--;
                start++;
            }
            curr = i - start + 1;
            len = max(len,curr);
        }
        return len;
    }
};