/***********************************************************
   heap.cpp -- Implementation File for Basic Heap-of-Ints
************************************************************/
#include "heap.h"

// Constructors and Destructor

Heap::Heap(void){ // New empty Heap with default capacity.
   h_capacity = 10;
   A = new int[h_capacity];
   h_size = 0;
}

Heap::Heap(int c){ // New empty Heap with capacity c.
   h_capacity = c;
   A = new int[h_capacity];
   h_size = 0;
}

Heap::Heap(int * B, int s, int c){ // New Heap with capacity c containing first s elements of B.
   h_capacity = c;
   A = new int[h_capacity];
   h_size = 0;
   if(s > c) return;//error
   for(int i = 0; i < s; i++)
   {
      A[i] = B[i];
      h_size ++;
   }
   make_heap();
}

Heap::Heap( const Heap & H ){ // Copy constructor.
   h_capacity = H.h_capacity;
   h_size = H.h_size;
   A = new int[h_capacity];
   for(int i = 0; i < H.h_capacity; i++)
      A[i] = H.A[i];
}

// Destructor
Heap::~Heap(){
   delete[] A;
}


// Operators
Heap Heap::operator+( const Heap & Right_H)const { 
   // New Heap with combined contents and size of operands.
   int new_capacity = h_capacity + Right_H.h_capacity ;
   Heap New_H( new_capacity );
   for(int i = 0; i < h_size; i++)
      New_H.insert(A[i]);
   Heap temp_H = Right_H;
   while(!temp_H.empty())
   {
      int temp = temp_H.extract_min();
      New_H.insert(temp);
   }
  return New_H ;
}

// Modifiers

void Heap::insert(int x){
// Inserts x into the heap.
   A[h_size] = x;
   trickle_up(h_size);
   h_size ++;
}

// Repairs the heap ordering invariant after adding a new element.
// Initial call should be trickle_up(h_size-1).
void Heap::trickle_up(int v){
   int parent = (v-1)/2;
   if(parent>=0)
   {
      if(A[parent] > A[v])
      {
         swap(A[parent],A[v]);
         trickle_up(parent);
      }     
   }
}

// Removes and returns minimum element.
int Heap::extract_min(){
   int temp = A[0];
   A[0] = A[--h_size];
   trickle_down(0);   
   return temp;
}

// Repairs the heap ordering invariant after replacing the root.
// Normal initial call should be trickle_down(0).
// trickle_down(i) performs the repair on the subtree rooted a A[i].
// make_heap() call trickle_down(i) for i (h_size/2)-1 down to 0.
void Heap::trickle_down(int i){
   int left = i*2 + 1;
   int right = i*2 + 2;
   int smallest = i;
   if(left < h_size && A[i] > A[left])
   {
      smallest = left;
   }
   if(right < h_size && A[smallest] > A[right])
   {
      smallest = right;
   }
   if(smallest !=  i)
   {
      int temp = A[i];
      A[i] = A[smallest];
      A[smallest] = temp;
      trickle_down(smallest);
   }
}

// Turns A[0] .. A[size-1] into a heap.
void Heap::make_heap(){
   for( int i = (h_size/2)-1; i>=0 ; i-- ) trickle_down(i);  
}

// Prints contents of heap to standard output (for testing).
void Heap::display(){
     for(int i = 0; i < h_size ; ++i) cout << A[i] << ", " ;
}
