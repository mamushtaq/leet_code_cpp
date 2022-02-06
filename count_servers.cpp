#include <iostream>
#include<vector>
using namespace std;
//
//You are given a map of a server center, represented as a m* n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server.Two servers are said to communicate if they are on the same row or on the same column.
//
//Return the number of servers that communicate with any other server.

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int communicate = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size()-1; j++) {
                if (grid[i][j] == 1 && grid[i][j+1]) {
                    communicate += 2;;
                    
                }
            }
        }
        cout << communicate;
        for (int i = 0; i < grid.size()-1; i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1 && grid[i+1][j]) {
                    if (grid[i][j + 1] == 1 || grid[i+1][j+1] == 1)
                        communicate += 1;
                    else
                        communicate += 2;

                }
            }
        }
        return communicate;
    }
};

int main() {
    /*[[1, 0, 0, 1, 0], [0, 0, 0, 0, 0], [0, 0, 0, 1, 0]]*/
    vector<vector<int>> grid{
            {1,0,0,1,0},
            {0,0,0,0,0},
            {0,0,0,1,0} };
    Solution*ptr = new Solution();
    cout << ptr->countServers(grid);
    return 0;
}