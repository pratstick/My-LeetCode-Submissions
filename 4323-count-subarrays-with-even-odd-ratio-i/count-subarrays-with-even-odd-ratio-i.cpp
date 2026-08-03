#define ll long long
class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        vector<ll>prefix;
        ll s = 0;
        for(int num:nums){
            s = (num%2==0)?s-b:s+a;
            prefix.push_back(s);
        }
        int n = nums.size();
        ll count = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i==0){
                    if(prefix[j]>=0) count++;
                    continue;
                }
                if((prefix[j]-prefix[i-1]) >= 0) count++;
            }
        }
        return count;
    }
};