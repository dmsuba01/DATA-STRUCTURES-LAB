// Graph ADT using Adjacency List
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class GraphList {
private:
    int vertices;
    vector<list<int>> adjList;

public:
    GraphList(int v) {
        vertices = v;
        adjList.resize(vertices);
    }

    void insertEdge(int src, int dest) {
        if (src < vertices && dest < vertices) {
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
    }

    void deleteEdge(int src, int dest) {
        if (src < vertices && dest < vertices) {
            adjList[src].remove(dest);
            adjList[dest].remove(src);
        }
    }

    bool searchEdge(int src, int dest) {
        if (src >= vertices || dest >= vertices) return false;
        for (list<int>::iterator it = adjList[src].begin(); it != adjList[src].end(); ++it) {
            if (*it == dest) return true;
        }
        return false;
    }

    void display() {
        cout << "Adjacency List:\n";
        for (int i = 0; i < vertices; i++) {
            cout << i << ": ";
            for (list<int>::iterator it = adjList[i].begin(); it != adjList[i].end(); ++it) {
                cout << *it << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    GraphList graph(5);
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
