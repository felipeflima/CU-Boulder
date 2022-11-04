#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST
MovieNode* m;

MovieTree::MovieTree() {
  //write your code
  root = NULL;
}

MovieTree::~MovieTree() {
  //write your code
}

void printMovieInventoryHelper(MovieNode* crawler)
{
    if (crawler == NULL)
    {
      return;
    }
    printMovieInventoryHelper(crawler->left);
    cout << "Movie: " << crawler->title << " " << crawler->rating << endl;
    printMovieInventoryHelper(crawler->right);
}

void MovieTree::printMovieInventory() {
   //write your code
   if (root == NULL)
   {
     cout << "Tree is empty. Cannot print" << endl;
   }
   printMovieInventoryHelper(root);

}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
  //write your code
  MovieNode* movie = new MovieNode(ranking, title, year, rating);
  MovieNode* leaf = new MovieNode(ranking, title, year, rating);
  MovieNode* parent = new MovieNode(ranking, title, year, rating);
  if (root == NULL)
  {
    movie->ranking = ranking;
    movie->title = title;
    movie->year = year;
    movie->rating = rating;
    root = movie;
  }
  else
  {
    movie = root;
    parent = root;
    while (movie != NULL)
    {
      if (movie->title < title)
      {
        parent = movie;
        movie = movie->right;
      }
      else if (movie->title > title)
      {
        parent = movie;
        movie = movie->left;
      }
    }
    leaf->ranking = ranking;
    leaf->title = title;
    leaf->year = year;
    leaf->rating = rating;
    if (parent->title < title)
    {
      parent->right = leaf;
    }
    else if (parent->title > title)
    {
      parent->left = leaf;
    }
  }
}

void findMovieHelper(MovieNode* current, string title)
{
  if(current == NULL)
  {
    cout<<"Movie not found."<<endl;
    return;
  }

  else if(current->title == title)
  {
      cout << "Movie Info:" << endl;
      cout << "==================" << endl;
      cout << "Ranking:" << current->ranking << endl;
      cout << "Title  :" << current->title << endl;
      cout << "Year   :" << current->year << endl;
      cout << "rating :" << current->rating << endl;
  }

  if(current->title > title)
  {
    findMovieHelper(current->left, title);
  }
  else if (current->title < title)
  {
    findMovieHelper (current->right, title);
  }
}

void MovieTree::findMovie(string title) {
  //write your code
  findMovieHelper(root, title);
}

void queryMoviesHelper(MovieNode* crawler, float rating, int year)
{
  if (crawler == NULL)
  {
    return;
  }
  if (crawler->rating >= rating && crawler->year >= year)
  {
    cout << crawler->title << "(" << crawler->year << ") " << crawler->rating << endl;
  }
  queryMoviesHelper(crawler->left, rating, year);
  queryMoviesHelper(crawler->right, rating, year);
}

void MovieTree::queryMovies(float rating, int year) {
  //write your code
  if (root == NULL)
  {
    cout << "Tree is empty. Cannot query Movies" << endl;
  }
  cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
  queryMoviesHelper(root, rating, year);
}

// float averageRatingHelper(MovieNode* crawler, float ratings, float counter, float sum, float average)
// {
//   if (crawler == NULL)
//   {
//     return 0.0;
//   }
//   ratings = crawler->rating;
//   counter += averageRatingHelper(crawler->left, ratings, counter, sum, average);
//   counter += averageRatingHelper(crawler->right, ratings, counter, sum, average);
//   sum += averageRatingHelper(crawler->left, ratings, counter, sum, average);
//   sum += averageRatingHelper(crawler->right, ratings, counter, sum, average);
//   average = sum/counter;
//   return average;
// }

float averageRatingSum(MovieNode* crawler)
{
  float sum = 0.0;
  if (crawler != NULL)
  {
    sum += crawler->rating;
    sum += averageRatingSum(crawler->left);
    sum += averageRatingSum(crawler->right);
    return sum;
  }
  else
  {
    return 0.0;
  }
}

int averageRatingCounter(MovieNode* crawler)
{
  int counter = 0;
  if (crawler != NULL)
  {
    counter = 1;
    counter += averageRatingCounter(crawler->left);
    counter += averageRatingCounter(crawler->right);
    return counter;
  }
  else
  {
    return 0;
  }
}


void MovieTree::averageRating() {
  //write your code
  if (root == NULL)
  {
    cout << "Average rating:0.0" << endl;
    return;
  }
  int counter = 1;
  float sum = 0.0;
  float average = 0.0;
  sum = averageRatingSum(root);
  counter = averageRatingCounter(root);
  average = sum/counter;
  cout << "Average rating:" << average << endl;
}
