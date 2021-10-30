#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<bool>> st;
    int X[4] = {0, 0, 1, -1};
    int Y[4] = {1, -1, 0, 0};
    int numIslands(vector<vector<char>>& A) {
        int m = A.size(), n = A[0].size();
        st.resize(m, vector<bool>(n, false));
        
        int res = 0;
        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (A[i][j] == '1' && st[i][j] == 0) {
                    res++;
                    // dfs(A, i, j, m, n);
                    bfs(A, i, j, m, n);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& A, int x, int y, int m, int n) {
        if (x < 0 || x >= m || y < 0 || y >= n) return;
        if (A[x][y] == '0' || st[x][y] == true) return;

        st[x][y] = true;
        for (int i = 0; i < 4; i ++ ) {
            int nx = x + X[i], ny = y + Y[i];
            dfs(A, nx, ny, m, n);
        }      
    }

    void bfs(vector<vector<char>> &A, int x, int y, int m, int n) {
        queue<pair<int, int>> q;
        q.push({x, y});
        st[x][y] = true;
        while (!q.empty()) {
            auto pos = q.front();
            q.pop();
            for (int i = 0; i < 4; i ++ ) {
                int nx = X[i] + pos.first, ny = Y[i] + pos.second;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && st[nx][ny] == false && A[nx][ny] == '1') {
                    q.push({nx, ny});
                    st[nx][ny] = true;
                }
            }
        }
    }
};

class Solution {
public:
    int n, m;
    vector<vector<char>> A;
    bool st[310][310] = {false}; //bfs 是否入队 , dfs 是否访问
    int X[4] = {1, -1, 0, 0};
    int Y[4] = {0, 0, 1, -1};

    bool judge(int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m) return false;
        if (A[x][y] == '0' || st[x][y] == true) return false;
        return true;
    }

    void dfs(int x, int y) {
        if (judge(x, y) == false) {
            return;
        }
        st[x][y] = true;
        for (int i = 0; i < 4; i ++ ) {
            int nx = X[i] + x, ny = Y[i] + y;
            dfs(nx, ny);
        }
    }

    void bfs(int x, int y) {
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        st[x][y] = true;
        while (!q.empty()) {
            pair<int, int> pos = q.front();
            q.pop();
            for (int i = 0; i < 4; i ++ ) {
                int nx = pos.first + X[i], ny = pos.second + Y[i];
                if (judge(nx, ny) == true) {
                    q.push(make_pair(nx, ny));
                    st[nx][ny] = true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        this->n = n, this->m = m;
        this->A = grid;
        int res = 0;
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < m; j ++ ) {
                if (grid[i][j] == '1' && st[i][j] == false) {
                    res++;
                    bfs(i, j);
                }
            }
        }
        return res;
    }
};

