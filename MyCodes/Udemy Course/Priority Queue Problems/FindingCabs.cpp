#include<bits/stdc++.h>

using namespace std;

class Car{
    public:
    string CarID;
    int x;
    int y;
    Car(string CarID, int x, int y)
    {
        this->CarID = CarID;
        this->x = x;
        this->y = y;
    }
    
    int dist()
    {
        return x*x + y*y;
    }
};

class Compare{
    public:
        bool operator()(Car A, Car B)
        {
            return A.dist() < B.dist();
        }
};

void findingCabs(vector<Car> cars, int k)
{
    priority_queue<Car, vector<Car>, Compare> maxH;
    for(int i = 0; i < cars.size(); i++)
    {
        maxH.push(cars[i]);
        if(maxH.size() > k)
            maxH.pop();
    }
    vector<Car> output;
    while(!maxH.empty())
    {
        output.push_back(maxH.top());
        maxH.pop();
    }
    reverse(output.begin(), output.end());

    for(auto car : output)
        cout<<car.CarID<<" ";
    cout<<endl;
    return;
}

int main()
{
    vector<Car> cars;
    int n, k;
    cin>>n>>k;
    string id;
    int x, y;
    for(int i=0; i<n; i++)
    {
        cin>>id>>x>>y;
        Car car(id, x, y);
        cars.push_back(car);
    }
    findingCabs(cars, k);
    return 0;
}
/*
input:
5 3
C1 1 1
C2 2 1
C3 3 2
C4 0 1
C5 2 3
*/