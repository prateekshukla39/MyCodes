#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> odd, even;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x & 1) 
            odd.push_back(x);
        else 
            even.push_back(x);
    }
    bool flag = true;
    int oddSize = odd.size(), evenSize = even.size();
    if(oddSize <= 1)
        flag = false;
    if((oddSize & 1) && evenSize == 0)
        flag = false;
    if(!flag)
    {
        cout << -1;
        return;
    }
    if(!(oddSize & 1))
    {
        for(int &i : even)
            cout <<i<<" ";
        for(int &i : odd)
            cout <<i<<" ";
    }
    else 
    {
        while(evenSize > 1){
            cout <<even.back()<< " ";
            even.pop_back();
        }
        cout << odd[0] << " " << even[0] << " ";

        for(int i = 1; i < odd.size(); i++)
            cout << odd[i] << " ";
    }
}
    
    int main()
    {
        solve();
        return 0;
    }