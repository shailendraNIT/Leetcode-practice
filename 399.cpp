#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<pair<string, double>>> graph;

unordered_set<string> vis;

double pathweight(string start, string end)
{
    if (start == end)
        return 1.0;
    if (graph.find(start) == graph.end())
        return -1.0;

    if (vis.find(start) != vis.end())
        return -1.0;

    vis.insert(start);

    for (auto nbr : graph[start])
    {
        if (vis.find(nbr.first) != vis.end())
            continue;
        double smallans = pathweight(nbr.first, end);
        cout << smallans << " ";
        cout << nbr.second << endl;
        if (smallans != -1.0)
            return smallans * nbr.second;
    }

    return -1.0;
}

vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    int n = equations.size();
    vector<double> ans;

    for (int i = 0; i < n; i++)
    {
        string start = equations[i][0];
        string end = equations[i][1];
        double value = values[i];

        graph[start].push_back({end, value});
        graph[end].push_back({start, 1.0 / value});
    }
    

    for (auto query : queries)
    {
        vis.clear();
        ans.push_back(pathweight(query[0], query[1]));
        cout << "------" << ans[i] << "-----" << endl;
    }
    return ans;
}

int main()
{
    vector<vector<string>> equations = {{"a","b"},{"b","c"}};
    vector<double> values = {2.0,3.0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    vector<double>ans=calcEquation(equations,values,queries);

    for(auto val:ans){
        cout<<val<<" ";
    }


    return 0;
}