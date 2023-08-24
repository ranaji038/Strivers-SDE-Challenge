//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        for(int i=0;i<len;i++)
        {
            cout<<ch[i];
        }
        cout<<endl;
    }
        return 0;
}


// } Driver Code Ends


//return the address of the string
char* reverse(char *S, int len)
{
       stack<char> st;
    
    for (int i = 0; i < len; i++) {
        char temp = *S;
        st.push(temp);
        S++;
    }
    
    char *ans = new char[len + 1];  // +1 for the null-terminator
    for (int i = 0; i < len; i++) {
        if (st.empty()) break;  // You should break the loop if the stack is empty
        char temp = st.top();   // Use char type, not int
        st.pop();
        ans[i] = temp;
    }
    ans[len] = '\0';  // Null-terminate the reversed string
    
    return ans;
    
}