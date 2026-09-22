class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       vector<int>result(temperatures.size(),0);
       stack<int>days;

       for(int day(0); day < temperatures.size(); day++){
            while((!days.empty()) && (temperatures[day] > temperatures[days.top()])){
                int copy_day = days.top();
                days.pop();

                result[copy_day] = day - copy_day;
            }
            days.push(day);
       } 

       return result;
    }
};
