
#include "graphmatrix.h"

#define N 5

int main(int argc, char *argv[])
{
    int n, m, a, b;
    float value;
    scanf("%d", &n);
    scanf("%d", &m);

    GraphMatrix graph(n);

    while(m--)
    {
        scanf("%d %d %f", &a, &b, &value);
        graph.InsertEdge(a, b, value);
    }

    graph.ShowGraph();

    std::vector<std::vector<float>> res(graph.adjMatrix);

    graph.FloydWarshall(res);

    for(int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < res.size(); j++)
        {
            if(j == 0)
                printf("|");

            printf(" %5.2f ", res[i][j]);
        
            if(j == res.size() - 1)
                printf("|");
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}
