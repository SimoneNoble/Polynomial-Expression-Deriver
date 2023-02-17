#include "GenerateExpression.h"
#include "GenerateOutputSets.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void GenerateExpression() {

    const size_t max_size = 21;
    int numbers[max_size]{};
    char option = 'z';

    while (option != 'A' && option != 'a' && option != 'B' && option != 'b')
    {
        cout << "Would you like to: \n A: Type your own input set \n B: Use input set from a file" << endl;
        cin >> option;

        if (option == 'A' || option == 'a')
        {
            cout << "You selected option A" << endl;

            cout << endl << "Please enter your terms (from x = 0 to x = 20): " << endl;
            size_t size = 0;
            while ((cin >> numbers[size++]) and (size < max_size));
            {
                cout << "The terms you inputted are: ";

                for (int i = 0; i < 21; i++)
                {
                    cout << numbers[i] << ", ";
                }
            }
        }

        else if (option == 'B' || option == 'b')
        {
            cout << "You selected option B" << endl;
            cout << "Please enter the name of your file (including '.txt'): " << endl;
            string filename;
            cin >> filename;
            ifstream MyFile;

            int rows = 1, cols = 21;
            int** arr = new int* [rows];
            for (int k = 0; k < rows; k++)
                arr[k] = new int[cols];

            MyFile.open(filename);
            try
            {
                if (MyFile.is_open())
                {
                    for (int x = 0; x < rows; x++)
                    {
                        for (int y = 0; y < cols; y++)
                        {
                            MyFile >> arr[x][y];
                        }
                    }
                }

                else
                {
                    throw 505;
                }
            }

            catch (...)
            {
                cout << "This file doesn't exist." << endl;
                cout << "Please restart the program." << endl;
                break;
            }

            cout << "After reading data from file:" << endl;

            for (int x = 0; x < rows; x++)
            {
                for (int y = 0; y < cols; y++)
                {
                    cout << arr[x][y] << " ";
                    numbers[y] = arr[x][y];
                }
            }

            MyFile.close();

            for (int i = 0; i < rows; i++)
            {
                delete[] arr[i];
            }
            delete[] arr;
        }
    }

    int term, termtest, termtest2, x, xtest, xtest2, a, b, c, d, e, newsize = 21;

    for (x = 0; x <= 20; x++)
    {
        for (int a = -9; a <= 9; a++)
        {
            for (int b = -9; b <= 9; b++)
            {
                for (int c = -9; c <= 9; c++)
                {
                    for (int d = -9; d <= 9; d++)
                    {
                        for (int e = -1000; e <= 1000; e++)
                        {
                            term = ((a * x * x * x * x) + (b * x * x * x) + (c * x * x) + (d * x) + e);

                            xtest = x - 1;
                            xtest2 = x - 2;

                            termtest = ((a * xtest * xtest * xtest * xtest) + (b * xtest * xtest * xtest) + (c * xtest * xtest) + (d * xtest) + e);

                            termtest2 = ((a * (xtest2) * (xtest2) * (xtest2) * (xtest2)) + (b * (xtest2) * (xtest2) * (xtest2)) + (c * (xtest2) * (xtest2)) + (d * (xtest2)) + e);

                            for (int j = 0; j < newsize; j++)
                            {
                                if (term == numbers[j])
                                {
                                    if (j == (newsize - 1) and termtest == numbers[j - 1] and termtest2 == numbers[j - 2] and j == x)
                                    {
                                        cout << "\n A possible solution is " << a << "x^4 + " << b << "x^3 + " << c << "x^2 + " << d << "x + " << e << endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}