#include "graphmatrix.h"

GraphMatrix::GraphMatrix(int n)
{
    this->adjMatrix.reserve(n);

    for(auto line : this->adjMatrix)
        line.reserve(n);
    
    initialize(n);
}

void GraphMatrix::InsertVertex(int a, int b, float value)
{
    this->adjMatrix[a][b] = value;
}

void GraphMatrix::initialize(int n)
{
    std::vector<float> aux(n, std::numeric_limits<float>::infinity());
    
    for(int i = 0; i < n; i++)
        this->adjMatrix.emplace_back(aux);

    for(int i = 0; i < n; i++)
        this->adjMatrix[i][i] = 0;
}

void GraphMatrix::ShowGraph()
{
    printf("size = %d\n\n", (int)this->adjMatrix.size() );
    for(int i = 0; i < this->adjMatrix.size(); i++)
    {
        for(int j = 0; j < this->adjMatrix[i].size(); j++)
        {
            if(j == 0)
                printf("|");

            printf(" %d -> %d: %5.2f |", i, j, this->adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}