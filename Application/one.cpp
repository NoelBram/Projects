#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'minCost' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY cost as parameter.
 */

int minCost(vector<vector<int>> cost) {
    if((cost.size() < 1) || (cost.size() > 100)){
        cout << " Error: The size of n must be >= 1 and <= 100. ";
        return 0;
    }
    int ans = 0, checker = 0, checker2 = -1; 
    for(int i = 0; i < cost.size(); i++){
        checker = 0; 
        for(int j = 0; j < cost[i].size(); j++){
            if((cost[i][j] < 0) || (cost[i][j] > 100)){
                cout << " Error: The size of cost[i][j] must be >= 0 and <= 100. ";
                return 0;
            }
            if(((checker == 0) && (j != checker2)) || ((checker > cost[i][j]) && (j != checker2))){
                checker = cost[i][j];
                checker2 = j;
            }  
        }
        ans += checker;
    }
    return ans;
}
