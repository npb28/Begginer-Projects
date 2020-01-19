/*
  Program allows user to enter the weight of total pennies, nickels, dimes &
  quarters. Program then calculates the number of wrappers needed for each coin.
  Program then calculates the total dollar worth of all coins combined. The coin
  weight is in grams.
*/

#include <iomanip>
#include <iostream>
#include <time.h>
#include <map>

using namespace std;

class Coins
{
  public:
    Coins(); //constructor
    void getWeight(); //ask user for weight of each coin
    void wrappersNeeded(char); //calculate num of wrappers needed
    void displayWrappers(char); //output to screen num of wrappers needed
    void getAmount(); //calculate total amount of all coins


  private:
    const static float PENNY = 2.5; //default weight of coins
    const static float NICKEL = 5.0;
    const static float DIME = 2.268;
    const static float QUARTER = 5.67;
    float pTotalWeight; //holds weight of all user's pennies
    float nTotalWeight; //holds weight of all user's nickels
    float dTotalWeight; //holds weight of all user's dimes
    float qTotalWeight; //holds weight of all user's quarters
    int pWrappers; //holds num of penny wrappers needed
    int nWrappers; //holds num of nickel wrappers needed
    int dWrappers; //holds num of dime wrappers needed
    int qWrappers; //holds num of quarter wrappers needed
};

int main()
{
  Coins start; //creates object to start program

  return 0;
}

Coins::Coins() //default constructor
{
  getWeight(); //gets weights from user
  wrappersNeeded('p'); //gets num of penny wrappers needed
  wrappersNeeded('n'); //gets num of nickel wrappers needed
  wrappersNeeded('d'); //gets num of dime wrappers needed
  wrappersNeeded('q'); //gets num of quarter wrappers needed
  getAmount(); //get total dollar amount
}

void Coins::getWeight() //gets each coins weight from user
{
  cout << "Enter the weight of each coin.\n" << endl;
  cin >> pTotalWeight;
  cin >> nTotalWeight;
  cin >> dTotalWeight;
  cin >> qTotalWeight;
  system("clear");
}

void Coins::wrappersNeeded(char type) //calculates needed wrappers
{
  const int pennyWrap = 50; //how many coins go in each wrapper
  const int nickelWrap = 40;
  const int dimeWrap = 50;
  const int quarterWrap = 40;
  int numPennies; //number of pennies
  int numNickels; //number of nickels
  int numDimes; //number of dimes
  int numQuarter; //number of quarters

  if(type == 'p') //determines num of each coin, needed wrappers & displays
  {               // that info to user
    numPennies = pTotalWeight / PENNY;
    pWrappers = numPennies / pennyWrap;
    displayWrappers(type);
  }
  else if(type == 'n')
  {
    numNickels = nTotalWeight / NICKEL;
    nWrappers = numNickels / nickelWrap;
    displayWrappers(type);
  }
  else if(type == 'd')
  {
    numDimes = dTotalWeight / DIME;
    dWrappers = numDimes / dimeWrap;
    displayWrappers(type);
  }
  else
  {
    numQuarter = qTotalWeight / QUARTER;
    qWrappers = numQuarter / quarterWrap;
    displayWrappers(type);
  }
}

void Coins::displayWrappers(char type) //displays needed wrappers to user
{
  switch (type)
  {
    case 'p':
      cout << "You need " << pWrappers << " penny wrappers.\n" << endl;
      break;
    case 'n':
      cout << "You need " << nWrappers << " nickel wrappers.\n" << endl;
      break;
    case 'd':
      cout << "You need " << dWrappers << " dime wrappers.\n" << endl;
      break;
    case 'q':
      cout << "You need " << qWrappers << " quarter wrappers.\n" << endl;
  }
}

void Coins::getAmount() //calculates dollar amount
{
  double totalAmount = 0;

  totalAmount += (pWrappers * 0.5);
  totalAmount += (nWrappers * 2);
  totalAmount += (dWrappers * 5);
  totalAmount += (qWrappers * 10);

  cout << fixed << showpoint << setprecision(2); //sets alignment for amount
  cout << "Your total is: $" << totalAmount << endl;
}

//125 200 113.4 226.8
