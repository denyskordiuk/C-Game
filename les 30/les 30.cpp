#include <list>
std::list<int> list1;          
std::list<int> list2(5);          // список list2 складається з 5 чисел, кожен елемент має значення по замовчуванню
std::list<int> list3(5, 2);           // список list3 складається з 5 чисел, кожне число рівне 2
std::list<int> list4{ 1, 2, 4, 5 };   
std::list<int> list5 = { 1, 2, 3, 5 }; 
std::list<int> list6(list4);          
std::list<int> list7 = list4;         









