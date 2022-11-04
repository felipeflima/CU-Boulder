#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;

MovieTree::MovieTree() {
  //write your code
  root = NULL;
}

void destroyNode(TreeNode *currNode){
     if(currNode!=NULL)
     {
       destroyNode(currNode->leftChild);
       destroyNode(currNode->rightChild);

       LLMovieNode* temp = currNode->head;
       LLMovieNode* next;
       while (temp) {
         next = temp->next;
         delete temp;
         temp = next;
       }
       currNode->head = NULL;
       delete currNode;
       currNode = NULL;
     }
 }

MovieTree::~MovieTree() {
  //write your code
  destroyNode(root);
  root = NULL;

}


void printMovieInventoryHelper(TreeNode* crawler)
{
    if (crawler == NULL)
    {
      return;
    }
    printMovieInventoryHelper(crawler->leftChild);
    cout << "Movies starting with letter: " << crawler->titleChar << endl;
    LLMovieNode* m;
    m = crawler->head;
    while (m != NULL)
    {
      cout << " >> " << m->title << " " << m->rating << endl;
      m = m->next;
    }
    printMovieInventoryHelper(crawler->rightChild);
}

void MovieTree::printMovieInventory() {
   //write your code
   if (root == NULL)
   {
     return;
   }
   printMovieInventoryHelper(root);
}


TreeNode* searchTree(TreeNode* current, char initial)
{
  if(current == NULL)
  {
    return NULL;
  }
  if(current->titleChar < initial)
  {
    searchTree(current->rightChild, initial);
  }
  else if (current->titleChar > initial)
  {
    searchTree (current->leftChild, initial);
  }
  else
  {
      return current;
  }

}

TreeNode* addNodeTree(TreeNode* root, char initial)
{
  TreeNode* movie;
  TreeNode* leaf = new TreeNode;
  TreeNode* parent;
  if (root == NULL)
  {
    leaf->titleChar = initial;
    root = leaf;
  }
  else
  {
    movie = root;
    parent = root;
    while (movie != NULL)
    {
      if (movie->titleChar < initial)
      {
        parent = movie;
        movie = movie->rightChild;
      }
      else if (movie->titleChar > initial)
      {
        parent = movie;
        movie = movie->leftChild;
      }
    }
    leaf->titleChar = initial;
    if (parent->titleChar < initial)
    {
      parent->rightChild = leaf;
      return parent->rightChild;
    }
    else if (parent->titleChar > initial)
    {
      parent->leftChild = leaf;
      return parent->leftChild;
    }
  }
}


void addList(TreeNode* &root, LLMovieNode* list)
{
  LLMovieNode* current = root->head;
  LLMovieNode* prev = NULL;
  if (current == NULL)
  {
    root->head = list;
  }
  else
  {
    if(list->title < current->title)
    {
        root->head = list;
        list->next = current;
        return;
    }
    while(current != NULL)
    {
        if(current->title < list->title)
        {
            prev = current;
            current = current->next;
            if(current == NULL)
            {
                prev->next = list;
                list->next = NULL;
                return;
            }
        }
        else
        {
            prev->next = list;
            list->next = current;
            return;
        }
    }
  }
}


void MovieTree::addMovie(int ranking, string title, int year, float rating)
{
  TreeNode* letter;
  TreeNode* newMovie;
  LLMovieNode* movie = new LLMovieNode(ranking, title, year, rating);
  movie->next = NULL;
  char initial = title[0];

  letter = searchTree(root, initial);
  if (letter != NULL)
  {
    addList(letter, movie);
  }
  else
  {
    if (root == NULL)
    {
      root = addNodeTree(root, initial);
      addList(root, movie);
    }
    else
    {
      newMovie = addNodeTree(root, initial);
      addList(newMovie, movie);
    }
  }
}


TreeNode* getMinValueNode(TreeNode* currNode){

    if(currNode->leftChild == NULL){
      return currNode;
    }
    return getMinValueNode(currNode->leftChild);
}



TreeNode* deleteMovieHelper(TreeNode* tempRoot, string title)
{
  char initial;
  initial = title[0];
  if(tempRoot->titleChar < initial)
  {
    tempRoot->rightChild = deleteMovieHelper(tempRoot->rightChild, title);
  }
  else if (tempRoot->titleChar > initial)
  {
    tempRoot->leftChild = deleteMovieHelper(tempRoot->leftChild, title);
  }
  else
  {
    LLMovieNode* currNode = tempRoot->head;
    LLMovieNode* prevNode = NULL;

    while (currNode->title != title && currNode != NULL) // different
    {
      prevNode = currNode;
      currNode = currNode->next;
    }

    if (currNode == NULL)
    {
      cout << "Movie: " << title << " not found, cannot delete." << endl;
      delete currNode;
      return tempRoot;
    }
    if (prevNode == NULL && tempRoot->head->next != NULL)
    {
      tempRoot->head = tempRoot->head->next;
      delete currNode; //could be seg falut
      return tempRoot;
    }
    if (prevNode != NULL && currNode != NULL)
    {
        prevNode->next = currNode->next;
        delete currNode; // seg fault?
        return tempRoot;
    }
    if (prevNode == NULL)
    {
      tempRoot->head = tempRoot->head->next;
      delete currNode; //could be seg falut
    }
    if (tempRoot->leftChild == NULL && tempRoot->rightChild == NULL)
    {
        delete tempRoot;
        tempRoot = NULL;
    }
    else if (tempRoot->leftChild == NULL)
    {
        TreeNode *tempNode = tempRoot;
        tempRoot = tempRoot->rightChild;
        delete tempNode;
    }
    else if (tempRoot->rightChild == NULL)
    {
        TreeNode *tempNode = tempRoot;
        tempRoot = tempRoot->leftChild;
        delete tempNode;
    }
    else
    {
        TreeNode* minValueNode = tempRoot->rightChild;
        while (minValueNode->leftChild != NULL)
        {
            minValueNode = minValueNode->leftChild;
        }
        tempRoot->head = minValueNode->head;
        tempRoot->titleChar = minValueNode->titleChar;
        tempRoot->rightChild = deleteMovieHelper(tempRoot->rightChild, minValueNode->head->title);
    }
}
return tempRoot;
}

void MovieTree::deleteMovie(string title)
{
  if (root == NULL)
  {
    cout << "Movie: " << title << " not found, cannot delete." << endl;
    return;
  }
  else
  {
    root = deleteMovieHelper(root, title);
  }
}
