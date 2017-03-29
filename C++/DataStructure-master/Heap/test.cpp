/*************************************************************
   Test Program for Basic Heap Class - Preliminiary Version.
**************************************************************/
#include <iostream>
#include "Heap.h"
#include "Heap.cpp"
using namespace std;

void heapTest();
 
int main(){
      heapTest();
      return 0;
}

void Show( Heap & H, string s ){
      cout << s << ".capacity=" << H.capacity() << endl;
      cout << s << ".size=" << H.size() << endl;
      cout << s << "=" ; H.display(); cout << endl;
      cout << "-----------------------\n";
} 
 
void heapTest(){

      // Test default constructor and basic functions 
      Heap H;
      Show( H, "H" );
 
      H.insert(7);
      H.insert(1);
      H.insert(3);
      H.insert(13);
      H.insert(11);
      H.insert(4);

      Show( H, "H" );
 
      //build another heap to test
      int tr[] = {15,2,6};
      Heap R(tr, 3, 3);
      Show(R, "R");

      Heap R2 = R;
      Show(R2,"R2");
      Heap R3 = H+R;
      Show(R3, "R3");

      cout << "Empty it: ";
      while(!H.empty()) cout << H.extract_min() << "; " ;
      cout << endl;

      cout << "Empty it: ";
      while(!R3.empty()) cout << R3.extract_min() << "; " ;
      cout << endl;

      Show( H, "H" );

}

