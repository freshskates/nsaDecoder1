//libraries
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj, string ins); //user introduction
string getFileName(); //get user filename

//main program
int main()
{
    //Data
    string objective = "Decode any string entered by subtracting 1 to the ASCII value, outputs to secret.txt"; //program objective
    string instructions = ""; //user instructions if needed
    string output; //user selected input filename
    ifstream fin; //represents input file
    ofstream fout;
    string line; //one line from input file
    int lineNumber = 0; //number of lines in the input file
    string fileName = "secret.txt";
    introduction(objective, instructions); //user introduction

    //input and open user selected file name

    output = getFileName();
    fin.open(fileName.c_str());
    fout.open(output.c_str());
    if (!(fin.good())) throw "I/O error";

    //read and output each line in the input file
    while (fin.good())
    {
        lineNumber = lineNumber + 1;
        getline(fin, line);
        for (int i = 0; i < line.length(); i++) {

            line[i] = line[i] + 1;

        }



        fout << line << endl;
        cout << line << endl;
    }//while fin.good

}//main

// introduction
void introduction(string obj, string ins)
{
    //data
    //obj is the program objective from main program
    //ins is the optional user instructions

    //output user introduction
    cout << "Objective: This program will ";
    cout << obj << endl;
    cout << "Programmer: Teacher\n";
    cout << "Editor(s) used: Notepad\n";
    cout << "Compiler(s) used: TDM MinGW\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
    cout << endl << ins << endl << endl;
}//introduction

//get user specified filename
string getFileName()
{
    //data
    string fN; //user specified filename

    //input filename
    do
    {
        cout << "Please enter an input filename [i.e.: x.txt]: ";
        getline(cin, fN);
    } while (!(fN.length() >= 5)); //do-while
    return fN;
}//getFileName