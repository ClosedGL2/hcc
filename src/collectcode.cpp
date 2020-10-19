#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>

#include "collectcode.hpp"

using namespace std;

void CodeCollector::setInputFile(string p_inputfile)
{
    // set file path
    inputfile = p_inputfile;

    // set file stream and check if file exists
    if (!(inputhcfile = fopen(inputfile.c_str(), "rb")))
    {
        cerr << "Error: File '" << inputfile << "' does not exist" << endl;
        cerr << "Compilation terminated." << endl;

        exit(1);
    }
}

string CodeCollector::collect()
{
    string collectedcode;

    // read whole file into string
    collectedcode = "";
    for (char c; (c = getc(inputhcfile)) != EOF;)
    {
        collectedcode.push_back(c);
    }
    fclose(inputhcfile);

    // loop if files included in included code, to get all included files
    int includecount = 0;
    do
    {
        // remove comments
        {int codelen = collectedcode.size();
        for (int i = 0; i < codelen; i++)
        {
            if (collectedcode[i] == '/')
            {
                // look for comment syntax
                int commentstart = i;
                i++;
                if (collectedcode[i] == '*')   /* this kind of comment */
                {
                    // increment i until it gets to end of comment or end of code
                    i += 2;
                    while (!((collectedcode[i-1] == '*' && collectedcode[i] == '/') || i == codelen - 1))
                        i++;

                    // erase comment
                    collectedcode.erase(commentstart, i - commentstart + 1);
                    i = commentstart - 1;
                    codelen = collectedcode.size();

                } else if (collectedcode[i] == '/')    // this kind of comment
                {
                    // increment i until it gets to end of comment or end of code
                    i++;
                    while (!((collectedcode[i] == '\n' || collectedcode[i] == '\r') || i == codelen - 1))
                        i++;
                    
                    // erase comment
                    collectedcode.erase(commentstart, i - commentstart + 1);
                    i = commentstart - 1;
                    codelen = collectedcode.size();

                } else
                    i--;
            } else if (collectedcode[i] == '\''    // jump past char
                    || collectedcode[i] == '"')    // jump past string
            {
                // increment i until it gets to end of char or string
                i++;
                for (char c = collectedcode[i-1]; !(collectedcode[i] == c && collectedcode[i-1] != '\\'); i++) {}
            }
        }}

        // handle #include
        {string filename;
        int codelen = collectedcode.size();
        for (int i = 0; i < codelen; i++)
        {
            // look for "#include" in file
            if (collectedcode[i] == '#'
             && collectedcode[i + 1] == 'i'
             && collectedcode[i + 2] == 'n'
             && collectedcode[i + 3] == 'c'
             && collectedcode[i + 4] == 'l'
             && collectedcode[i + 5] == 'u'
             && collectedcode[i + 6] == 'd'
             && collectedcode[i + 7] == 'e')
             {
                 // read include file
             }
        }}
    } while (includecount > 0);
    
    return collectedcode;
}