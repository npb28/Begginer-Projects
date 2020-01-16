#include <iomanip>
#include <iostream>
using namespace std;

class Song {
  private:
    int bottles; //number of bottles to begin song
    bool validInput; //validate user's input

  public:
    Song(); //default constuctor
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

void Song::validateInput(int input) //validate input
{
  if(input > 0 && input < 100)
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
  do
  {
    cout << "How many bottles would you like to start the song with ?" << endl;
    cin >> bottles;

    validateInput(bottles);

  }while(validInput == false);

}

void Song::printSong() //print song's lyrics
{
  int startingBottles = bottles;
  int oneLessBottle = bottles - 1;

  for(int num = 0; num < startingBottles; num++) // call class methods
  {
    cout << bottles << " bottles of beer on the wall, " << bottles--;
    cout << " bottles of beer. Take one down and pass it around, ";
    cout << oneLessBottle-- << " bottles of beer on the wall" << endl;
    cout << " " << endl;
  }
}

