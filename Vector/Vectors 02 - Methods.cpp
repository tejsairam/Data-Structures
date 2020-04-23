#include <iostream>
#include<vector>
using namespace std;

int main() {

    //Create and initialise a vector
    vector<int> d{1,2,3,10,14};
    
    //push_back takes O(1) time mostly
    d.push_back(16);

    for(int x:d){
        cout<<x<<" ";
    }
    cout<<endl;

    // removing last element and it also takes O(1) time
    d.pop_back();
    for(int x:d){
        cout<<x<<" ";
    }
    cout<<endl;

    //insert in the middle takes O(N) time
    d.insert(d.begin() + 3,100); //move to the 3rd index and add 100 
    for(int x:d){
        cout<<x<<" ";
    }
    cout<<endl;
    

    d.insert(d.begin() + 3,4,50); //inserting 4 elements of value 50 at middle
    for(int x:d){
        cout<<x<<" ";
    }
    cout<<endl;


    //erase some element in the middle
    d.erase(d.begin() + 3);
    for(int x:d){
        cout<<x<<" ";
    }
    cout<<endl;


    d.erase(d.begin() + 3, d.begin()+5);
    for(int x:d){
        cout<<x<<" ";
    }
    cout<<endl;


    //size
    cout<<d.size()<<endl;
    cout<<d.capacity()<<endl;


    //when vector expandw it dosen't shrink automatially if we erase an element
    //we avoid the shrink
    d.resize(7); // if the size is increasing then more memory will be allocated
    cout<<d.size()<<endl;
    cout<<d.capacity()<<endl;


    //remove all the elements in vector and this dosen't delete the memory occupied by the vector
    d.clear();
    cout<<"After clearing all the elements"<<endl;

    cout<<d.size()<<endl;
    cout<<d.capacity()<<endl;

    if(d.empty()){
        cout<<"This is an empty vector"<<endl;
    }

    d.push_back(10);
    d.push_back(11);
    d.push_back(12);

    cout<<"Front most element : "<<d.front()<<endl;
    cout<<"Last most element : "<<d.back()<<endl;

    vector<int> v;
    int n;
    cin>>n;
    
    //Reserve
    //To avoid doubling we will use reserve
    v.reserve(1000);
    cout<<"Initial vector capacity : "<<v.capacity()<<endl;
    for(int i = 0; i< n; i++){
        int num;
        cin>>num;
        v.push_back(num);
        cout<<"Changing Capacity : "<<v.capacity()<<endl;
    }

    cout<<"After adding all elements capacity is : "<<v.capacity()<<endl;



}
