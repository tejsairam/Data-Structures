/* You are a person who wants to book a cab. There are N number of cabs available near you and we are given the location
of the cabs i.e. (x1,y1), (x2,y2),.......You are starting at origin. We want to know the distance of the cabs from you in sorted order */

//To solve this we can make a vector pair to store car location --> vector<pair<int,int> >

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2){
    int d1 = p1.first * p1.first + p1.second *p1.second;
    
    int d2 = p2.first * p2.first + p2.second *p2.second;

    //same distance then sort according to x cordinate
    if(d1 == d2){
        return p1.first<p2.first;
    }

    return d1<d2;

}

int main() {

    int n; // n is the number of cars
    cin>>n;

    vector<pair<int,int> > v;
    for(int i = 0; i < n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }

    sort(v.begin(), v.end(), compare);

    for(auto p:v){
        cout<<p.first<<","<<p.second<<endl;
    }


}
