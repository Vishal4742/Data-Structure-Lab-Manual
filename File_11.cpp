//Program to implement a graph and traverse it using Breadth First Search
#include <iostream>
using namespace std;

#define MAX 10 
class Queue {
private:
    int arr[MAX];  
    int front, rear;  

public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(int value) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        arr[++rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        int value = arr[front];
        if (front == rear) { 
            front = rear = -1;
        } else {
            front++;
        }
        return value;
    }
};

class Graph {
private:
    int adjMatrix[MAX][MAX];  
    int numVertices;  

public:
    Graph(int vertices) {
        numVertices = vertices;
        for (int i = 0; i < numVertices; i++)
            for (int j = 0; j < numVertices; j++)
                adjMatrix[i][j] = 0;
    }

    void addEdge(int src, int dest) {
        adjMatrix[src][dest] = 1;  
        adjMatrix[dest][src] = 1;  
    }

    void displayMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void BFS(int startVertex) {
        bool visited[MAX] = {false};  
        Queue q;  

        visited[startVertex] = true;
        q.enqueue(startVertex);

        cout << "\nBFS Traversal starting from vertex " << startVertex << ": ";

        while (!q.isEmpty()) {
            int vertex = q.dequeue();
            cout << vertex << " ";

            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                    q.enqueue(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }
};

int main() {
    cout << "Vishal Kumar\n0126AL231142\n3rd Sem AIML\n";

    int vertices, edges;
    cout << "\nEnter number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (source destination):\n";
    for (int i = 0; i < edges; i++) {
        int src, dest;
        cin >> src >> dest;
        g.addEdge(src, dest);
    }

    g.displayMatrix();

    int startVertex;
    cout << "\nEnter starting vertex for BFS: ";
    cin >> startVertex;

    g.BFS(startVertex);

    return 0;
}
