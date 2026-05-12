#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

#define MaxV 100

vector<int> matrixGraph;

bool visited[MaxV];

struct MatrixGraph
{
    int edge[MaxV][MaxV];
    int vertexNum;
    int edgeNum;

    MatrixGraph()
    {
        for (int i = 0; i < MaxV; ++i)
        {
            for (int j = 0; j < MaxV; ++j)
            {
                edge[i][j] = 0;
            }
        }
        vertexNum = 0;
        edgeNum = 0;
    }
};

void InitMatrixGraph(MatrixGraph *mg)
{
    for (int i = 0; i < MaxV; ++i)
    {
        for (int j = 0; j < MaxV; ++j)
        {
            mg->edge[i][j] = 0;
        }
    }
    mg->vertexNum = 0;
    mg->edgeNum = 0;
}

void AddEdgeMatrix(MatrixGraph *mg, int u, int v)
{
    mg->edge[u][v] = 1;
    mg->edge[v][u] = 1;
    mg->edgeNum++;
}

void AddDirectEdgeMatrix(MatrixGraph *mg, int u, int v)
{
    mg->edge[u][v] = 1;
    mg->edgeNum++;
}

int GetDegreeMatrix(MatrixGraph *mg, int u)
{
    int cnt = 0;
    for (int i = 0; i < mg->vertexNum; ++i)
    {
        if (mg->edge[u][i] == 1)
        {
            cnt++;
        }
    }
    return cnt;
}

void ResetVisited()
{
    fill(visited, visited + MaxV, false);
}

void DFSMatrix(MatrixGraph *mg, int u)
{
    matrixGraph.push_back(u);
    visited[u] = true;
    for (int i = 0; i < mg->vertexNum; ++i)
    {
        if (mg->edge[u][i] == 1 && visited[i] == false)
        {
            DFSMatrix(mg, i);
        }
    }
}

int CountConnected1(MatrixGraph *mg)
{
    int cnt = 0;
    for (int i = 0; i < mg->vertexNum; ++i)
    {
        if (!visited[i])
        {
            cnt++;
            DFSMatrix(mg, i);
        }
    }
    return cnt;
}

void DFSMatrixStack(MatrixGraph *mg, int start)
{
    stack<int> st;
    st.push(start);
    visited[start] = true;
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        matrixGraph.push_back(u);
        for (int i = mg->vertexNum - 1; i >= 0; --i)
        {
            if (mg->edge[u][i] == 1 && visited[i] == false)
            {
                st.push(i);
                visited[i] = true;
            }
        }
    }
}

int CountConnected2(MatrixGraph *mg)
{
    int cnt = 0;
    for (int i = 0; i < mg->vertexNum; ++i)
    {
        if (!visited[i])
        {
            cnt++;
            DFSMatrixStack(mg, i);
        }
    }
    return cnt;
}

void BFSMatrixQueue(MatrixGraph *mg, int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        matrixGraph.push_back(u);
        for (int i = 0; i < mg->vertexNum; ++i)
        {
            if (mg->edge[u][i] == 1 && visited[i] == false)
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int CountConnected3(MatrixGraph *mg)
{
    int cnt = 0;
    for (int i = 0; i < mg->vertexNum; ++i)
    {
        if (!visited[i])
        {
            cnt++;
            BFSMatrixQueue(mg, i);
        }
    }
    return cnt;
}

int main()
{
    MatrixGraph *mg = new MatrixGraph;

    InitMatrixGraph(mg);
    mg->vertexNum = 5;
    AddEdgeMatrix(mg, 0, 1);
    AddEdgeMatrix(mg, 0, 2);
    AddEdgeMatrix(mg, 1, 3);
    AddEdgeMatrix(mg, 2, 4);

    matrixGraph.clear();
    ResetVisited();
    DFSMatrix(mg, 0);
    for (int x : matrixGraph)
    {
        cout << x << " ";
    }
    cout << endl;

    matrixGraph.clear();
    ResetVisited();
    DFSMatrixStack(mg, 0);
    for (int x : matrixGraph)
    {
        cout << x << " ";
    }
    cout << endl;

    matrixGraph.clear();
    ResetVisited();
    BFSMatrixQueue(mg, 0);
    for (int x : matrixGraph)
    {
        cout << x << " ";
    }
    cout << endl;

    delete mg;

    return 0;
}
