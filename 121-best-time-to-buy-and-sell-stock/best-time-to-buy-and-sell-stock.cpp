class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;
        for(int&it:prices){
            int sell = it - mini;
            if(sell > profit) profit = sell;
            if(it<mini) mini = it;
        }
        return profit;
    }
};