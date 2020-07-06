
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void introduction(string obj, string ins); 
string getFileName(); 

int main()
{
    
    string objective = "Decode any string entered by subtracting 1 to the ASCII value, outputs to secret.txt"; 
    string instructions = ""; 
    string output;
    ifstream fin; 
    ofstream fout;
    string line;
    int lineNumber = 0; 
    string fileName = "secret.txt";
    introduction(objective, instructions);


    output = getFileName();
    fin.open(fileName.c_str());
    fout.open(output.c_str());
    if (!(fin.good())) throw "I/O error";

    while (fin.good())
    {
        lineNumber = lineNumber + 1;
        getline(fin, line);
        for (int i = 0; i < line.length(); i++) {

            line[i] = line[i] + 1;

        }



        fout << line << endl;
        cout << line << endl;
    }

}


void introduction(string obj, string ins)
{

    cout << "Objective: This program will ";
    cout << obj << endl;
    cout << "Programmer: Teacher\n";
    cout << "Editor(s) used: Notepad\n";
    cout << "Compiler(s) used: TDM MinGW\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
    cout << endl << ins << endl << endl;
}
string getFileName()
{

    string fN; 


    do
    {
        cout << "Please enter an input filename [i.e.: x.txt]: ";
        getline(cin, fN);
    } while (!(fN.length() >= 5)); 
    return fN;
}