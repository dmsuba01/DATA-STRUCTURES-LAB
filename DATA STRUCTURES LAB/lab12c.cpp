#include <iostream>
using namespace std;

#define MAX 100
#define INF 99999

class Graph {
    int cost[MAX][MAX];
    int V;

public:
    Graph(int v) {
        V = v;
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                cost[i][j] = INF;
    }

    void addEdge(int u, int v, int w) {
        u--; v--; // convert to 0-based index
        cost[u][v] = w;
        cost[v][u] = w;
    }

    void displayGraph() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (cost[i][j] == INF)
                    cout << "INF ";
                else
                    cout << cost[i][j] << " ";
            }
            cout << endl;
        }
    }

    void prims() {
        int selected[MAX] = {0};
        int no_edge = 0;
        int start = -1;

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (cost[i][j] != INF) {
                    start = i;
                    break;
                }
            }
            if (start != -1) break;
        }

        if (start == -1) {
            cout << "Graph is empty or disconnected.\n";
            return;
        }

        selected[start] = 1;

        cout << "Prim's MST:\n";
        while (no_edge < V - 1) {
            int min = INF, x = -1, y = -1;

            for (int i = 0; i < V; i++) {
                if (selected[i]) {
                    for (int j = 0; j < V; j++) {
                        if (!selected[j] && cost[i][j] < min) {
                            min = cost[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }

            if (x != -1 && y != -1) {
                cout << x + 1 << " - " << y + 1 << " : " << cost[x][y] << endl;
                selected[y] = 1;
                no_edge++;
            } else {
                break;
            }
        }
    }

    int findParent(int parent[], int i) {
        while (parent[i] != i)
            i = parent[i];
        return i;
    }

    void unionSet(int parent[], int i, int j) {
        int a = findParent(parent, i);
        int b = findParent(parent, j);
        parent[a] = b;
    }

    void kruskal() {
        int parent[MAX];
        for (int i = 0; i < V; i++)
            parent[i] = i;

        cout << "Kruskal's MST:\n";
        int edges = 0;

        while (edges < V - 1) {
            int min = INF, u = -1, v = -1;

            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (findParent(parent, i) != findParent(parent, j) && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }

            if (u != -1 && v != -1) {
                cout << u + 1 << " - " << v + 1 << " : " << cost[u][v] << endl;
                unionSet(parent, u, v);
                edges++;
            } else {
                break;
            }
        }

        if (edges < V - 1)
            cout << "Graph is disconnected, MST cannot be formed.\n";
    }

    void dijkstra(int src) {
        src--; // convert to 0-based
        int dist[MAX], visited[MAX];
        for (int i = 0; i < V; i++) {
            dist[i] = INF;
            visited[i] = 0;
        }

        dist[src] = 0;

        for (int count = 0; count < V - 1; count++) {
            int min = INF, u = -1;

            for (int i = 0; i < V; i++) {
                if (!visited[i] && dist[i] < min) {
                    min = dist[i];
                    u = i;
                }
            }

            if (u == -1) break;

            visited[u] = 1;

            for (int v = 0; v < V; v++) {
                if (!visited[v] && cost[u][v] != INF && dist[u] + cost[u][v] < dist[v])
                    dist[v] = dist[u] + cost[u][v];
            }
        }

        cout << "Dijkstra's shortest paths from " << src + 1 << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "To " << i + 1 << " : ";
            if (dist[i] == INF)
                cout << -1 << endl;
            else
                cout << dist[i] << endl;
        }
    }
};

int main() {
    int V, choice;
    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    while (true) {
        cout << "\n1. Add Edge\n2. Display Graph\n3. Prim's Algorithm\n4. Kruskal's Algorithm\n5. Dijkstra's Algorithm\n6. Exit\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int u, v, w;
            cout << "Enter (u v w): ";
            cin >> u >> v >> w;
            g.addEdge(u, v, w);
        }
        else if (choice == 2) {
            g.displayGraph();
        }
        else if (choice == 3) {
            g.prims();
        }
        else if (choice == 4) {
            g.kruskal();
        }
        else if (choice == 5) {
            int src;
            cout << "Enter source vertex: ";
            cin >> src;
            g.dijkstra(src);
        }
        else if (choice == 6) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}