#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template <typename T>

class Graph{
    public:
        unordered_map<T, list<T>> adj;

        void addEdge(int u, int v, bool direction){
            // direction = 0 -> undirected graph
            // direction = 1 -> directed graph

            adj[u].push_back(v);
            if(direction == 0) adj[v].push_back(u); 
        }

        void printAdjList(){
            for(auto i : adj){
                cout << i.first << "-> ";
                for(auto j : i.second)
                    cout << j << " ";
                cout << endl;
            } 
        }
};

int main(){

    int n;
    cout << "Enter the no. of nodes " << endl;
    cin >> n;
    int m;
    cout << "Enter the no of edges " << endl;
    cin >> m;

    Graph<int> g;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        // creating an undirected graph
        g.addEdge(u, v, 0);
    }
    g.printAdjList();

    return 0;
}