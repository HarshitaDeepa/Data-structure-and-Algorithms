//Lowest common ancestor in binary tree
#include<iostream>
#include<queue>
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

void insert(node* root, int data)
{
  queue<node*> q;
  q.push(root);
  while(!q.empty())
  {
    node* temp = q.front();
    q.pop();
    if(!temp->left)
    {
      temp->left = newNode(data);
      break;
    }
    else
    {
      q.push(temp->left);
    }
    if(!temp->right)
    {
      temp->right = newNode(data);
      break;
    }
    else
    {
      q.push(temp->right);
    }
  }
}

bool findpath(node* root, vector<int> &path, int key)
{
  if(root == NULL)
  {
  return false;
  }

  path.push_back(root->data);

  if(root->data == key)
  {
    return true;
  }
  if((root->left && findpath(root->left, path, key)) || (root->right && findpath(root->right, path, key)))
  {
    return true;
  }
  path.pop_back();
  return false;
}

int findLCA(node* root, int n1, int n2)
{
  vector<int> path1,path2;
  if(!findpath(root, path1, n1) && !findpath(root, path2, n2))
  {
    return -1;
  }
  int i;
  for(i = 0; i < path1.size() && i < path2.size(); i++)
  {
    if(path1[i] != path2[i])
    {
      break;
    }
  }
  return path1[i-1];
}
int main()
{
  cout<<"enter no of elements";
  int n;
  cin>>n;
  int data;
  cin>>data;
  node* root = newNode(data);
  for(int i = 0; i < n-1; i++)
  {
    cin>>data;
    insert(root,data);
  }
  cout<<"enter nodes whose ancenstor is to be searched";
  int n1,n2;
  cin>>n1>>n2;
  cout<<findLCA(root,n1,n2)<<endl;
  return 0;
}
