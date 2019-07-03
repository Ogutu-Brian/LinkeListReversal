#include <iostream>
#include "list.h"
using namespace std;

int main()
{
    List<int> list;
    for(int i = 1; i <= 10; i++){
        list.add(i);
    }
    list.print();
    list.reverse();
    list.print();
    return 0;
}
