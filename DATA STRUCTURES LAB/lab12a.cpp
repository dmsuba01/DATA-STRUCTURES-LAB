// Graph ADT using Adjacency Matrix
#include <iostream>
#include <vector>
using namespace std;

class GraphMatrix {
private:
    int vertices;
    vector<vector<int>> adjMatrix;

public:
    GraphMatrix(int v) {
        vertices = v;
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
    }

    void insertEdge(int src, int dest) {
        if (src < vertices && dest < vertices) {
            adjMatrix[src][dest] = 1;
            adjMatrix[dest][src] = 1;
        }
    }

    void deleteEdge(int src, int dest) {
        if (src < vertices && dest < vertices) {
            adjMatrix[src][dest] = 0;
            adjMatrix[dest][src] = 0;
        }
    }

    bool searchEdge(int src, int dest) {
        return adjMatrix[src][dest] == 1;
    }

    void display() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    GraphMatrix graph(5);
    int choice, src, dest;
    do {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter source and destination: ";
                cin >> src >> dest;
                graph.insertEdge(src, dest);
                break;
            case 2:
                cout << "Enter source and destination: ";
                cin >> src >> dest;
                graph.deleteEdge(src, dest);
                break;
            case 3:
                cout << "Enter source and destination: ";
                cin >> src >> dest;
                if (graph.searchEdge(src, dest))
                    cout << "Edge exists.\n";
                else
                    cout << "Edge does not exist.\n";
                break;
            case 4:
                graph.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
