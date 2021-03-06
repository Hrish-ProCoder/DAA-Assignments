//Implement all pairs shortest path using Floyd and Warshall method.

#include <iostream>
#include <climits>
#include <iomanip>
#include <chrono>
using namespace std;
using namespace std::chrono;
#define N 4
#define M INT_MAX
void printPath(int path[][N], int v, int u)
{
    if (path[v][u] == v)
        return;

    printPath(path, v, path[v][u]);
    cout << path[v][u] << " ";
}
void printSolution(int cost[N][N], int path[N][N])
{
    for (int v = 0; v < N; v++)
    {
        for (int u = 0; u < N; u++)
        {
            if (u != v && path[v][u] != -1)
            {
                cout << "Shortest Path from " << v << " -> " << u << " is ("
                     << v << " ";
                printPath(path, v, u);
                cout << u << ")" << endl;
            }
        }
    }
}

void floydWarshall(int adjMatrix[][N])
{
    int cost[N][N], path[N][N];
    for (int v = 0; v < N; v++)
    {
        for (int u = 0; u < N; u++)
        {
            cost[v][u] = adjMatrix[v][u];

            if (v == u)
                path[v][u] = 0;
            else if (cost[v][u] != INT_MAX)
                path[v][u] = v;
            else
                path[v][u] = -1;
        }
    }

    for (int k = 0; k < N; k++)
    {
        for (int v = 0; v < N; v++)
        {
            for (int u = 0; u < N; u++)
            {
                if (cost[v][k] != INT_MAX && cost[k][u] != INT_MAX
                    && cost[v][k] + cost[k][u] < cost[v][u])
                {
                    cost[v][u] = cost[v][k] + cost[k][u];
                    path[v][u] = path[k][u];
                }
            }
        }
    }
    printSolution(cost, path);
}

int main()
{
    
            
    int adjMatrix[N][N] =
    {
        { 9, M, 1, M },
        { 4, 0, 3, M },
        { M, 6, M, 2 },
        { 4, 21, M, 0 }
    };
    auto start = high_resolution_clock::now();
    floydWarshall(adjMatrix);
    auto stop = high_resolution_clock::now();
   
   auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nTime taken by function: "
         << duration.count()<< " microseconds" << endl;

    return 0;
}