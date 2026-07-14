class Solution {
  public:
    int minDistance(string start, string target) {
        int m = start.size();
        int n = target.size();
        vector<int>prev(n+1,0);
        for(int i=0;i<=m;i++){
            vector<int>curr(n+1,0);
            for(int j=0;j<=n;j++){
                if(j==0){
                    curr[j] = i;
                    continue;
                }
                if(i==0){
                    curr[j] = j;
                    continue;
                }
                if(start[i-1]==target[j-1]) curr[j] = prev[j-1];
                else{
                    int insert = 1 + curr[j-1];
                    int del = 1 + prev[j];
                    int replace = 1 + prev[j-1];
                    curr[j] = min({insert,del,replace});
                }      
            }
            prev = curr;
        }
        return prev[n];
    }
};

