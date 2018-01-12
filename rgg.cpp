#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;

int linecount = 0; //count for the lines the file provides

string randtxt()
{
  int randtxt_int = 0;
  string texts[2] = {"Faust.txt", "KeinWesen.txt"};
  srand(time(0)); //sets seed number for rand function

  randtxt_int = rand() % 2;

  return texts[randtxt_int];
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
string output = "";
string a = randtxt();
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
return 0;
}
