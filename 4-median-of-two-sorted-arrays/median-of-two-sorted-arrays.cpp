class Solution {
public:
    double findMedianSortedArrays(vector<int> &arr1, vector<int> &arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int n = n1 + n2;
        
        int i = 0, j = 0;
        int prev = 0, curr = 0;
        
        for (int count = 0; count <= n / 2; ++count) {
            prev = curr;
            if (i < n1 && j < n2) {
                if (arr1[i] < arr2[j]) {
                    curr = arr1[i++];
                } else {
                    curr = arr2[j++];
                }
            } else if (i < n1) {
                curr = arr1[i++];
            } else {
                curr = arr2[j++];
            }
        }
        
        if (n % 2 == 1) {
            return curr;
        }
        else {
            return (double)(prev + curr) / 2.0;
        }
    }
};