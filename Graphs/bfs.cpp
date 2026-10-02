#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

vector<int> bfs(vector<vector<int>>& adj, int src) {

    int V = adj.size();

    // Queue to store nodes as they get discovered
    queue<int> q;

    vector<int> dist(V, INT_MAX);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : adj[u]){
            if(dist[v] == INT_MAX){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    // Return the final shortest distances from the source
    return dist;
}

int main() {
    int src = 0;

    vector<vector<int>> adj(5);
    adj[0] = {{1}, {2}};
    adj[1] = {{0}, {4}, {2}};
    adj[2] = {{0}, {3}, {1}};
    adj[3] = {{2}, {4}};
    adj[4] = {{1}, {3}};

    vector<int> result = bfs(adj, src);

    for (int d : result)
        cout << d << " ";
    cout << " ";

    return 0;
}
