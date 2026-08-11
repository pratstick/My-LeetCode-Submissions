class Solution {
private:
    void merge(int low, int mid, int high, vector<int>& nums){
        vector<int> temp;
        int left = low;
        int right = mid+1;
        while(left<=mid && right <= high){
            if(nums[left] < nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }            
        }
        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }

        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
            nums[i] = temp[i-low];
        }
        return;
    }
    void mSort(int low, int high, vector<int>&nums){
        if(low>=high) return;
        int mid = low + (high-low)/2;
        mSort(low,mid,nums);
        mSort(mid+1,high,nums);
        merge(low,mid,high,nums);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mSort(0,nums.size()-1,nums);
        return nums;
    }
};
