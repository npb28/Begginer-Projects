#include <iomanip>
#include <iostream>
using namespace std;

class Song {
  private:
    int bottles; //number of bottles to begin song
    bool validInput; //validate user's input

  public:
    Song(); //default constuctor
    int getBottles(); //return num of bottles
    void decreaseBottle(); //class method to remove bottle
    void printLyric(); //class method to print lyrics
    void validateInput(int); //validated user's input
    void startingBottles(); //ask user for num of bottles
    void printSong(); //print song with correct num of bottles
};

int main()  //driver program
{
  Song song; //create class object
  song.printSong(); //call object's method

  return 0;
}

Song::Song() //default constructor
{
  startingBottles(); //calling method to get num of bottles
}

int Song::getBottles() //return num of bottles
{
  return bottles;
}

void Song::decreaseBottle() //decrement num of bottles
{
  bottles--;
}

void Song::validateInput(int input) //validate input
{
  if(input > 0)
  {
    validInput = true;
  }
  else
  {
    validInput = false;
  }
}

void Song::startingBottles() //get user's starting bottle num
{
  int startingBottles;

  do
  {
    cout << "How many bottles would you like to start the song with ?" << endl;
    cin >> startingBottles;

    validateInput(startingBottles);

  }while(validInput == false);

  bottles = startingBottles;

}

void Song::printSong() //print entire song's lyrics
{
  for(int num = 0; num < bottles; num++) // call class methods
  {
    printLyric();
    decreaseBottle();
  }
}

void Song::printLyric() //print one lyrical verse
{

  int bottlesLeft = bottles - 1;

  cout << bottles << " bottles of beer on the wall, " << bottles;
  cout << " bottles of beer. Take one down and pass it around, ";
  cout << bottlesLeft << " bottles of beer on the wall" << endl;
  cout << " " << endl;
}
