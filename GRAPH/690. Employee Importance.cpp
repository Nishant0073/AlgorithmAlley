/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

first map the employee id with the employee, it will make easy to find employee.
then push first employee into queue 
and the traverse all subordinates of employee and add importance.

*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int,Employee*> mp;
        for(auto it:employees)
            mp[it->id] = it;

        int ans = 0;
        queue<Employee*> que;
        que.push(mp[id]);
        while(que.size()!=0)
        {
            Employee *emp = que.front();
            ans+=emp->importance;

            que.pop();
            mp.erase(emp->id);

            for(auto i:emp->subordinates)
            {
                if(mp.find(i)!=mp.end())
                    que.push(mp[i]);
            }
        }

        return ans;
    }
};
