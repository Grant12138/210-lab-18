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
    Review* next;

    Review() : rating(-1), comments("No Review"), next(nullptr) {}
};

// Function prototypes
Review* getReview(Review* &);
int getChoice();
void stackReview(Review* &, Review*);
void queueReview(Review* &, Review*);
void displayReview(Review*);
bool anotherReview();
void deleteList(Review* &);
void print_id(string const& lab_desc);

int main()
{
    print_id("Lab 18: Movie Reviews");

    Review* head = nullptr;

    cout << "Which linked list method should we use?\n";
    cout << "    [1] New nodes are added at the head of the linked list\n";
    cout << "    [2] New nodes are added at the tail of the linked list\n";
    int choice = getChoice();

    do
    {
        Review* aReview = new Review {};

        if (choice == 1)
            stackReview(head, getReview(aReview));
        else
            queueReview(head, getReview(aReview));
    }
    while (anotherReview());

    displayReview(head);

    deleteList(head);

    cout << '\n';
    return 0;
}

Review* getReview(Review* &aReview)
{
    // Get review rating
    while (true)
    {
        try
        {
            cout << "Enter review rating 0 - 5: ";
            string buf;
            cin >> buf;
            cin.ignore(1000, '\n');
            aReview->rating = stod(buf);
            if (aReview->rating >= 0.0 && aReview->rating <= 5.0)
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
    getline(cin, aReview->comments);

    return aReview;
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
    if (head == nullptr)
        head = aReview;
    else
    {
        aReview->next = head;
        head = aReview;
    }
}

void queueReview(Review* &head, Review* aReview)
{
    if (head == nullptr)
        head = aReview;
    else
    {
        static Review* current = head;
        current->next = aReview;
        current = aReview;
    }
}

void displayReview(Review* head)
{
    const Review* current = head;
    if (current == nullptr)
        cout << "No reviews added yet\n";

    cout << "Displaying all reviews:\n";
    int i = 0;
    double sum = 0;
    while (current != nullptr)
    {
        cout << "    > Review #" << ++i << ": " << current->rating <<  ": " << current->comments << '\n';
        sum += current->rating;
        current = current->next;
    }

    cout << "    > Average: " << sum / i << '\n';
}

bool anotherReview()
{
    char yesOrNo;
    while (true)
    {
        cout << "Enter another review? Y/N: ";
        cin >> yesOrNo;
        cin.ignore(1000, '\n');
        if (yesOrNo == 'Y' || yesOrNo == 'y')
            return true;
        if (yesOrNo == 'N' || yesOrNo == 'n')
            return false;
        cout << "You did not enter a valid response\n";
    }
}

void deleteList(Review* &head)
{
    Review* current = head;
    while (current != nullptr)
    {
        head = current->next;
        delete current;
        current = head;
    }
}

void print_id(string const& lab_desc)
{
    cout << "\nCOMSC210 | Grant Luo | " << lab_desc << "\n";
    cout << "Editor: CLion\n";
    cout << "Compiler: Apple clang version 16.0.0\n";
    cout << "File: " << __FILE__ << "\n";
    cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
}