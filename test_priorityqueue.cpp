#include "priorityqueue.h"
#include <cstdio>
#include <cassert>
#include <iostream>

void test_1() {
  PriorityQueue<int> pq;
  pq.push(3);
  assert(pq.top() == 3);

  pq.push(500);
  assert(pq.top() == 500);

  pq.push(100);
  assert(pq.top() == 500); // 20 should remain the top
}

void test_2() {
  PriorityQueue<int> pq;
  pq.push(1);
  pq.push(2);
  pq.push(3);
  pq.push(4);

  assert(pq.size() == 4);

  pq.pop();
  assert(pq.top() == 3);
  assert(pq.size() == 3);

  pq.pop();
  assert(pq.top() == 2);
  assert(pq.size() == 2);

  pq.pop();
  assert(pq.size() == 1);

  pq.pop();
  assert(pq.size() == 0);
}

void test_3() {
  PriorityQueue<int> pq;
  pq.push(1);
  pq.push(2);
  pq.push(3);

  PriorityQueue<int> copy = pq;
  assert(copy.size() == pq.size());
  assert(copy.top() == pq.top());

  pq.pop();
  assert(copy.top() == 3); // Copy should remain unchanged
  assert(pq.top() == 2);
  assert(copy.size() == 3);
  assert(pq.size() == 2);
}

void test_4() {
  PriorityQueue<int> pq;
  pq.push(2);
  pq.push(3);

  PriorityQueue<int> assign;
  assign.push(1);

  assign = pq;
  assert(assign.size() == pq.size());
  assert(assign.top() == pq.top());

  pq.pop();
  assert(assign.top() == 3); // Assignment should remain unchanged
  assert(assign.size() == 2);
}

void comprehensive_test() {
  PriorityQueue<int> pq;
  pq.push(3);
  pq.push(1);
  pq.push(2);
  pq.push(5);

  assert(pq.top() == 5);
  pq.pop();
  assert(pq.top() == 3);
  pq.pop();
  assert(pq.top() == 2);
  pq.pop();
  assert(pq.top() == 1);
  pq.pop();
  assert(pq.size() == 0);

  PriorityQueue<int> pq2;
  pq2.push(5);
  pq2.push(15);

  PriorityQueue<int> pq3 = pq2;
  assert(pq3.top() == 15);

  PriorityQueue<int> pq4;
  pq4 = pq2;
  assert(pq4.top() == 15);
}

void test_5() {
  PriorityQueue<int> pq5;
  assert(pq5.size() == 0);
  pq5.pop();
  assert(pq5.size() == 0);
}

void test_6() {
  PriorityQueue<int> pq6;
  pq6.push(1001);
  pq6.push(1652);
  pq6.push(1234);

  PriorityQueue<int> copy = pq6;

  pq6.push(1655);
  pq6.push(2000);

  assert(copy.top() == 1652);
  assert(copy.size() == 3);

  assert(pq6.top() == 2000);
  assert(pq6.size() == 5);
}

void test_7() {
  PriorityQueue<int> pq1;
  PriorityQueue<int> pq2;

  pq1.push(109944);
  pq1.push(109945);
  pq1.push(100000);

  pq2 = pq1;

  pq1.push(109946);

  assert(pq1.top() == 109946);
  pq1.pop();
  assert(pq1.top() == 109945);

  assert(pq2.top() == 109945);
  pq2.pop();
  assert(pq2.top() == 109944);
  pq2.pop();
  assert(pq2.top() == 100000);
  pq2.pop();
  assert(pq2.size() == 0);

  pq1.pop();
  assert(pq1.top() == 109944);
  pq1.pop();
  assert(pq1.size() == 1);
}


int main(int argc, char* argv[])
{
  // // STEVENS TEST CODE
  // // Here's some quick test code to get you started.  You'll need much more
  // // thorough testing, of course.

  // PriorityQueue<int> q;

  // // Push three elements onto the front
  // q.push(1);
  // q.push(2);
  // q.push(3);

  // // Make a copy
  // PriorityQueue<int> another = q;

  // // Push some more elements onto the front of the original
  // q.push(4);
  // q.push(5);

  // while(q.size() > 0){
  //   printf("%d ", q.top());
  //   q.pop();
  // }
  // printf("\n");

  // while(another.size() > 0){
  //   printf("%d ", another.top());
  //   another.pop();
  // }
  // printf("\n");
  
  test_1();
  test_2();
  test_3();
  test_4();
  comprehensive_test();
  test_5();
  test_6();
  test_7();

  std::cout << "All test cases passed!" << std::endl;

  return(0);
}

