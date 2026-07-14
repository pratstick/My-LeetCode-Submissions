class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int start = 0;
        int end = 0;
        start+=stoi(startTime.substr(0,2))*3600;
        start+=stoi(startTime.substr(3,2))*60;
        start+=stoi(startTime.substr(6,2)); 

        
        end+=stoi(endTime.substr(0,2))*3600;
        end+=stoi(endTime.substr(3,2))*60;
        end+=stoi(endTime.substr(6,2)); 
               
        return end - start;
    }
};