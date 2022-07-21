#include<bits/stdc++.h>

using namespace std;

string convert_to_digital_time(int minutes){
    //complete this function
    int hours = minutes/(60);
    int absMins = minutes%(60);
    string Time;
    Time = to_string(hours) + ":" + (absMins < 10 ? "0" : "") + to_string(absMins);
    return Time;
}

int main()
{
    int minutes;
    cin>>minutes;
    cout<<convert_to_digital_time(minutes)<<endl;
    return 0;
}