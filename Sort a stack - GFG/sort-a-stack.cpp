//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void insertA(stack<int> &s , int a){
    
    if(s.size() == 0){
        s.push(a);
    }else{
        
        int temp = s.top();
        
        if(temp < a){
            s.push(a);
            
        }else{
            
            s.pop();
            insertA(s,a);
            s.push(temp);
            
            
            
        }
        
        
        
        
        
    }
    
    
    
}


void SortedStack :: sort()
{
   //Your code here
   if(s.size() == 0) return;
   
   int a = s.top();
   s.pop();
   sort();
   
   insertA(s,a);
   
   
   
}