#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

#define MaxV 100

vector<int> graph;

bool visited[MaxV];

struct Graph
{
    // adj[u] 存放u能到达的所有邻接点
    vector<int> adj[MaxV];
    int vertexNum;
    int edgeNum;
    Graph() : vertexNum(0), edgeNum(0) {}
};

void InitGraph(Graph *g)
{
    for (int i = 0; i < MaxV; ++i)
    {
        g->adj[i].clear();
    }
    g->vertexNum = 0;
    g->edgeNum = 0;
}

// 无向图加边 u <-> v
void AddEdge(Graph *g, int u, int v)
{
    g->adj[u].push_back(v);
    g->adj[v].push_back(u);
    g->edgeNum++;
}

// 有向图加边 u -> v
void AddDirectEdge(Graph *g, int u, int v)
{
    g->adj[u].push_back(v);
    g->edgeNum++;
}

int GetDegree(Graph *g, int u)
{
    return g->adj[u].size();
}

void ResetVisited()
{
    fill(visited, visited + MaxV, false);
}

void DFS(Graph *g, int u)
{
    graph.push_back(u);
    visited[u] = true;
    for (int v : g->adj[u])
    {
        if (!visited[v])
        {
            DFS(g, v);
        }
    }
}

void DFS_Stack(Graph* g, int start){
    stack<int> st;
    st.push(start);
    visited[start] = true;
    while(!st.empty()){
        int u = st.top();
        st.pop();
        graph.push_back(u);
        for(int i = g->adj[u].size() - 1; i >= 0; --i){
            int v = g->adj[u][i];
            if(!visited[v]){
                st.push(v);
                visited[v] = true;
            }
        }
    }
}


void BFS(Graph *g, int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        graph.push_back(u);
        for (int v : g->adj[u])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

int main()
{
    Graph *g = new Graph;
    InitGraph(g);
    g->vertexNum = 5;
    AddEdge(g, 0, 1);
    AddEdge(g, 0, 2);
    AddEdge(g, 1, 3);
    AddEdge(g, 2, 4);

    graph.clear();
    ResetVisited();
    DFS(g, 0);
    for(int g : graph){
        cout << g << " ";
    }
    cout << endl;

    graph.clear();
    ResetVisited();
    DFS_Stack(g, 0);
    for(int g : graph){
        cout << g << " ";
    }
    cout << endl;

    graph.clear();
    ResetVisited();
    BFS(g, 0);
    for(int g : graph){
        cout << g << " ";
    }
    cout << endl;

    delete g;

    return 0;
}