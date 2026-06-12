#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    vector<int> minCost(n, INT_MAX);
    vector<bool> visited(n, false);

    minCost[0] = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] &&
                (u == -1 || minCost[j] < minCost[u])) {
                u = j;
            }
        }

        visited[u] = true;
        ans += minCost[u];

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int dist = abs(points[u][0] - points[v][0]) +
                           abs(points[u][1] - points[v][1]);

                minCost[v] = min(minCost[v], dist);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
