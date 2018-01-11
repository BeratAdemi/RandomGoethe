#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;



void quote(){
  char retry = ' ';
  int linecount = 0;
  int randQuote_int = 0;
  string line = "";
  vector<string>randQuote_vect;

  ifstream goethe("Faust.txt");

  do{

      srand(time(0));

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
        cout << randQuote_vect[randQuote_int] << endl;
        goethe.close();
        cout << randQuote_vect.size() << endl;
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
