//
// Created by Maurice Heinze on 1/7/23.
//

#include <iostream>
using namespace std;

void    print_to_uppercase(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] > 96 && str[i] < 123)
            str[i] = (int)str[i] - 32;
        i++;
    }
    cout << str;
}

int main(int argc, char *argv[])
{
    int i;

    i = 0;
    (void)argc;
    if (argv[1] == NULL)
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        while (argv[++i])
            print_to_uppercase(argv[i]);
    }
    cout << "\n";
    return 0;
}