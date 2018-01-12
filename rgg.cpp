#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;



void quote(){
  char retry = ' '; //char for controling do-while
  int linecount = 0; //count for the lines the file provides
  int coloncount = 0; //counting colons for better looking output
  int randQuote_int = 0; //int for random linenumber
  string line = ""; //string that saves single lines from file, to pass it on to the vector
  string output = "";
  vector<string>randQuote_vect; //dynamic array with text; lines stored as single strings

  ifstream goethe("Faust.txt"); //opens file

  do{

      srand(time(0)); //sets seed number for rand function

      if(goethe.is_open()){
        while(!goethe.eof())
        {
          getline(goethe, line);
          if (line != " ")
          {
            randQuote_vect.push_back(line);
            linecount++;
          }
        }

        randQuote_int = rand() % linecount;

        output = randQuote_vect[randQuote_int];
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
        cout << output << endl;

        goethe.close();
      }

      else{
        cout << "Unable to open file." << endl;
        cout << "Try again? [Y]es / [N]o" << endl;
        cin >> retry;
      }
  } while (retry == 'y' || retry == 'Y');
}

// main() is where program execution begins.
int main() {
quote();
return 0;
}
