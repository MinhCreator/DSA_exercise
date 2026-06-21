#include <bits/stdc++.h>
using namespace std;

int main()
{

    const int n = 7;

    string vertex[] = {"A", "B", "C", "D", "E", "F", "G"};

    int adjacencyMatrix[n][n] = {0};

    int weight[n][n] = {0};

    auto addEdge = [&](int u, int v, int w)
    {
        adjacencyMatrix[u][v] = adjacencyMatrix[v][u] = 1;
        weight[u][v] = weight[v][u] = w;
    };

    addEdge(0, 1, 6);
    addEdge(0, 3, 4);
    addEdge(1, 2, 7);
    addEdge(1, 3, 8);
    addEdge(1, 4, 6);
    addEdge(2, 4, 4);
    addEdge(3, 4, 14);
    addEdge(3, 5, 5);
    addEdge(4, 5, 7);
    addEdge(4, 6, 8);
    addEdge(5, 6, 10);

    cout << "Adjacency Matrix\n";

    for (int i = 0; i < n; i++)
    {

        cout << vertex[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // cout << vertex[i] << " ";
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nAdjacency List\n";

    for (int i = 0; i < n; i++)
    {
        cout << vertex[i] << ": ";
        for (int j = 0; j < n; j++)
            if (adjacencyMatrix[i][j])
                cout << vertex[j] << " ";
        cout << endl;
    }

    cout << "\nWeighted Matrix\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(3) << weight[i][j];
        cout << endl;
    }

    return 0;
}