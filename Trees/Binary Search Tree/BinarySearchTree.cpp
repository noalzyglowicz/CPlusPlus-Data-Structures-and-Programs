//Noal Zyglowicz (ntz3sw) 10/15/19
#include "BinarySearchTree.h"
#include <string>
#include "BinaryNode.h"
#include <cstdlib>
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree() { root = NULL; }

BinarySearchTree::~BinarySearchTree() {
  delete root;
  root = NULL;
}

// insert finds a position for x in the tree and places it there.
void BinarySearchTree::insert(const string& x) {
  // YOUR IMPLEMENTATION GOES HERE
  if(root == NULL){
    BinaryNode *newNode = new BinaryNode();
    newNode -> value = x;
    root = newNode;
  } else {
    insertHelper(x, root);
  }
}

//insert helper function
void BinarySearchTree::insertHelper(const string& x, BinaryNode *& bn){
  if(bn -> left == NULL && bn -> right == NULL){
    BinaryNode *newNode = new BinaryNode();
    newNode -> value = x;
    if(x < bn -> value){
      bn -> left = newNode;
    }
    else if(x > bn -> value){
      bn -> right = newNode;
    }
  }

  else if(bn -> left == NULL && bn -> right != NULL){
    if(x < bn -> value){
      BinaryNode *newNode = new BinaryNode();
      newNode -> value = x;
      bn -> left = newNode;
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
      BinaryNode *newNode = new BinaryNode();
      newNode -> value = x;
      bn -> right = newNode;
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
  
}

// remove finds x's position in the tree and removes it.
void BinarySearchTree::remove(const string& x) { root = remove(root, x); }

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string BinarySearchTree::pathTo(const string& x) const {
  // YOUR IMPLEMENTATION GOES HERE
  BinaryNode *dummyNode = root;
  if(find(x)){
  return pathToHelper(x, dummyNode);
  } else {
  return "";
  }
    
}

//pathTo helper function
string BinarySearchTree::pathToHelper(const string& x, BinaryNode *& bn) const {

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
bool BinarySearchTree::find(const string& x) const {
  // YOUR IMPLEMENTATION GOES HERE
  BinaryNode *dummyNode = root;
  return findHelper(x, dummyNode);
}

//find helper function
bool BinarySearchTree::findHelper(const string& x, BinaryNode*& bn) const {
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
int BinarySearchTree::numNodes() const {
  // YOUR IMPLEMENTATION GOES HERE
  if(root == NULL){
    return 0;
  }
  BinaryNode *dummyNode = root;
  return numNodesHelper(dummyNode);
}

int BinarySearchTree::numNodesHelper(BinaryNode*& bn) const {
  
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
}

// private helper for remove to allow recursion over different nodes. returns
// a BinaryNode* that is assigned to the original node.
BinaryNode* BinarySearchTree::remove(BinaryNode*& n, const string& x) {
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
      BinaryNode* temp = n->right;
      n->right = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    if (n->right == NULL) {
      BinaryNode* temp = n->left;
      n->left = NULL;
      delete n;
      n = NULL;
      return temp;
    }
    // two children
    string sr = min(n->right);
    n->value = sr;
    n->right = remove(n->right, sr);
  } else if (x < n->value) {
    n->left = remove(n->left, x);
  } else {
    n->right = remove(n->right, x);
  }
  return n;
}

// min finds the string with the smallest value in a subtree.
string BinarySearchTree::min(BinaryNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->value;
  }
  return min(node->left);
}

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p) {
  if (p == nullptr) return;
  showTrunks(p->prev);
  cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isLeft) {
  if (root == NULL) return;

  string prev_str = "    ";
  Trunk* trunk = new Trunk(prev, prev_str);

  printTree(root->left, trunk, true);

  if (!prev)
    trunk->str = "---";
  else if (isLeft) {
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

  printTree(root->right, trunk, false);
}

void BinarySearchTree::printTree() { printTree(root, NULL, false); }

/*
int main(){
  BinarySearchTree *t = new BinarySearchTree();
  t->insert("and");
  t->insert("apple");
  t->insert("aardvark");
  t->insert("aaron");
  t->insert("e");
  t ->insert("f");

  t->printTree();
  cout << t->find("hippo") << endl;

  return 0;
  }*/


 
