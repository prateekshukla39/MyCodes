#include<bits/stdc++.h>

using namespace std;

int skip_whitespace(string &sentence, int &indx)
{
    while(indx < sentence.length() && sentence[indx] == ' ')
        indx++;

    return indx;
}

int normalize_word(string &sentence, int &indx)
{
    if(indx < sentence.length() && sentence[indx] != ' ')
    {
        sentence[indx] = toupper(sentence[indx]);
        indx++;
    }
    while(indx < sentence.length() && sentence[indx] != ' ')
    {
        sentence[indx] = tolower(sentence[indx]);
        indx++;
    }

    return indx;
}

string normalize(const string &sentence) {
    string copy = sentence;
    //Make the changes in copy, and return it
    int indx = 0;
    while(indx < copy.length())
    {
        indx = skip_whitespace(copy, indx);
        indx = normalize_word(copy, indx);
    }

    return copy;
}

int main()
{
    string sentence;
    getline(cin, sentence);
    cout<<normalize(sentence)<<endl;
    return 0;
}