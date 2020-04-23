#include <iostream>
#include<vector>
using namespace std;

int main() {

    //ways to create and initialise a vector
    vector<int> a;
    vector<int> b(5,10); // it means vector b has 5 integers with value 10
    vector<int> c(b.begin(),b.end()); //copying vector b to vector c
    vector<int> d{1,2,3,4,10};

    //iterate over the vector
    for(int i = 0; i < c.size(); i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;

    for(auto it = b.begin(); it != b.end(); it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;

    for(int x:d){ // for every integer x that lies in vector d
        cout<<x<<" "; 
    }
    cout<<endl;

    //Discuss more functions
    vector<int> v;
    int n;
    cin>>n;
    for(int i = 0; i < n ; i++){
        int num;
        cin>>num;
        v.push_back(num); // Adds an element to the end of the vector
    }

    for(int x:v){
        cout<<x<<" ";
    }
    cout<<endl;
    // Doubling of memeory is expensive. We should try to avoid it
    //memory doubles after adding element at the end of vector i.e 1 2 4 8 16 32 .....
    //Understand at memory level, what are the differences in the two
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl; //size of underlying array
    cout<<v.max_size()<<endl; // max number of elements a vector can hold in the worst case according to availabl memory

    cout<<d.size()<<endl;
    cout<<d.capacity()<<endl; //size of underlying array
    cout<<d.max_size()<<endl;
}
