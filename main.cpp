#include "LinkedList.h"

int main() {
    LinkedList<int> list;

    list.insertAtBeginning(30);
    list.insertAtBeginning(20);
    list.insertAtBeginning(10);

    list.print();

    if (list.search(20)) {
        cout << "Знайдено\n";
    }

    list.deleteValue(20);
    list.print();


    
//  InsertAtEnd(10) method test

//    list.insertAtEnd(10);
//    list.print();
//
//    list.insertAtEnd(20);
//    list.insertAtEnd(30);
//    list.print();
//
//    list.insertAtBeginning(5);
//    list.print(); 
//
//    list.insertAtEnd(40);
//    list.print();
    
    
//   getSize() method test
//    list.print();
//    cout<< list.getSize() << endl;
    
// reverse() method test
//    list.insertAtEnd(20);
//    list.insertAtEnd(30);
//    list.print();
//    list.reverse();
//    list.print();
    
// detectCycle() method test

//    list.print();
//    cout<< list.detectCycle() << endl;
    
// getNthFromEnd method test

   list.insertAtEnd(20);
   list.insertAtEnd(30);
   list.insertAtEnd(40);
   list.insertAtEnd(50);
   list.print();
   
   cout << list.getNthFromEnd(2)->data << endl;
   
    
    return 0;
}
