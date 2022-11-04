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

MovieTree::~MovieTree() {
  //write your code
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
  TreeNode* movie = new TreeNode();
  TreeNode* leaf = new TreeNode();
  TreeNode* parent = new TreeNode();
  if (root == NULL)
  {
    movie->titleChar = initial;
    root = movie;
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
  TreeNode* letter = new TreeNode();
  TreeNode* newMovie = new TreeNode();
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


TreeNode* BST::deleteNode(TreeNode *currNode)
{

  if(currNode == NULL)
  {
    return NULL;
  }
    //TODO Case : No child
    if(currNode->leftChild == NULL && currNode->rightChild == NULL)
    {
      delete currNode;
      currNode = NULL;
    }
    //TODO Case : Only rightChild child
    else if(currNode->leftChild == NULL)
    {
      TreeNode* temp = currNode;
      currNode = currNode->rightChild;
      delete temp;
    }
    //TODO Case : Only leftChild child
    else if(currNode->rightChild == NULL)
    {
      TreeNode* temp2 = currNode;
      currNode = currNode->leftChild;
      delete temp2;
    }
    //TODO Case: Both leftChild and rightChild child
    else
    {
      ///Replace with Minimum from rightChild subtree
      TreeNode* temp3;
      temp3 = getMinValueNode(currNode->rightChild);
      currNode->titleChar = temp3->titleChar;
      currNode->rightChild = deleteNode(currNode->rightChild);

    }
return currNode;
}



void deleteMovieHelper(TreeNode* treeCrawler, string title)
{
    LLMovieNode* currentLL = treeCrawler->head;
    LLMovieNode* prevLL = NULL;
    if(treeCrawler->head->title == title && currentLL != NULL)
    {
        treeCrawler->head = treeCrawler->head->next;
        delete currentLL;
        return;
    }
    while(currentLL != NULL && currentLL->title != title)
    {
        prevLL = currentLL;
        currentLL = currentLL->next;
    }
    if(currentLL == NULL)
    {
        cout << "Movie: " << title << " not found, cannot delete." << endl;
        return;
    }
    if(currentLL->title == title)
    {
        prevLL->next = currentLL->next;
        delete currentLL;
        return;
    }

}



void MovieTree::deleteMovie(string title)
{
  TreeNode* search = new TreeNode;
  char initial;
  initial = title[0];
  if (root == NULL)
  {
    cout << "Movie: " << title << " not found, cannot delete." << endl;
    return;
  }
  else
  {
    search = searchTree(root, title[0]);
    if (search != NULL)
    {
      deleteMovieHelper(search, title);
    }
    else
    {
      cout << "Movie: " << title << " not found, cannot delete." << endl;
      return;
    }
    return;
  }
}
