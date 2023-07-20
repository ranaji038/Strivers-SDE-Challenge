//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    private:
    int sum(Node * root){
        if(root == NULL) return 0;
        
        return sum(root->left) + sum(root->right) + root->data;
    }
    public:
    pair<bool,int> check(Node * root){
        if(!root) return {true,0};
        
        if(!root->left && !root->right) return { true , root->data};
        
        pair<bool,int> lefti = check(root->left);
        pair<bool,int> righti = check(root->right);
        
        
        if(lefti.first & righti.first & lefti.second + righti.second == root->data){
            return {true,lefti.second + righti.second + root->data};
        }else{
              return {false,lefti.second + righti.second + root->data};
        }
        
        
        
    }
    bool isSumTree(Node* root)
    {
        //  // Your code here
        //  if(root == NULL) return true;
         
        //  if(root->left == NULL && !root->right) return true;
         
        //  bool left = isSumTree(root->left);
        //  bool right = isSumTree(root->right);
         
        //  int leftsum = 0 , rightsum = 0;
        //  if(root->left != NULL)
        //   leftsum = sum(root->left);
         
        //  if(root->right != NULL)
        //   rightsum = sum(root->right);
        // //  cout<<leftsum<<" "<<rightsum<<endl;
         
        //  bool check ;
     
        //  if(leftsum + rightsum == root->data) check = true;
        //  else check = false;
         
        //  if(left & right & check){
        //      return true;
        //  }else {
        //      return false;
        //  }
         
         return check(root).first;
         
         
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        cout <<ob.isSumTree(root) << endl;
    }
    return 1;
}
// } Driver Code Ends