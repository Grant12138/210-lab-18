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
Review* getReview(Review* &);
int getChoice();
void stackReview();
void queueReview();

int main()
{
    Review* head = nullptr;
    Review* aReview = getReview(head);

    cout << "Which linked list method should we use?\n";
    cout << "    [1] New nodes are added at the head of the linked list\n";
    cout << "    [2] New nodes are added at the tail of the linked list\n";
    int choice = getChoice();

    if (choice == 1)
        stackReview();
    else
        queueReview();

    return 0;
}

Review* getReview(Review* &head)
{
    Review* newReview = new Review();

    // Get review rating
    while (true)
    {
        try
        {
            cout << "Enter review rating 0 - 5: ";
            string buf;
            cin >> buf;
            cin.ignore(1000, '\n');
            newReview->rating = stod(buf);
            if (newReview->rating >= 0.0 && newReview->rating <= 5.0)
                break;
            cout << "Please enter a value between 0 and 5\n";
        }
        catch (invalid_argument &)
        {
            cout << "You did not enter a valid rating\n";
        }
    }

    // Get review comments
    cout << "Enter review comments: ";
    getline(cin, newReview->comments);

    return newReview;
}

int getChoice()
{
    while (true)
    {
        try
        {
            cout << "    Choice: ";
            string buf;
            cin >> buf;
            cin.ignore(1000, '\n');
            int choice = stoi(buf);
            if (choice == 1 || choice == 2)
                return choice;
            cout << "Enter either 1 or 2 for your choice\n";
        }
        catch (invalid_argument &)
        {
            cout << "You did not enter a valid choice\n";
        }
    }
}

void stackReview(Review* &head, Review* aReview)
{

}