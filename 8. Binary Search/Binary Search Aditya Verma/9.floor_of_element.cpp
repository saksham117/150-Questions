// find floor of an element in sorted arrat

// floor of an element is the greates integer smaller than or equal to that number

// but what sense does it make in this problem

// arr 1 2 3 4 8 10 10 12 19
// element is 5

// so the question says that if 5 is present, return it
// else return the greatest integer smaller than this
// which in this case is 4

// so basically we will apply buinary serach
// and mantain a candidate floor

// if mid is the same element, return
// else if mid > key
// serach in left and do not store it as canduadate

// if mid < key
// serach in right
// store it as a candidate

// finally return the candidate when low > high
// also update canddidate when it is greater than prev candidate but less than key


// so simple problem

// Function to find floor of K
// arr[]: integer array of size N
// N: size of arr[]
// K: element whose floor is to find
int findFloor(long long int arr[], int N, long long int K) {
    
    //Your code here
    int low = 0;
    int high = N-1;
    int floor = -1;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] == K)
        {
            return mid;
        }
        else if(arr[mid] > K)
        {
            high = mid -1;
        }
        else{
            floor = mid;
            low = mid+1;
        }
    }

    return floor;


}
