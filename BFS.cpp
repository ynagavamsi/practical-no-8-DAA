#include <iostream>
using namespace std;

int graph[20][20];
int visited[20];
int n;

void BFS(int start) {
    int queue[20];
    int front = 0;
    int rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int vertex = queue[front++];

        cout << vertex << " ";

        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int edges;

    cout << "Enter number of vertices: ";
    cin >> n;

    // Initialize graph
    for (int i = 0; i < n; i++) {
        visited[i] = 0;

        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):" << endl;

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "BFS Traversal: ";
    BFS(start);

    return 0;
}
