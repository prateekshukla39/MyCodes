#include<bits/stdc++.h>

using namespace std;

string extractStringAtKey(string str, int key)
{
    char *s = strtok((char*)str.c_str(), " ");
    while(key>1)
    {
        s = strtok(NULL, " ");
        key--;
    }
    return (string)s;
}

int convertToInteger(string str)
{
    int ans = 0, p = 1;
    for(int i=str.length(); i>=0; i--)
    {
         ans += (str[i]-'0')*p;
         p *= 10; 
    }
    return ans;
}

bool compareNumeric(pair<string,string> str1, pair<string,string> str2)
{
    string key1, key2;
    key1 = str1.second;
    key2 = str2.second;
    
    return convertToInteger(key1) < convertToInteger(key2);
}

bool compareLexico(pair<string,string> str1, pair<string,string> str2)
{
    string key1, key2;
    key1 = str1.second;
    key2 = str2.second;
    return key1 < key2;
}

int main()
{
    int t, T;
    cin >> t;
    T = t;
    cin.get();
    string str;
    vector<string> v;
    while (t--)
    {
        getline(cin, str);
        v.push_back(str);
    }
    int key;
    string reversal, ordering;
    cin>>key>>reversal>>ordering;

    // To extract keys and store for comparison

    vector<pair<string,string>> vp;

    for(int i = 0; i<T; i++)
        vp.push_back({v[i],extractStringAtKey(v[i],key)});
    
    // Sorting

    if(ordering == "numeric")
        sort(vp.begin(),vp.end(),compareNumeric);
    else
        sort(vp.begin(),vp.end(),compareLexico);
    
    // Reversal 

    if(reversal == "true")
        reverse(vp.begin(),vp.end());
    
    // Printing result

    for(int i = 0; i<T; i++)
        cout<<vp[i].first<<endl;
    return 0;
}