class Solution {
   private:
   int n;
    bool isPalindrome(string& word, int l, int r) {
        while (l < r) {
            if (word[l] != word[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void helper(int ind, string& s, vector<string>& list, vector<vector<string>>& ans){
        if(ind==n){
            ans.push_back(list);
            return;
        }
        for(int j = ind; j < n; j++){
            if(isPalindrome(s,ind,j)){
                string sub = s.substr(ind, j - ind + 1);
                list.push_back(sub);
                helper(j+1,s,list,ans);
                list.pop_back();
            }
        }
    }

   public:
    vector<vector<string> > partition(string s) {
        vector<vector<string>> ans;
        vector<string> list;
        n = s.size();
        helper(0,s,list,ans);
        return ans;
    }
};