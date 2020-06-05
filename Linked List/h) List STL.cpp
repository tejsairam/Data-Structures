/*

List STL in c++ ---> doubly linked list = each element is connected with next element as well as previous element

useful for insertion and deletion from front and middle than compared to vector

push_back
push_front
pop_back
pop_front
insert
erase (works with index)
remove (if we want to remove some elements from list)

*/

#include<iostream>
#include<list>
using namespace std;

int main() {
    list<int> l; 

    list<int> l1{1,2,3,10,8,5};

    //different data type
    list<string> l2{"apple","banana","kiwi"};
    l2.push_back("pineapple");

    //sort
    l2.sort();

    //reverse
    l2.reverse();

    //remove pineapple
    cout << l2.front() << endl;
    l2.pop_front();

    //remove last element ad add to the frot of the list
    l2.push_front("Mango");
    cout << l2.back() << endl;
    l2.pop_back();

    //iterate over the list and print the data
    for(auto s:l2) {
        cout << s << "->";
    }

    cout << endl;
    l2.push_back("orange");
    l2.push_back("orange");

    for(auto s:l2) {
        cout << s << "->";
    }

    cout << endl;
    //remove a fruit by a particular value
    string f;
    cin >> f;
    l2.remove(f);

    for(auto s:l2) {
        cout << s << "->";
    }

    cout << endl;
    //erase some element at one or more elements from the list

    //auto it = l2.begin() + 1; // this gives error and it works with vector but not lists 
                              // as direct  access is not possible as memory is not linear
    // so do this
    auto it = l2.begin();
    it++;
    it++;
    l2.erase(it);

    for(auto s:l2) {
        cout << s << "->";
    }

    cout << endl;

    //we can insert elements in the list

    auto it1 = l2.begin();

    l2.insert(it1,"fruit juice");

    it1++;
    it1++;

    l2.insert(it1,"guava");

    for(auto s:l2) {
        cout << s << "->";
    }
}
