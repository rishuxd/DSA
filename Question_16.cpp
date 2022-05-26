// Question 16 

#include <iostream>
using namespace std;

class Graph
{
private:
    bool **adjMatrix;
    int numVertices, counter;

public:
    Graph(int numVertices)
    {
        this->counter = 0;
        this->numVertices = numVertices;
        adjMatrix = new bool *[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            adjMatrix[i] = new bool[numVertices];
            for (int j = 0; j < numVertices; j++)
                adjMatrix[i][j] = false;
        }
    }

    void addEdge(int i, int j)
    {
        adjMatrix[i][j] = true;
        adjMatrix[j][i] = true;
    }

    void toString()
    {
        for (int i = 0; i < numVertices; i++){
            cout << i << " : ";
            for (int j = 0; j < numVertices; j++){
                cout << adjMatrix[i][j] << " ";
            }
            cout << "\n";
        }
    }

    // kCheck
    void kCheck(){
        for (int i = 0; i < numVertices; i++){
            for (int j = 0; j < numVertices; j++){
                if (adjMatrix[i][j]==1){
                    counter=counter+1;
                }
                
            }
        }
        if ((counter/2)==numVertices*(numVertices-1)/2){
            cout<<"Complete Graph "<<endl;
        }
        else{
            cout<<"Incomplete Graph"<<endl;
        }
    }
};

int main()
{
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(0, 3);
    g.addEdge(0, 2);
    g.addEdge(1, 3);


    g.toString();
    g.kCheck();
}