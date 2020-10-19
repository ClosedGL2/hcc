#include "includetest.hc"

"Hello world\n";
'Hi there';
'\n';

// switch demo
U0 SwitchDemo()
{
    I16 i;
    for (i = 0; i < 10; i++)
    {
        switch [i]
        {
            case 0: "0\n"; break;
            case 1: "1\n"; break;
            case 2: "2\n"; break;
            case 3: "3\n"; break;
            start:
                '[';
            case 4: "4"; break;
            case 5: "5"; break;
            case 6: "6"; break;
            case 7: "7"; break;
            end:
                ']\n';
                break;
            case 8: "8\n"; break;
            case 9: "9\n"; break;
        }
    }
}

/*
 * print demo
 */
U0 PrintDemo()
{
    U64 text = 'Cello\n';
    Print(text);

    I16 i;
    for (i = 0; i < 10; i++)
    {
        Print("Character: %d", i);
    }
}

"/* this is not a comment because it is recognized as a string */";

SwitchDemo;
PrintDemo;