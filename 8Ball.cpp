/*
  Remaining Task:
      1. Fix askQuestion() funtion
      2. Comment code
      3. Refactor
*/

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
    void randomNum();
    void displayMenu();
    void getChoice();
    void case1Task();
    void case2Task();


  private:
    string usersQ;
    int randomNumber;
    int choice;
};

int main()
{
  EightBall startGame;

  return 0;
}

EightBall::EightBall()
{
  do
  {
    randomNum();
    displayMenu();
    getChoice();

    if(choice != 3)
    {
      switch(choice)
      {
        case 1: case1Task();
                break;
        case 2: case2Task();
      }
    }
  } while(choice != 3);
}

void EightBall::askQuestion()
{
  cout << "\nEnter a question to ask.\n" << endl;
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
}

void EightBall::randomNum()
{
  srand(time(NULL));
  randomNumber = rand() % 20 + 1;
}

void EightBall::displayMenu()
{
  system("clear");
  cout << "\nWelcome to the magic 8 Ball.\n" << endl;
  cout << "1. Ask question." << endl;
  cout << "2. Check previous question." << endl;
  cout << "3. Exit program.\n" << endl;
}

void EightBall::getChoice()
{
  cin >> choice;
}
void EightBall::case1Task()
{
  askQuestion();
  showThinking();
  responses(randomNumber);

  cout << "\nPress the enter key to return to the menu.";
  cin.get();
  cin.get();
}

void EightBall::case2Task()
{
  cout << "\nYour previous question was: " << usersQ << endl;

  cout << "\nPress the enter key to return to the menu.";
  cin.get();
  cin.get();
}
