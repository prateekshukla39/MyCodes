#include<bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> &books,int m,int mid)
{    
    int n = books.size();
    int cs = 0;
    int students = 1;
    
    for(int i = 0; i < n; i++)
    {
        if(cs + books[i] > mid)
        {
            students++;
            cs = books[i];
            if(students > m)
                return false;
        }
        else
            cs += books[i];
    }
    return true;
}


int minPages(vector<int> books, int m){
    //complete this code
    int n = books.size();
    int s = 0;
    int e = 0;
    
    for(int b:books){
        e += b;
        s = max(s,b);
    }
    int result = INT_MAX;
    
    while(s <= e)
    {
        int mid = (s + e)/2;
        if(isPossible(books,m,mid))
        {
            result = min(result,mid);
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return result;
}

int main()
{
    vector<int> books = {10,20,30,15};
    int m = 2;
    cout<<minPages(books, m);
    return 0;
}