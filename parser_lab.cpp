// Lab exercise - Parser                 


#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>

using namespace std;

// prototypes
string GetToken();
void error(int);

int main()
{
	string token;
	int sizeOfToken;

	cout << "Please enter a declaration in format "
		<< "<type> <variable> [= number] ;" << endl;

	token = GetToken();

	vector <string> tokens; // vector of strings

	stringstream check1(token);

	string temp;

	bool flag1 = true; // bool variables to signal condition of action
	bool flag2 = true;
	bool flag3 = true;

	while (getline(check1, temp, ' '))
	{
		tokens.push_back(temp);
	}

	sizeOfToken = tokens.size();

	if (tokens[0] != "int" && tokens[0] != "float")
	{
		error(1);
		flag3 = false; // condition fails
	}


	if (sizeOfToken == 2)
	{
		// check variable name and semicolon
		temp = tokens[1];
		if (temp.back() != ';')
		{
			error(4);
			flag1 = false; // signals error 
		}
		if (temp[0] != 'A' && temp[0] != 'B' &&temp[0] != 'C' &&temp[0] != 'D' &&temp[0] != 'E')
		{
			error(2);
			flag2 = false; // signal error
		}
		if (flag1 && flag2 && flag3) // if no error(s) found
			error(0);
	}


	else if (sizeOfToken == 4)
	{
		temp = tokens[1];
		if (temp[0] != 'A' && temp[0] != 'B' &&temp[0] != 'C' &&temp[0] != 'D' &&temp[0] != 'E')
			error(2);
		temp = tokens[3];
		if (temp.back() != ';')
			error(4);
		temp.pop_back();
		if (tokens[0] == "int")
		{
			if (temp != "0" && temp != "1" && temp != "2" && temp != "3" && temp != "4" && temp != "5" && temp != "6" && temp != "7" && temp != "8" && temp != "9")
			{
				error(3);
			}

		}
		else // no error detected
			error(0);
	}


	system("PAUSE");

	return 0;
}
////////////////////////////////////
// GetToken() get the string      //
///////////////////////////////////
string GetToken()
{

	string str;

	getline(cin, str);

	return str;

}
////////////////////////////////////////////
// error()- displays errors message       //
///////////////////////////////////////////
void error(int code)
{
	switch (code)
	{
	case 0: cout << "no errors found" << endl; break;
	case 1: cout << "unrecognizable type" << endl; break;
	case 2: cout << "illegal variable name" << endl; break;
	case 3: cout << "unexpected number" << endl; break;
	case 4: cout << "; expected" << endl;
	}
	return;
}

