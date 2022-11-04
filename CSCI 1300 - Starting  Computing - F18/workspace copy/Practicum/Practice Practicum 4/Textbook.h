#ifndef TEXTBOOK_H
#define TEXTBOOK_H
#include <iostream>
using namespace std;

class Textbook
{
    public:
        Textbook();
        Textbook(string, int, float, bool);
        void setTitle (string);
        string getTitle();
        void setPages(int);
        int getPages();
        void setCost(float);
        float getCost();
        void setOnline(bool);
        bool getOnline();
        float costPerPage();
        
        
    private:
        string title;
        int pages;
        float cost;
        bool online;
        
};

#endif


