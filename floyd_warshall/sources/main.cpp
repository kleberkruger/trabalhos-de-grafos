
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

    return 0;
}
