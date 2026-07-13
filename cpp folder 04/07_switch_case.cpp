#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "enter then value of n\n";
    cin >> num;
    char jh = 'a';
    switch (jh)
    { // only cotain integer and character.
    case 'a':
        cout << "character is 1\n";
         switch (num)
        {
        case 1:
            cout << "num is 1\n";
            break;
        case 2:
            cout << "num is 2\n";
            break;
        case '1':
            cout << "\nchar is '1'\n\n";
            break;
        default:
        cout << "num is not 1,2,3,4\n";
        }
        break;

    case 'b':
        cout << "num is 2\n";
        break;
    case '1':
        cout << "\nchar is '1'\n\n";
        break;
    default:
        cout << "num is not a,b,c\n";
    }
}
// switch case mai continue not valid.