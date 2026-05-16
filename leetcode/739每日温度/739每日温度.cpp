# include <iostream>
# include <vector>
# include <stack>
using namespace std;

class Solution{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> s;
        for (int i = 0; i < n; i++){
            int temperature = temperatures[i];
            while(!s.empty() && temperature > temperatures[s.top()]){
                int prev_index = s.top();
                s.pop();
                ans[prev_index] = i - prev_index;
            }
            s.push(i);
        }
        return ans; 
    }
};