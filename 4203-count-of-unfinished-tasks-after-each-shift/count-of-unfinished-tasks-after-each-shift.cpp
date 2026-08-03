#define ll long long
class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        vector<ll>p; //prefixsum
        ll s = 0;
        for(int a:tasks){
            s+=a;
            p.push_back(s);
        }
        //s is total time of all tasks
        ll d = 0;
        vector<int>res;
        int n = tasks.size();
        for(int t:shifts){
            if(d+t >= s){ //all tasks completed
                res.push_back(0);
                d = 0;
            }
            else{
                d+=t; //sum of time of uncompleted tasks
                auto it = upper_bound(p.begin(),p.end(),d);//fully finished
                res.push_back(n-distance(p.begin(),it));
            }
        }
        return res;
    }
};