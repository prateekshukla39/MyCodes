#include<bits/stdc++.h>

using namespace std;

string simplifyPath(string path)
{
    //complete this code return the simplified path
    // Step 1 : Tokenise the path wrt '/'  (Tokenization and Filtering)
    istringstream iss(path);
    vector<string> tokens;
    string token;

    while(getline(iss, token, '/'))
    {
        if(token == "." || token == "")
            continue;
        tokens.push_back(token);
    }
    // Step 2 : Handle '..'
    vector<string> stack;

    if(path[0] == '/')
        stack.push_back(""); // Denotes that the path is an absolute path (wrt to the root directory)

    for(string token : tokens)
    {
        if(token == "..")
        {
            // 2 cases : absolute and relative paths
            if(stack.size() == 0 || stack[stack.size() - 1] == "..")
                stack.push_back(token);
            else if(stack[stack.size() - 1] != "")
                stack.pop_back();
        }
        else
            stack.push_back(token); 
    }

    // Creating the path by combining all the elements in the stack
    ostringstream oss;
    int i = 0;

    for(auto token : stack)
    {
        if(i != 0)
            oss<<"/";
        oss<<token;
        i++;
    }

    return oss.str();
}
int main()
{
    string path = "/../x/y/../z/././w/a///../../c/./";
    cout<<simplifyPath(path)<<endl;
    return 0;
}