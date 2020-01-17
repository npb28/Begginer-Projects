/* 
  Remaining Task
    -Add comments
    -Refactor
 */

//Simulate a magic 8-ball.


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
    char usersQ[20];
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

  system("clear");
}

void EightBall::askQuestion()
{
  system("clear");
  cout << "\nEnter a question to ask.\n" << endl;
  cin.ignore(1000, '\n');
  cin.getline(usersQ, 20);
  cout << " " << endl;
}

void EightBall::showThinking()
{
  cout << "Thinking...\n" << endl;
}

void EightBall::responses(int num)
{
  map<int, string> responses;

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
}

void EightBall::case2Task()
{
  cout << "\nYour previous question was: " << usersQ << endl;

  cout << "\nPress the enter key to return to the menu.";
  cin.get();
  cin.get();
}
