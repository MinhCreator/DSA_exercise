#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10];
bool visited[10];

void BFS_Tree(int start)
{

    queue<int> queueInit;

    visited[start] = true;
    queueInit.push(start);

    cout << "BFS Tree Edges:\n";

    while (!queueInit.empty())
    {

        int u_vect = queueInit.front();
        queueInit.pop();

        for (int v_vect : adj[u_vect])
        {

            if (!visited[v_vect])
            {

                visited[v_vect] = true;
                queueInit.push(v_vect);

                cout << u_vect << " - " << v_vect << endl;
            }
        }
    }
}

void DFS_Tree(int u_vect)
{

    visited[u_vect] = true;

    for (int v : adj[u_vect])
    {

        if (!visited[v])
        {

            cout << u_vect << " - " << v << endl;

            DFS_Tree(v);
        }
    }
}

int main()
{

    adj[1] = {2, 5};
    adj[2] = {3, 1};
    adj[3] = {2, 4};
    adj[4] = {6, 3, 7, 5};
    adj[5] = {4, 7, 1};
    adj[6] = {7, 4, 8};
    adj[7] = {6, 4, 5, 9};
    adj[8] = {6, 9};
    adj[9] = {7, 8};

    BFS_Tree(3);

    fill(visited, visited + 10, false);

    cout << "\nDFS Tree Edges:\n";

    DFS_Tree(3);

    return 0;
}