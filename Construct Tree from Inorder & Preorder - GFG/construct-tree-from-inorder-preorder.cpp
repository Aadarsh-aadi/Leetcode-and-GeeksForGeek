// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
 int preIndex = 0;

int search(int arr[], int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
}

 Node* fbuildTree(int in[], int pre[], int inStrt, int inEnd)
{
 
    if (inStrt > inEnd)
        return NULL;
 
    /* Pick current node from Preorder traversal using preIndex
    and increment preIndex */
    Node* tNode;
    tNode = new Node(pre[preIndex++]);
    //cout << tNode->data << endl;
 
    /* If this node has no children then return */
    if (inStrt == inEnd)
        return tNode;
 
    /* Else find the index of this node in Inorder traversal */
    int inIndex = search(in, inStrt, inEnd, tNode->data);
 
    /* Using index in Inorder traversal, construct left and
     right subtress */
    tNode->left = fbuildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = fbuildTree(in, pre, inIndex + 1, inEnd);
 
    return tNode;
}
 
 
class Solution{
    public:
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        preIndex = 0;
        return fbuildTree(in,pre,0,n-1);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends