#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
    public:
        unordered_map<int,list<int>>adj;
        void addEdge(int u, int v, bool direction){
            //direction=0 undirected
            //direction=1 directed

            //Create an edge from u to v
            adj[u].push_back(v);
            if(direction==0)    adj[v].push_back(u);
        }

        void initializeNodes(int n) {
            for(int i = 0; i < n; i++) {
                // Ensure each node exists in the map, even if its adjacency list is empty
                adj[i];
            }
        }

        void printAdjList(){
            for(auto it:adj){
                cout<<it.first<<"->";
                for(auto j: it.second){
                    cout<<j<<",";
                }
                cout<<endl;
            }
        }
};

int main(){
    int n;
    cout<<"Enter the no. of nodes"<<endl;
    cin>>n;

    int m;
    cout<<"Enter the no. of edges"<<endl;
    cin>>m;

    graph g;
    g.initializeNodes(n);  // Ensure all nodes are added to adj list, even if disconnected
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    g.printAdjList();
    return 0;
}