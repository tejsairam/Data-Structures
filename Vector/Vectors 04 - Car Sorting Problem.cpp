#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

class Car{
    public:
    string car_name;
    int x,y;
    Car(){

    }

    Car(string n,int x,int y){
        car_name = n;
        this->x = x;
        this->y = y;
    }
    int dist(){
        return x*x+y*y;//this return square of distances from origin
    }
};
bool compare(Car A, Car B){
    int da = A.dist();
    int db = B.dist();

    if(da == db){
        return A.car_name.length()<B.car_name.length();
    }
    return da<db;
    
}


int main(){
    int n;
    cin>>n;

    vector<Car> v;
    for(int i=0;i<n;i++){
        int x;
        int y;
        string name;
        cin>>name>>x>>y;
        //make a car object
        Car temp(name,x,y);
        v.push_back(temp);
    }

    sort(v.begin(),v.end(),compare);

    for(auto c:v){
        cout<<"Car Name : "<<c.car_name<<" , "<<"Distance: "<<c.dist()<<" , "<<"Location: "<<c.x<<c.y<<endl;
    }
    
    return 0;
}
