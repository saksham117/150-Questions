#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int main(){

    int V;
    int E;

    cout<<"Enter the number of vertices: ";
    cin>>V;
    
    cout<<"Enter the number of edges: ";
    cin>>E;

    unordered_map<int, vector<int> *> adjList;

    // creating the template for adjancey list
    for(int i = 0; i < V; i++)
    {   
        // I miss this line often, after the eqal to one
        vector<int> * v = new vector<int>();
        adjList[i] = v;
    }

    for(int i = 0; i < E; i++)
    {   
        int v1,v2;

        cout<<"Enter the first vertex: ";
        cin>>v1;
    
        cout<<"Enter the second vertex: ";
        cin>>v2;

        adjList[v1]->push_back(v2);
        adjList[v2]->push_back(v1);
    }

    return 0;
}

// THIS IS FOR UNDIRECTED GRAPSH
// IF GRAPHS ARE GOUNG TO BE DIRECTED WE ARE JUST GOING TO PUSHBACK INTO THE VECOR FROM V1 TO V2, AND NOT DO V2 AND V1
