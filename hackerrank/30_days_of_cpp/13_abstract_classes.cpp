// Write your MyBook class here

    //   Class Constructor
    //   
    //   Parameters:
    //   title - The book's title.
    //   author - The book's author.
    //   price - The book's price.
    //
    // Write your constructor here
    
    
    //   Function Name: display
    //   Print the title, author, and price in the specified format.
    //
    // Write your method here
    
// End class

#include <string>
#include <iostream>

using namespace std;

class Book{
    public:
    Book(string title, string author){

    }
    protected:
    string title;
    string author;
};


class MyBook : Book{
    public:
    MyBook(string title, string author, int price) : Book(title, author){
        this->price = price;
    }

    void display(){
        cout << "Title: " << this->title << endl;
        cout << "Author: " << this->author << endl;
        cout << "Price: " << this->price << endl;
    }

    private:
    int price;
};