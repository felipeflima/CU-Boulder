#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;

float averageRatingHelper(MovieNode* crawler, float ratings, float counter, float sum, float average)
{
  if (crawler == NULL)
  {
    return 0.0;
  }
  ratings = crawler->rating;
  counter += averageRatingHelper(crawler->left, ratings, counter, sum, average);
  counter += averageRatingHelper(crawler->right, ratings, counter, sum, average);
  sum += averageRatingHelper(crawler->left, ratings, counter, sum, average);
  sum += averageRatingHelper(crawler->right, ratings, counter, sum, average);
  average = sum/counter;
  return average;
}

void MovieTree::averageRating() {
  //write your code
  if (root == NULL)
  {
    cout << "Average rating:0.0" << endl;
    return;
  }
  float ratings = 0.0;
  float counter = 1;
  float sum = 0.0;
  float result = 0.0;
  float average = 0.0;
  result = averageRatingHelper(root,ratings, counter, sum, average);
  cout << "Average rating:" << result << endl;
}










float averageRatingSum(MovieNode* crawler, float sum)
{
  if (crawler == NULL)
  {
    return 0;
  }
  sum += crawler->rating;
  sum += averageRatingSum(crawler->left, sum);
  sum += averageRatingSum(crawler->right, sum);
  return sum;
}

int averageRatingCounter(MovieNode* crawler, int counter)
{
  if (crawler == NULL)
  {
    return 0;
  }
  counter += averageRatingCounter(crawler->left, counter);
  counter += averageRatingCounter(crawler->right, counter);
  return counter;
}


void MovieTree::averageRating() {
  //write your code
  if (root == NULL)
  {
    cout << "Average rating:0.0" << endl;
    return;
  }
  float ratings = 0.0;
  int counter = 1;
  float sum = 0.0;
  float average = 0.0;
  sum = averageRatingSum(root, sum);
  counter = averageRatingCounter(root, counter);
  average = sum/counter;
  cout << counter << endl;
  cout << sum << endl;
  cout << "Average rating:" << average << endl;
}
