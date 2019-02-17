//lowest common ancestor in binary search tree
#include<iostream>
#include<vector>
using namespace std;

struct node{
  int data;
  node* left;
  node* right;
};

node* newNode(int data)
{
  node* temp = new node;
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

node* insert(node* root, int data)
{
  if(root == NULL)
  {
    return newNode(data);
  }
  if(root->data < data)
  {
    root->right = insert(root->right, data);
  }
  else
  {
    root->left = insert(root->left, data);
  }
  return root;
}

node* findLCA(node* root, int n1, int n2)
{
  if(root == NULL)
  {
    return NULL;
  }
  if(root->data > n1 && root->data > n2)
  {
    return findLCA(root->left, n1, n2);
  }
  if(root->data < n1 && root->data < n2)
  {
    return findLCA(root->right, n1, n2);
  }
  return root;
}

void inorder(node* root)
{
  if(root == NULL)
  {
    return;
  }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

int main()
{
  cout<<"enter no of elements in tree"<<endl;
  int n;
  cin>>n;
  cout<<"enter elements"<<endl;
  int data;
  cin>>data;
  node* root = newNode(data);
  for(int i = 0; i < n-1; i++)
  {
    cin>>data;
    insert(root, data);
  }
  inorder(root);
  cout<<"enter elements whose ancestor is to be searched"<<endl;
  int n1,n2;
  cin>>n1>>n2;
  node* ans = findLCA(root, n1, n2);
  cout<<ans->data;
}
