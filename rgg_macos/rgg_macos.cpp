/*   
    <Random Goethe Generator; Output random quotes from Goethes texts.>
    V 1.1 Copyright (C) <2018>  <Berat Ademi>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

	Developer E-Mail: rgg@support.ademib.de
*/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cmath>
#include <vector>
#include <limits>
using namespace std;

int linecount = 0; //count for the lines the file provides
int sentcount = 0; //count for the sentences
bool run = true;  //variable to control while loop
				   


//welcoming text
char rggstart() {
	char modein = ' '; //char that stores user input for mode

 //output to start program
	cout << "Random Goethe Generator V1.1  Copyright(C) 2018  Berat Ademi" << endl;
	cout << "This program comes with ABSOLUTELY NO WARRANTY; for details visit https://opensource.org/licenses/GPL-3.0" << endl;
	cout << "This is free software, and you are welcome to redistribute it" << endl;
	cout << "under certain conditions; visit https://opensource.org/licenses/GPL-3.0 for details." << endl;
	cout << string(2, '\n');
	cout << "You have three options to choose from." << endl;
	cout << "1. [P]oem: Output of full poems written by Goethe." << endl;
	cout << "2. [D]rama: Output of single quotes found in Goethes dramas." << endl;
	cout << "3. E[x]it" << endl;
	cout << endl;
	cout << "Which option would you like to use?" << endl;
	cin >> modein;

	cout << string(2, '\n');

	return modein;
}


//function picks a random text to return; user input for choosen mode
string randtxt(char mode)
{
  int randtxt_int = 0;  //final random number
  string drama[1] = {"texts_macos/Faust.txt"}; //string arrays with the file names that contain the texts
  string poem[2] = {"texts_macos/KeinWesen.txt", "texts_macos/Heidenroeslein.txt"};
  srand(time(0)); //sets seed number for rand function

  //picking the random text or exit based on the user input
  if(mode == 'd' || mode == 'D')
  {
    randtxt_int = rand() % 1; return drama[randtxt_int];
  }
  else if(mode == 'p' || mode == 'P')
  {
    randtxt_int = rand() % 2; return poem[randtxt_int];
  }
  else if(mode == 'x' || mode == 'X')
  {
    return "exit";
  }
  else
  {
      cout << "The chosen option is not available!" << endl ;
      cout << "Enter a valid opton: ";
      char a = ' ';
      cin >> a;
      return randtxt(a);
  }
}

//function generates a random number to pick a line
int randintline()
{
	srand(time(0)); //sets seed number for rand function
	int randQuote_int = 0; //int for random linenumber
	randQuote_int = rand() % linecount;
	linecount = 0; //resets linecount
	return randQuote_int;
}

//function generates a random number to pick quote (sentence)
int randintsent()
{
	srand(time(0)); //sets seed number for rand function
	int randQuote_int = 0; //int for random linenumber
	randQuote_int = rand() % sentcount;
	sentcount = 0; //resets sentcount
	return randQuote_int;
}


//function reads text from file and returns vector with lines from file as strings
vector<string> textin(string txt)
{
	char retry = 'y'; //char for controling do-while
	string line = ""; //string that saves single lines from file, to pass it to the vector and to process them
	vector<string>tmp_vect; //initializing vector
	vector<string>end_vect; //initializing end-vector
	tmp_vect.clear(); //makes sure the vector is empty to avoid running out of memory

	ifstream goethe(txt); // opens file

	//reads file
	while (retry == 'y' || retry == 'Y')
	{
		if (goethe.is_open()) {
			while (!goethe.eof())  //checks if the end of file is reached
			{
				getline(goethe, line);
				if (line != " ")
				{
					tmp_vect.push_back(line);
					linecount++;
				}
			}
			retry = 'n';
			goethe.close();
		}
		else
		{
			cout << "Unable to open file." << endl;
			cout << "Try again? [Y]es / [N]o" << endl;
			cin >> retry;
		}
	}
	
	//split tmp_vect into sentences
	end_vect.clear();
	
	line = tmp_vect[randintline()];
	tmp_vect.clear();

	for (int i = 0; i < line.length(); i++) {

		switch (line[i]) {
			case '.': end_vect.push_back(line.substr(0, line.find('.')+1));
						line.erase(0, line.find('.')+1);
						sentcount++;
						break;
			case '?': end_vect.push_back(line.substr(0, line.find('?')+1));
						line.erase(0, line.find('?')+1);
						sentcount++;
						break;
			case '!': end_vect.push_back(line.substr(0, line.find('!')+1));
						line.erase(0, line.find('!')+1);
						sentcount++;
						break;

			default: break;
		}
	}

      return end_vect;
}

int main() {

	char modein = rggstart();

  while(run)
  {
    string output = ""; //string that stores the output to process output before actual output
    string a = "";
		a = randtxt(modein); //string that stores file name of random text

    if(a == "exit")
    {
      return 0;
    }


    vector<string>vect; //vector that will contain text
    vect.clear(); //making sure the vector is empty to avoid running out of memory
    vect = textin(a); //getting read text from file

		int output_int = randintsent();
    output = vect[output_int]; //setting output to be one random object from vect
  
    //processing output for better looks
    for(int i = 0; i < output.length(); i++)
    {
      switch(output[i])
      {
        case ' ': if(output[i+1] == ' ')
                  {
                    output[i+1] = '\n';
                  }
                  break;

        default: break;
      }
    }

		//adding the name of poem/character to output
		if(output_int != 0)
		{
			string tmp = vect[0];
			cout << tmp.substr(0, tmp.find(':')+1);
		}

    //output
    cout << output << endl;
    cout << string(2, '\n');
  	cout << "Do you want to see another quote? ([P]oem, [D]rama or E[x]it)" << endl;
    cin >> modein;
    cout << endl;
  }
  return 0;
}
