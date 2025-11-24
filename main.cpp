//Toba Mohaqqeq
//COMSC 210
//lab-34

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int SIZE = 7;

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
    // Creates a vector of graph edges/weights
    vector<Edge> edges = {
        // (x, y, w) —> edge from x to y having weight w
        {0,1,12},{0,2,8},{0,3,21},{2,3,6},{2,6,2},{5,6,6},{4,5,9},{2,4,4},{2,5,5}
    };
    

    // Creates graph
    Graph g(edges);
    g.printGraph();
    g.dfs(0);
    g.bfs(0);

    return 0;
}
