//Toba Mohaqqeq
//COMSC 210
//lab-34

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int SIZE = 9;

struct Edge {
    int src, dest, weight;
};

typedef pair<int, int> Pair;  // Creates alias 'Pair' for the pair<int,int> data type

class Graph {
public:
    // a vector of vectors of Pairs to represent an adjacency list
    vector<vector<Pair>> adjList;

    // Graph Constructor
    Graph(const vector<Edge> &edges) {
        adjList.resize(SIZE);

        for (auto &e : edges) {
            adjList[e.src].push_back({e.dest, e.weight});
            adjList[e.dest].push_back({e.src, e.weight});
        }
    }
           
void printTransitNetwork(const Graph &graph, const vector<string> &names){
     cout << " City Transit Network Topology:\n";
    cout << "=================================\n";

    for (auto &edge : graph.adjList[i]){
        int neighbor = edge.first;
        int weight = edge.sedcond;

        cout << "→ station " << neighbor << " (" << names[neighbor] << ") "  << "- travel time: "<< weight << "minutes\n";
    
}
    cout << endl; 
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
};
int main() {
    vector<Edge> edges = {
    {0,1,8},{0,2,21},{1,2,6},{1,3,5},{1,4,4},{2,7,11},{2,8,8},{3,4,9},{5,6,10},{5,7,15},{5,8,5},{6,7,3},{6,8,7}
    };
    

    // Creates graph
    Graph g(edges);
    g.printGraph();
    g.dfs(0);
    g.bfs(0);

    return 0;
}
