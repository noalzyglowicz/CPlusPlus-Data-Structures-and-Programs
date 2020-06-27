//Noal Zyglowicz (ntz3sw), 10/17/19
#include "AVLTree.h"
#include <string>
#include "AVLNode.h"
#include <iostream>
using namespace std;

AVLTree::AVLTree() { root = NULL; }

AVLTree::~AVLTree() {
  delete root;
  root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
  // YOUR IMPLEMENTATION GOES HERE
  if(root == NULL){
    AVLNode *newNode = new AVLNode();
    newNode -> value = x;
    root = newNode;
  } else {
    insertHelper(x, root);
     
  }
  
}

void AVLTree::insertHelper(const string& x, AVLNode *& bn){
  
  if(bn -> left == NULL && bn -> right == NULL){
    AVLNode *newNode1 = new AVLNode();
    newNode1 -> value = x;
    if(x < bn -> value){
      bn -> left = newNode1;
    }
    else if(x > bn -> value){
      bn -> right = newNode1;
    }
  }

  else if(bn -> left == NULL && bn -> right != NULL){
    if(x < bn -> value){
      AVLNode *newNode1 = new AVLNode();
      newNode1 -> value = x;
      bn -> left = newNode1;
    }
    else if(x > bn -> value){
      insertHelper(x, bn -> right);
    } 
  }

  else if(bn -> left != NULL && bn -> right == NULL){
    if(x < bn -> value){
      insertHelper(x, bn -> left);
    }
    else if(x > bn -> value){
      AVLNode *newNode1 = new AVLNode();
      newNode1 -> value = x;
      bn -> right = newNode1;
    }
  }

  else if(bn -> left != NULL && bn -> right != NULL){
    if(x < bn -> value){
      insertHelper(x, bn -> left);
       
    }
    else if(x > bn -> value){
      insertHelper(x, bn -> right);
     }
  }

  bn -> height = 1 + max(height(bn -> right), height(bn -> left));
  balance(bn);

  
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) { root = remove(root, x); }

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
  // YOUR IMPLEMENTATION GOES HERE
   AVLNode *dummyNode = root;
  if(find(x)){
  return pathToHelper(x, dummyNode);
  } else {
  return "";
  }
}

string AVLTree::pathToHelper(const string& x, AVLNode *& bn) const {
  if(bn -> value == x){
    return bn -> value;
  }
  
  else if(x < bn -> value){
    return (bn -> value) + " " +  pathToHelper(x, bn -> left);
  }

  else if(x > bn -> value){
    return (bn -> value) + " " + pathToHelper(x, bn -> right);
  }

  return "";
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
  // YOUR IMPLEMENTATION GOES HERE
   AVLNode *dummyNode = root;
  return findHelper(x, dummyNode);
}

bool AVLTree::findHelper(const string& x, AVLNode*& bn) const {
  if(bn -> value == x){
    return true;
  }

  if(bn == NULL){
    return false;
  }

  else if(x < (bn -> value)){
    if(bn -> left != NULL){
      return findHelper(x, bn -> left);
      }
  }

  else if(x > (bn -> value)){
    if(bn -> right != NULL){
      return findHelper(x, bn -> right);
      }
  }

  return false;
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
  // YOUR IMPLEMENTATION GOES HERE
  if(root == NULL){
    return 0;
  }
  AVLNode *dummyNode = root;
  return numNodesHelper(dummyNode);
}

int AVLTree::numNodesHelper(AVLNode*& bn) const {
  
  if(bn -> left == NULL && bn -> right == NULL){
    return 1;
  }

  else if(bn -> left != NULL && bn -> right == NULL){
    return 1 + numNodesHelper(bn -> left);
  }

  else if(bn -> left == NULL && bn -> right != NULL){
      return 1 + numNodesHelper(bn -> right);
  }
  
  else if (bn -> left != NULL && bn -> right != NULL){
      return 1 + numNodesHelper(bn -> left) + numNodesHelper(bn -> right);
  }
  return 1;
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
  
  //check to see if need to rotate left
  
  if(balanceFactor(n) == 2){
    //check to see if double rotation and need to rotate right
    if(balanceFactor(n -> right) < 0){
      rotateRight(n -> right);
    }
    rotateLeft(n);
  }
  
  //else check to see if need to rotate right 
  if(balanceFactor(n) == -2){ 
    //check to see if double rotation and need to rotate left
    if(balanceFactor(n -> left) > 0){
      rotateLeft(n -> left);
    }
    rotateRight(n);
  }

  
}

//helper function to calculate balance factor
int AVLTree::balanceFactor(AVLNode *& n){
  if(n == NULL){
    return 0;
  } else {
  return  height(n -> right) - height(n -> left);
  }
}



// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
  
  AVLNode *newRoot = n -> right;
  AVLNode *nRight = newRoot -> left;
  newRoot -> left = n;
  n -> right = nRight;
  n->height = 1 + max(height(n->left), height(n->right));
  newRoot->height = 1 + max(height(n->left), height(n->right));
  n = newRoot;
  return newRoot; 
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
  // YOUR IMPLEMENTATION GOES HERE
  
 AVLNode *newRoot = n -> left;
 AVLNode *nLeft = newRoot -> right;
 newRoot -> right = n;
 n -> left = nLeft;
 n->height = 1 + max(height(n->left), height(n->right));
 newRoot->height = 1 + max(height(n->left), height(n->right));
 n = newRoot;
 return newRoot; 
}

// private helper for remove to allow recursion over different nodes. returns
// an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
  if (n == NULL) {
    return NULL;
  }
  // first look for x
  if (x == n->value) {
    // found
    // no children
    if (n->left == NULL && n->right == NULL) {
      delete n;
      n = NULL;
      return NULL;
    }
    // single child
    if (n->left == NULL) {
      AVLNode* temp = n->right;
      n->right = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    if (n->right == NULL) {
      AVLNode* temp = n->left;
      n->left = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    // two children -- tree may become unbalanced after deleting n
    string sr = min(n->right);
    n->value = sr;
    n->right = remove(n->right, sr);
  } else if (x < n->value) {
    n->left = remove(n->left, x);
  } else {
    n->right = remove(n->right, x);
  }
  n->height = 1 + max(height(n->left), height(n->right));
  balance(n);
  return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->value;
  }
  return min(node->left);
}

// height returns the value of the height field in a node. If the node is
// null, it returns -1.
int AVLTree::height(AVLNode* node) const {
  if (node == NULL) {
    return -1;
  }
  return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p) {
  if (p == nullptr) return;
  showTrunks(p->prev);
  cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
  if (root == NULL) return;

  string prev_str = "    ";
  Trunk* trunk = new Trunk(prev, prev_str);

  printTree(root->right, trunk, true);

  if (!prev)
    trunk->str = "---";
  else if (isRight) { 
    trunk->str = ".---";
    prev_str = "   |";
  } else {
    trunk->str = "`---";
    prev->str = prev_str;
  }

  showTrunks(trunk);
  cout << root->value << endl;

  if (prev) prev->str = prev_str;
  trunk->str = "   |";

  printTree(root->left, trunk, false);
}

void AVLTree::printTree() { printTree(root, NULL, false); }


/*
int main(){
  AVLTree *t = new AVLTree();
  t->insert("c");
  t->printTree();
  t->insert("b");
  t->printTree();
  t->insert("a");
  t->printTree();
  //t->insert("orange");
  //t->insert("pineapple");
  //t->printTree();
  //t ->insert("watermelon");
  //t->printTree();
  //cout << t->find("orange") << endl;

  return 0;
  }
*/

