class Solution {
using ll = long long;
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,1);
        int maxi = -1;
        for(int i=0;i<n;i++){
            if(nums[i]>=maxi){
                maxi = nums[i];
                prefix[i] = maxi;
            }
            else{
                prefix[i] = gcd(nums[i],maxi);
            }
        }
        sort(prefix.begin(),prefix.end());
        int low = 0;
        int high = n-1;
        ll ans = 0;
        while(low<high){
            ans+=gcd(prefix[low],prefix[high]);
            low++;
            high--;
        }
        return ans;
    }
};