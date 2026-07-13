vector<int> ans;
class Solution {
private:
    void generate(){
        for(int i=1;i<=9;i++){
            int num = i;            
            for(int j = i+1;j<=9;j++){
                num= num*10+j;
                ans.push_back(num);
            }
        }
        sort(ans.begin(),ans.end());
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        if(ans.empty()){
            generate();
        }
        vector<int> res;
        for(auto&it:ans){
            if(it>=low && it<=high) res.push_back(it);
        }

        return res;

    }
};