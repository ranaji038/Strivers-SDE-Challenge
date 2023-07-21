//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
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

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    void fun(Node *root , int dis , map<int,vector<int>> &mpp){
        
        if(root == NULL) return;
        
        mpp[dis].push_back(root->data);
        
        
        if(root->left) fun(root->left,dis-1,mpp);
        
        if(root->right) fun(root->right,dis+1 , mpp);
        
    }
    
    
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        // vector<int> ans;
        // if(root== NULL )return ans;
        
        // map<int,vector<int>> mpp;
        
        // // mpp[0].push_back(root->data);
        
        // fun(root,0,mpp);
        // // fun(root->right,1,mpp);
        
        // for(auto it : mpp){
            
        //     for(auto i : it.second){
        //         ans.push_back(i);
        //     }
        // }
        
        // return ans;
        
            vector<int> ans;
    if (root == NULL) return ans;

    map<int, vector<int>> mpp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        Node* currNode = curr.first;
        int dis = curr.second;

        mpp[dis].push_back(currNode->data);

        if (currNode->left) q.push({currNode->left, dis - 1});
        if (currNode->right) q.push({currNode->right, dis + 1});
    }

    for (auto it : mpp) {
        for (auto i : it.second) {
            ans.push_back(i);
        }
    }

    return ans;
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}



// } Driver Code Ends