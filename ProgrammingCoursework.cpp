#include <iostream>
using namespace std;
#include "GenerateExpression.h"
#include "GenerateOutputSets.h"

int main() {

    char option = 'z';

    while (option != 'A' && option != 'B')
    {
        cout << "Would you like to (Type 'A' or 'B'): \n A: Derive an algebraic expression \n B: Derive an output set " << endl;

        cin >> option;

        if (option == 'A' || option == 'a')

        {
            cout << "You selected option A" << endl;

            GenerateExpression();
        }

        else if (option == 'B' || option == 'b')

        {
            cout << "You selected option B" << endl << endl;
            GenerateOutputSets();
        }
    }
}