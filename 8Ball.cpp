/*
Simulate a magic 8-ball.
Allow the user to enter their question.
Display an in progress message(i.e. "thinking").
Create 20 responses, and show a random response.
Allow the user to ask another question or quit.
*/

#include <iomanip>
#include <iostream>
#include <time.h>
#include <map>

using namespace std;

class EightBall
{
  public:
    EightBall();
    void askQuestion();
    void showThinking();
    void responses(int);
    int randomNum();
    void displayMenu();
    int getChoice();


  private:
    string usersQ;
    int randomNumber;
};

int main()
{
  EightBall startGame;

  return 0;
}

EightBall::EightBall()
{
  int choice;

  do
  {
    displayMenu();
    choice = getChoice();

    if(choice != 2)
    {
      askQuestion();
      showThinking();
      randomNum();

      switch(choice)
      {
        case 1:
          responses(randomNumber);
      }
    }
  }while(choice != 2);
}

void EightBall::askQuestion()
{
  cout << "Enter a question to ask.\n" << endl;
  cin >> usersQ;
  cout << " " << endl;
}

void EightBall::showThinking()
{
  cout << "Thinking...\n" << endl;
}

void EightBall::responses(int num)
{
  map<int, string> responses;

  responses[1] = "Nigel";
  responses[2] = "Pierre";
  responses[3] = "Bonnain";
  responses[4] = "Heather";
  responses[5] = "Kris";
  responses[6] = "Deshon";
  responses[7] = "Marcus";
  responses[8] = "Pooh";
  responses[9] = "Linda";
  responses[10] = "Lundynn";
  responses[11] = "Messiah";
  responses[12] = "Jordan";
  responses[13] = "Rico";
  responses[14] = "David";
  responses[15] = "Kevin";
  responses[16] = "Nikki";
  responses[17] = "Terrion";
  responses[18] = "Herbert";
  responses[19] = "Roberta";
  responses[20] = "Stephanie";

  cout << responses.at(num) << endl;

  cout << "\nPress the enter key to return to the menu.";
  cin.get();
  cin.get();
}

int EightBall::randomNum()
{
  srand(time(NULL));
  randomNumber = rand() % 20 + 1;

  return randomNumber;
}

void EightBall::displayMenu()
{
  system("cls");
  cout << "Welcome to the magic 8 Ball. \n" << endl;
  cout << "1. Ask question." << endl;
  cout << "2. Exit program.\n" << endl;
}

int EightBall::getChoice()
{
  int choice;
  cin >> choice;

  return choice;
}
