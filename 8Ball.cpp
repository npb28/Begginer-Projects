/*
  This program simulates a magic 8-ball.
*/

#include <iomanip>
#include <iostream>
#include <time.h>
#include <map>

using namespace std;

class EightBall
{
  public:
    EightBall(); //Constructor
    void askQuestion(); //Funtion ask user for their question
    void showThinking(); //Function displays thinking
    void responses(int); //Funtion takes random num & displays 8ball's response
    void randomNum(); //Function generates a random number
    void displayMenu(); //Function displays menu with options for user
    void getChoice(); //Function ask user for menu choice
    void case1Task(); //Function calls functions to complete menu task
    void case2Task(); //Function calls functions to complete menu task


  private:
    char usersQ[100]; //stores user's question
    int randomNumber; //stores random number
    int choice; //stores users menu choice
};

int main()
{
  EightBall startGame; //creates Eightball object to begin game

  return 0;
}

EightBall::EightBall()
{
  do
  {
    randomNum(); //creates random number
    displayMenu(); //displays menu
    getChoice(); //gets user's menu choice

    if(choice != 3)
    {
      switch(choice) //determines which case to perform depending on user
      {
        case 1: case1Task();
                break;
        case 2: case2Task();
      }
    }
  } while(choice != 3); //ends menu loop if user selects option 3

  system("clear"); //clear terminal
}

void EightBall::askQuestion() //gets user's question
{
  system("clear"); //clear terminal
  cout << "\nEnter a question to ask.\n" << endl;
  cin.ignore(1000, '\n'); //clears buffer
  cin.getline(usersQ, 100); //gets users question, including spaces
  cout << " " << endl;
}

void EightBall::showThinking() //displays thinking to screen
{
  cout << "Thinking...\n" << endl;
}

void EightBall::responses(int num) //displays response to user
{
  map<int, string> responses; //a map holding 20 responses

  responses[1] = "It is certain.";
  responses[2] = "It is decidedly so.";
  responses[3] = "Without a doubt.";
  responses[4] = "Yes - definitely.";
  responses[5] = "You may rely on it.";
  responses[6] = "As I see it, yes.";
  responses[7] = "Most likely.";
  responses[8] = "Outlook good.";
  responses[9] = "Yes.";
  responses[10] = "Signs point to yes.";
  responses[11] = "Reply hazy, try again.";
  responses[12] = "Ask again later.";
  responses[13] = "Better not tell you now.";
  responses[14] = "Cannot predict now.";
  responses[15] = "Concentrate and ask again.";
  responses[16] = "Don't count on it.";
  responses[17] = "My reply is no.";
  responses[18] = "My sources say no.";
  responses[19] = "Outlook not so good.";
  responses[20] = "Very doubtful.";

  cout << responses.at(num) << endl;
  cout << " " << endl;
}

void EightBall::randomNum() //generates random number.
{
  srand(time(NULL));
  randomNumber = rand() % 20 + 1;
}

void EightBall::displayMenu() //displays menu
{
  system("clear");
  cout << "\nWelcome to the magic 8 Ball.\n" << endl;
  cout << "1. Ask question." << endl;
  cout << "2. Check previous question." << endl;
  cout << "3. Exit program.\n" << endl;
}

void EightBall::getChoice() //gets user's menu choice
{
  cin >> choice;
}
void EightBall::case1Task() //calls functions to satisfy menu option 1
{
  askQuestion();
  showThinking();
  responses(randomNumber);

  cout << "\nPress the enter key to return to the menu.";
  cin.get();
}

void EightBall::case2Task() //calls functions to satisfy menu option 2
{
  cout << "\nYour previous question was: " << usersQ << endl;

  cout << "\nPress the enter key to return to the menu.";
  cin.get();
  cin.get();
}
