using ll = long long;
class Solution {
private:
    ll timetoFinish(vector<int>&nums, int k){
        ll time = 0;
        for(int&it:nums){
            time += ((it + k - 1)/k);
        }
        return time;
    }
public:
int minEatingSpeed(vector<int>& nums, int h) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low) / 2;
            ll time = timetoFinish(nums,mid);
            
            if(time <= h){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
