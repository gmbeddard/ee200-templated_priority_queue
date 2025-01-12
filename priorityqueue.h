#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <stdexcept>

template <typename PQ> 

class PriorityQueue{
  public:
    PriorityQueue();
    ~PriorityQueue();

    // copy constructor
    PriorityQueue(const PriorityQueue &copy);

    // operator overload for deep copying!
    PriorityQueue& operator=(const PriorityQueue &copy);
    
    // returns the current number of elements in the PriorityQueue
    int size() const;

    // returns the first (highest value) item in the PriorityQueue (O(1))
    // okay, so this priority queue is set up such that the first element of the queue is the greates element
    // standard C++11 makes this a const so i will too
    PQ top() const;

    // should add the element x to the PriorityQueue
    void push(PQ x);

    // should remove the top item in the PriorityQueue (O(1))
    void pop();
  
  private:
    std::vector<PQ> heap;  
  
};

// .cpp style implementation timeeeeeee
// follows template: 
    // template <typename T>
    // funct_type class_name<T>::funct_name(arguments) : initializer_list_vals {}
// example from array.h (HW 12)
    // template <typename ArrTemp> Array<ArrTemp>::Array() : size_arr(0), mem_space(1), mem_ptr(new ArrTemp[mem_space]) {}

template <typename PQ>
PriorityQueue<PQ>::PriorityQueue() {
  heap = std::vector<PQ>();
}

template <typename PQ>
PriorityQueue<PQ>::~PriorityQueue() {
  heap.clear();                         // from std vector library, clears vector and sets size to 0
}

template <typename PQ>
PriorityQueue<PQ>::PriorityQueue(const PriorityQueue &copy) {
  heap = copy.heap;
}

template <typename PQ>
PriorityQueue<PQ>& PriorityQueue<PQ>::operator=(const PriorityQueue &copy) {
  if (this != &copy) {
    heap = copy.heap;
  }
  return *this;  
}

template <typename PQ>
int PriorityQueue<PQ>::size() const {
  return heap.size();
}

template <typename PQ>
PQ PriorityQueue<PQ>::top() const {
  if (heap.empty()) {
    throw std::runtime_error("error: priorityqueue is empty!");
  }
  // if heap is not empty, return first element!
  return heap[0];  
}

template <typename PQ>
void PriorityQueue<PQ>::push(PQ x) {
  // standard cpp seems to add the value at the end of the heap (complete tree) and then do a check/swap to correctly order added value
    // seems like we can use vector's push_back function to add value @ end of vector
    // then we will need to find the parent node, loop through heap vector, if value of heap is greater than parent, replace the values with vector:swap()
    // oh wait, vector.swap doesn't work how i want it to. stackoverflow has a solution tho. std::swap
  heap.push_back(x);
  int index = heap.size() - 1;

  while (index > 0) {
    int parent_node = (index - 1) / 2;
    if (heap[index] > heap[parent_node]) {
      std::swap(heap[index], heap[parent_node]);
      index = parent_node;
    }
    else {
      break;
    }
  }
}

// remove top element in queue
template <typename PQ>
void PriorityQueue<PQ>::pop() {
  // avoid undefined behavior
  if (heap.empty()) {
    //throw std::runtime_error("error: priorityqueue is empty!");
    return;
  }
  
  // access last element in heap, set it as the first element
  heap[0] = heap.back();
  // delete the duplicate of heap[0] to remove any uneceesary duplicates 
  heap.pop_back();

  // now we have to organize the heap
  int index = 0;
  int size = heap.size();

  // use a while true loop to iterate through heap's , once things are reordered properly, we break with an else statement!
  while (true) {
    // odd numbered index for left
    int left_node = 2 * index + 1;
    // ecen numebd index for right side, we incremenent each 
    int right_node = 2 * index + 2;
    // largest will just point to the current node's index so we can swap indexes as needed
    int largest = index;

    // check if left node is in the bounds of the heap vector and
    // if left node is greater than the largest value, make left node the new largest
    if (left_node < size && heap[left_node] > heap[largest]) {
      largest = left_node;
    }

    // NOT an else if satement because a heap is a ~*complete tree*~ (from class notes). basically if the left branch is greater than parent,
    // the left tree will always be greater than right.
    // same as left node for right node ^
    if (right_node < size && heap[right_node] > heap[largest]) {
      largest = right_node;
    }

    // update index. 
    // if largest is not = to current index, update index to the actual largest index
    // swap index and the value of largest to the new largest index and value
    // this will continue the loop to further adjust the subtree rooted at the new index position 
    if (largest != index) {
      std::swap(heap[index], heap[largest]);
      index = largest;
    }

    // heap should be reorded so we break the while true loop!
    else {
      break;
    } 
  }
}


#endif