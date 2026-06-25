#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {
    int rows = heights.size();
    int cols = heights[0].size();

    vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    > pq;

    dist[0][0] = 0;
    pq.push({0, {0, 0}});

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!pq.empty()) {
        int effort = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();

        if (r == rows - 1 && c == cols - 1)
            return effort;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                int newEffort = max(
                    effort,
                    abs(heights[r][c] - heights[nr][nc])
                );

                if (newEffort < dist[nr][nc]) {
                    dist[nr][nc] = newEffort;
                    pq.push({newEffort, {nr, nc}});
                }
            }
        }
    }

    return 0;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> heights(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> heights[i][j];
        }
    }

    cout << minimumEffortPath(heights) << endl;

    return 0;
}
