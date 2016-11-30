//Required headers
#include <iostream>
//Namespaces
using namespace std;
//Tree Node
class Node
{
  public:
    //Constructor
    Node(int val):data(val),left(nullptr),right(nullptr){}
    //Left Child
    Node* left;
    //Right Child
    Node* right;
    //Destructor
    ~Node()
    {
      //Delete the pointers and reset them to null
      delete left;
      delete right;
      left = nullptr;
      right = nullptr;
    }
    //data
    int data;
};

//Binary Tree Class
class BinarySearchTree
{
  public:
    //Constructor
    BinarySearchTree():root(nullptr){}
    //Insert
    void Insert(int val,Node* node);
    //Preorder Traversal
    void PreOrderTraversal(Node* node);
    //Postorder Traversal
    void PostOrderTraversal(Node* node);
    //Inorder Traversal
    void InOrderTraversal(Node* node);
    //Destructor
    ~BinarySearchTree(){root = nullptr;}
    //Root node
    Node* root;
};

//Insert Definition
void BinarySearchTree::Insert(int val,Node* node)
{
  //If the node is null we assume we start with a bew tree by initializing root
  if(node == nullptr)
  {
    root = new Node(val);
  }
  //Check if the value is less than the node's data
  else if (val < node->data)
  {
    ///Check if the left child is not null
    if(nullptr != node->left)
    {
      //Recursively traverse to find the insert point
      Insert(val,node->left);
    }
    else
    {
      //Insert the value at the left node
      node->left = new Node(val);
    }
  }
  //Check if the value is greater than the node's data
  else if (val > node->data)
  {
    ///Check if the right child is not null
    if(nullptr != node->right)
    {
      //Recursively traverse to find the insert point
      Insert(val,node->right);
    }
    else
    {
      //Insert the value at the left node
      node->right = new Node(val);
    }
  }
}

//PreOrderTraversal
void BinarySearchTree::PreOrderTraversal(Node* node)
{
  //If node is null return
  if(nullptr == node)return;
  cout<<node->data<<" -> ";
  PreOrderTraversal(node->left);
  PreOrderTraversal(node->right);
}

//PostOrderTraversal
void BinarySearchTree::PostOrderTraversal(Node* node)
{
  //If node is null return
  if(nullptr == node)return;
  PostOrderTraversal(node->left);
  PostOrderTraversal(node->right);
  cout<<node->data<<" -> ";
}

//InOrderTraversal
void BinarySearchTree::InOrderTraversal(Node* node)
{
  //If node is null return
  if(nullptr == node)return;
  InOrderTraversal(node->left);
  cout<<node->data<<" -> ";
  InOrderTraversal(node->right);
}

//Identical
bool AreTreesIdentical(Node* node1, Node* node2)
{
  //Check if both the nodes are equal return true
  if(nullptr == node1 && nullptr == node2) return true;

//Check if both are not null
  if(nullptr != node1 && nullptr != node2)
  {
    //Return based on comparision and recursively test the same
    return node1->data == node2->data &&
           AreTreesIdentical(node1->left,node2->left) &&
           AreTreesIdentical(node1->right,node2->right);
  }
  //If there is a mismatch return false
  return false;
}

//Main function
int main(int argc,char*argv[])
{
  BinarySearchTree * bst = new BinarySearchTree();
  bst->Insert(23,nullptr);
  bst->Insert(10,bst->root);
  bst->Insert(25,bst->root);
  bst->Insert(12,bst->root);
  bst->Insert(19,bst->root);
  bst->Insert(9,bst->root);
  bst->Insert(30,bst->root);
  bst->Insert(24,bst->root);
  // bst->PreOrderTraversal(bst->root);
  // cout<<"\n";
  // bst->InOrderTraversal(bst->root);
  // cout<<"\n";
  // bst->PostOrderTraversal(bst->root);
  // cout<<"\n";

  BinarySearchTree * bst2 = new BinarySearchTree();
  bst2->Insert(23,nullptr);
  bst2->Insert(10,bst2->root);
  bst2->Insert(25,bst2->root);
  bst2->Insert(12,bst2->root);
  bst2->Insert(19,bst2->root);
  bst2->Insert(9,bst2->root);
  bst2->Insert(30,bst2->root);

  //Check if identical
  cout<<boolalpha<<AreTreesIdentical(bst->root,bst2->root)<<"\n";
  bst2->Insert(24,bst2->root);
  cout<<boolalpha<<AreTreesIdentical(bst->root,bst2->root)<<"\n";
  return 0;
}
