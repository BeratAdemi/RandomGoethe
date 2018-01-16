#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cmath>
#include <vector>
#include <limits>
using namespace std;

int linecount = 0; //count for the lines the file provides
bool run = true;
char tmp ='Y';
string randtxt(char mode)
{
  int randtxt_int = 0;
  string drama[1] = {"Faust.txt"};
  string poem[2] = {"KeinWesen.txt", "Heidenröslein.txt"};
  srand(time(0)); //sets seed number for rand function

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

vector<string> textin(string txt)
{
  char retry = 'y'; //char for controling do-while
  string line = ""; //string that saves single lines from file, to pass it on to the vector
  vector<string>xvec;

    ifstream goethe(txt); // opens file

    while(retry == 'y' || retry == 'Y')
    {
      if(goethe.is_open()){
        while(!goethe.eof())
        {
          getline(goethe, line);
          if (line != " ")
          {
            xvec.push_back(line);
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
      return xvec;
}

int randint()
{
  srand(time(0)); //sets seed number for rand function
  int randQuote_int = 0; //int for random linenumber
  randQuote_int = rand() % linecount;
  return randQuote_int;
}

// main() is where program execution begins.
int main() {

  while(run)
  {
    char modein = ' ';
    cout << "Random Goethe Generator" << endl;
    cout << "You have three options to choose from." << endl;
    cout << "1. [P]oem: Output of full poems written by Goethe." << endl;
    cout << "2. [D]rama: Output of single quotes found in Goethes dramas." << endl;
    cout << "3. E[x]it" << endl;
    cout << endl;
    cout << "Which option would you like to use?" << endl;
    cin >> modein;

    cout << string(2, '\n');

    string output = "";
    string a = randtxt(modein);

    if(a == "exit")
    {
      return 0;
    }

    vector<string>vect = textin(a);

    output = vect[randint()];
    for(int i = 0; i < output.length(); i++)
    {
      switch(output[i]) //switch modifies output
      {
        case ' ': if(output[i+1] == ' ')
                  {
                    output[i+1] = '\n';
                  }
                  break;

        default: break;
      }
    }
    cout << output << endl;
    cout << string(2, '\n');
    cout << "Again? [Y/N]";
    cin >> tmp;
    cout << endl;
    if(tmp == 'N' || tmp == 'n')
    {
      run = false;
    }
  }
  return 0;
}

/*
Roadmap:
Schleife, damit man das Programm immer weiter ausführt. ==> leeren des Vectors xD
GUI
compiled package
Website
more texts
*/