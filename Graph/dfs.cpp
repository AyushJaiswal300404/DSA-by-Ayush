#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

class graph {
    public:
        unordered_map<int, list<int>> adj;

        void addEdge(int u, int v, bool direction) {
            adj[u].push_back(v);
            if(direction == 0) adj[v].push_back(u);
        }

        void initializeNodes(int n) {
            for(int i = 0; i < n; i++) {
                adj[i];  // ensures every node exists
            }
        }

        void printAdjList() {
            for(auto it : adj) {
                cout << it.first << " -> ";
                for(auto j : it.second) {
                    cout << j << ",";
                }
                cout << endl;
            }
        }

        void dfs(int n) {
            vector<bool> visited(n, false);

            cout << "\nDFS Traversal:" << endl;
            for(int i = 0; i < n; i++) {
                if(!visited[i]) {
                    dfsHelper(i, visited);
                }
            }
        }

    private:
        void dfsHelper(int node, vector<bool> &visited) {
            visited[node] = true;
            cout << node << " ";

            for(auto neighbour : adj[node]) {
                if(!visited[neighbour]) {
                    dfsHelper(neighbour, visited);
                }
            }
        }
};

int main() {
    int n;
    cout << "Enter the number of nodes:" << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges:" << endl;
    cin >> m;

    graph g;
    g.initializeNodes(n);

    cout << "Enter edges (u v):" << endl;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);  // undirected graph
    }

    cout << "\nAdjacency List:" << endl;
    g.printAdjList();

    g.dfs(n);

    return 0;
}
