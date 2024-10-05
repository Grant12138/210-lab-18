/***************************************************************************
* COMSC-210 | Lab 18 | Grant Luo
* Editor: CLion
* Compiler: Apple clang version 16.0.0
*/
#include <iostream>
using namespace std;

struct Review
{
    double rating;
    string comments;
    Review* prev;
    Review* next;

    Review() : rating(-1), comments("No Review"), prev(nullptr), next(nullptr) {}
};

// Function prototypes
int getChoice();

int main()
{
    cout << "Which linked list method should we use?\n";
    cout << "    [1] New nodes are added at the head of the linked list\n";
    cout << "    [2] New nodes are added at the tail of the linked list\n";

    return 0;
}

int getChoice()
{
    cout << "    Choice: ";
}