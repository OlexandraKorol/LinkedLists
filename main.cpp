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

    return 0;
}