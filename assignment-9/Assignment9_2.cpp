
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[7];
bool visited[7];

string vertex[]={"A","B","C","D","E","F","G"};

void BFS(int start){

    queue<int> queueInit;

    visited[start]=true;
    queueInit.push(start);

    while(!queueInit.empty()){

        int u=queueInit.front();
        queueInit.pop();

        cout<<vertex[u]<<" ";

        for(int v:adj[u]){
            if(!visited[v]){
                visited[v]=true;
                queueInit.push(v);
            }
        }
    }
}

void DFS(int u){

    visited[u]=true;
    cout<<vertex[u]<<" ";

    for(int v:adj[u]){
        if(!visited[v])
            DFS(v);
    }
}

int main(){

    adj[0]={1,3};
    adj[1]={0,2,3,4};
    adj[2]={1,4};
    adj[3]={0,1,4,5};
    adj[4]={1,2,3,5,6};
    adj[5]={3,4,6};
    adj[6]={4,5};

    cout<<"BFS from D:\n";
    BFS(3);

    fill(visited,visited+7,false);

    cout<<"\n\nDFS from B:\n";
    DFS(1);

    return 0;
}