//Union of Two Linked Lists gfg
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

struct Node* makeUnion(struct Node* head1, struct Node* head2);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        printList(makeUnion(first,second));
    }
    return 0;
}

// } Driver Code Ends


/*
// structure of the node is as follows

struct node
{
	int data;
	struct node* next;
	
	node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/

#define node Node

struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    // code here
    set<int>s;
    while(head1 != NULL or head2 != NULL){
        if(head1 != NULL){
            s.insert(head1->data);
            head1 = head1->next;
        }
        else if(head1 == NULL){
            s.insert(head2->data);
            head2 = head2->next;
        }
    }
    node*head = new node(0);
    node*tail = head;
    for(auto it : s){
        node*curr = new node(it);
        tail->next = curr;
        tail = curr;
    }
    return head->next;
}
