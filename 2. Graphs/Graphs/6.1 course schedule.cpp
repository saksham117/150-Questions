#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:

    void kahn(unordered_map<int, vector<int>*>& graph, int n, int* in, vector<int>& output){

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int i = 0; i < n; i++)
        {
            if(in[i] == 0){
                minHeap.push(i);
            }
        }

        while(!minHeap.empty()){

            int top = minHeap.top();
            minHeap.pop();
            output.push_back(top);

            for(int i = 0; i < graph[top]->size(); i++)
            {
                int node = graph[top]->at(i);
                in[node] -= 1;

                if(in[node] == 0)
                {
                    minHeap.push(node);
                }
            }
        }
        

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>*> graph;
        int* in = new int[numCourses];
        for(int i = 0; i < numCourses; i++){
            
            vector<int>* v = new vector<int>();
            graph[i] = v;
            in[i] = 0;
        }

        for(int i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i][1]]->push_back(prerequisites[i][0]);
            in[prerequisites[i][0]] += 1;
        }

        vector<int> output;
        kahn(graph, numCourses, in, output);

        if(output.size() == numCourses)
        {
            return true;
        }
        else{
            return false;
        }
    }
};