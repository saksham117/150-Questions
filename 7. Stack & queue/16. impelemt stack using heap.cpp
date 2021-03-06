// In priority queue, we assign priority to the elements that are being pushed. 
// A stack requires elements to be processed in Last in First Out manner. The idea is to associate a 
// count that determines when it was pushed. 
// This count works as a key for the priority queue.

// So the implementation of stack uses a priority queue of pairs, with the first element serving as the count
// second as the value and use a maxheap