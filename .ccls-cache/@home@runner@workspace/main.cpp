//Toba Mohaqqeq
//COMSC 210
//lab-34

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <functional>
#include <string>

using namespace std;

const int SIZE = 9;

struct Edge {
    int src, dest, weight;
};

typedef pair<int, int> Pair;  


class Graph {
public:

vector<vector<Pair>> adjList;

    // Graph Constructor
    Graph(const vector<Edge> &edges) {
        adjList.resize(SIZE);

        for (auto &e : edges) {
            adjList[e.src].push_back({e.dest, e.weight});
            adjList[e.dest].push_back({e.src, e.weight});
        }
    }

    // Print the graph's adjacency list
    void printGraph() const {
        cout << "Graph's adjacency list:" << endl;
        for (int i = 0; i < SIZE; i++) {
            cout << i << " --> ";
            for (auto  &p : adjList[i]){
                cout << "(" << p.first << ", " << p.second << ") ";
        }
            cout << endl;

    }
}

void dfs(int start) const {
    vector<bool> visited(SIZE, false);
    stack<int> st;

    visited[start] = true;
    st.push(start);

    cout << "DFS Starting from vertex " << start << ":\n";

    while (!st.empty()){
        int v = st.top();
        st.pop();
        cout << v << " ";

        for (auto &edge : adjList[v]){
            int u = edge.first;
            if (!visited[u]){
                visited[u] = true;
                st.push(u);
            }
        }
    }
    cout << endl;
}

void bfs(int start) const{
    vector<bool> visited(SIZE, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);
    
    cout << "BFS Starting from vertex " << start << ":\n";

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (auto &edge : adjList[v]){
            int u = edge.first;
            if (!visited[u]){
                visited[u] = true;
                q.push(u);
            }
        }
    }
    
    cout << endl;
}
void dijkstra(int start) const {
    const int INF = numeric_limits<int>::max();
    vector<int> dist(SIZE, INF);
    dist[start] = 0;

    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    pq.push({0, start});

    while (!pq.empty()){
        int d = pq.top().first; 
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue; 

        for (auto &edge : adjList[u]){
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]){ 
                 dist[v] = dist[u] + w;
                 pq.push({dist[v], v});
            } 
        }
    }
    cout << "Shortest paths from node " << start << ":\n";
        for (int i = 0; i < SIZE; ++i){
            cout << start << " -> " << i << " : ";
            if (dist[i] == INF) cout << "unreachable";
            else cout << dist[i] << "\n";

        }
     }

        void minimumSpanningTree() const {
            const int INF = numeric_limits<int>::max();
            int n = adjList.size();

            vector<int> key(n, INF);
            vector<int> parent(n, -1);
            vector<bool> inMST(n, false);

                 key[0] = 0;
            
            for (int count = 0; count < n - 1; ++count){
                int u = -1;
                int minkey = INF;

                for (int v = 0; v < n; ++v){
                    if (!inMST[v] && key[v] < minkey){
                        minkey = key[v];
                        u = v;
                    }
                }
                
                if (u == -1) break;
                inMST[u] = true;

                for (auto &edge : adjList[u]){
                    int v = edge.first;
                    int w = edge.second;

                     if (!inMST[v] && w < key[v]){
                         key[v] = w;
                         parent[v] = u;
                     }
                }
            }
                cout << "Minimum spanning Tree edges:\n"; 
                for (int v = 1; v < n; ++v){
                    if (parent[v] != -1){
                        cout << "Edge: " << parent[v] << " - " << v << " Weight: " << key[v] << " units\n";
                    }
                }
            }
            
    
};

void printTransitNetwork(const Graph &graph, const vector<string> &names){
     cout << " City Transit Network Topology:\n";
    cout << "=================================\n";
    
for (int i=0; i < (int)graph.adjList.size(); ++i){
    cout << "Station " << i << " (" << names[i] << ") connects to:\n";

    for (auto &edge : graph.adjList[i]){
        int neighbor = edge.first;
        int weight = edge.second;
        
        cout << "→ station " << neighbor << " (" << names[neighbor] << ") "  << "- travel time: " << weight << "minutes\n";

}
    cout << endl; 
 }
}

int main() {
    vector<Edge> edges = {
    {0,1,8},{0,2,21},{1,2,6},{1,3,5},{1,4,4},{2,7,11},{2,8,8},{3,4,9},{5,6,10},{5,7,15},{5,8,5},{6,7,3},{6,8,7}
    };
    

    // Creates graph
    Graph g(edges);

    vector<string> names =
    {
    "Central Station", "North Station",
    "East Station", "West Station",
    "Museum District", "Airport Terminal", "Tech Park", "University Campus", "Stadium"
}; 
    g.printGraph();
    g.dfs(0);
    g.bfs(0);
    g.dijkstra(0);
    
cout << "\n=== Transit Newtwork == \n";
    printTransitNetwork(g, names);
    
    return 0;
}
