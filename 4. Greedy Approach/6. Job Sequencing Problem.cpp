// sort the array via descending order of profit
// find the maximum deadline amongst the jobs and then create an array of that much size 
// start from the sorted array and push this job into the index corresponding to its deadline in the array we created
// if that index is occupied, search back from there and find if an index is empty
// if empty, push it
// else continue
// if no of jobss == max deadline return and no need to check further

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<unordered_set>

using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
class Solution 
{
    public:

    // custom comparator
    bool compare(Job a, Job b){
        return a.profit > b.profit;
    }

    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr + n, compare); // sort according to profit 

        int maxDeadline = 0;

        // finding the maximum deadline till which we can do the last task
        for(int i = 0; i < n; i++){

            if (arr[i].dead > maxDeadline){
                maxDeadline = arr[i].dead;
            }
        }

        // created an array of size maxdeadline and intialized each value as -1
        int* allJobs = new int[maxDeadline];
        for(int i = 0; i < maxDeadline; i++){
            allJobs[i] = -1;
        }

        int numberOfJobs = 0;
        int profit = 0;

        for(int i = 0; i < n; i++){

            if(numberOfJobs == maxDeadline){ // this is one small optimization I thought of
                break;
            }

            // if the last possible deadline is present fill there
            if(allJobs[arr[i].dead - 1] == -1){
                allJobs[arr[i].dead - 1] = arr[i].id;
                numberOfJobs += 1; 
                profit += arr[i].profit;
            // eklse iterate from the last and see at what last time we can do job
            }else{

                for(int j = arr[i].dead - 2; j >= 0; j--){

                    if(allJobs[j] == -1){
                        allJobs[j] = arr[i].id;
                        numberOfJobs += 1; 
                        profit += arr[i].profit;
                        break;
                    }
                }
            }

        }

        vector<int> output;
        output.push_back(numberOfJobs);
        output.push_back(profit);
        return output;

        
    } 
};
