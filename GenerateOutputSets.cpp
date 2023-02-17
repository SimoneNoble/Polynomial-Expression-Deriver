#include "GenerateOutputSets.h"
#include <iostream>
#include <fstream>
using namespace std;

void GenerateOutputSets() {

    cout << "Please enter polynomial in terms of: ax^4 + bx^3 + cx^2 + dx + e" << endl << endl;

    cout << "(E.g., 6x^3 + 1: a = 0, b = 6, c = 0, d = 0, e = 1)" << endl << endl;

    cout << "Please note: Only up to 4 terms are allowed. At least one of your constants must be 0." << endl << endl;

    int a, b, c, d, e;

    bool boolean = false;

    while (boolean == false)
    {
        cout << "a: ";
        cin >> a;
        cout << "b: ";
        cin >> b;
        cout << "c: ";
        cin >> c;
        cout << "d: ";
        cin >> d;
        cout << "e ";
        cin >> e;
        cout << endl;

        if (a == 0 or b == 0 or c == 0 or d == 0 or e == 0)

        {
            boolean = true;
        }
        else
        {
            cout << "Only up to 4 terms are allowed. At least one of your constants must be 0." << endl << endl;
        }
    }

    cout << "The algebraic expression you inputted is " << a << "x^4 + " << b << "x^3 + " << c << "x^2 + " << d << "x + " << e << endl;

    int x, term, arr[21];

    cout << "Your output set is: ";

    for (x = 0; x <= 20; x++)
    {
        term = (a * x * x * x * x) + (b * x * x * x) + (c * x * x) + (d * x) + e;

        cout << term << ", ";

        arr[x] = term;
    }

    char saveoption;

    cout << endl << "Would you like to save this output set? Enter Y or N: " << endl;

    cin >> saveoption;

    if (saveoption == 'Y' || saveoption == 'y')
    {
        cout << "You have decided to save the output set" << endl;

        cout << "What would you like to name your file? " << endl;

        string filename;

        cin >> filename;

        filename = filename + ".txt";

        cout << "You have named your file: " << filename << endl;
        fstream MyFile;

        try
        {
            MyFile.open(filename, ios_base::out | ios_base::in);
            if (MyFile.is_open() == false)
            {
                cout << "Creating text file: ";
                MyFile.open(filename, ios_base::out);
                    for (int i = 0; i < 21; i++)
                    {
                        ofstream MyFile(filename);
                        for (int i = 0; i < 21; i++)
                        {
                            MyFile << arr[i] << " ";
                        }
                        MyFile.close();
                    }; 
            }
            else
            {
                throw 505;
            }
        }
        catch (...)
        {
            cout << "Warning: file already exists. Proceed? \n (Y or N)" << endl;
            char option;
            cin >> option;
            if (option == 'N' || option == 'n')
            {
                MyFile.close();
                cout << "You have decided not to proceed." << endl;
            }
            else if (option == 'Y' || option == 'y')
            {
                cout << "You have decided to proceed." << endl;
                cout << "Creating text file: ";
                MyFile.open(filename, ios_base::out);
                for (int i = 0; i < 21; i++)
                {
                    ofstream MyFile(filename);
                    for (int i = 0; i < 21; i++)
                    {
                        MyFile << arr[i] << " ";
                    }
                    MyFile.close();
                };
            }
        }

    }
}