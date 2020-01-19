/*
  Still need to comment code & refactor

  Allow the user to input the total weight of each type of coin they have
  (pennies, nickels, dimes, and quarters).
  Print out how many of each type of coin wrapper they would need, how many
  coins they have, and the estimated total value of all of their money.
  Subgoals:
  Round all numbers printed out to the nearest whole number.
  Allow the user to select whether they want to submit the weight in either
  grams or pounds.
*/

#include <iomanip>
#include <iostream>
#include <time.h>
#include <map>

using namespace std;

class Coins
{
  public:
    Coins();
    void getWeight();
    void wrappersNeeded(char);
    void displayWrappers(char);
    void getAmount();


  private:
    const static float PENNY = 2.5;
    const static float NICKEL = 5.0;
    const static float DIME = 2.268;
    const static float QUARTER = 5.67;
    float pTotalWeight;
    float nTotalWeight;
    float dTotalWeight;
    float qTotalWeight;
    int pWrappers;
    int nWrappers;
    int dWrappers;
    int qWrappers;
};

int main()
{
  Coins start;

  return 0;
}

Coins::Coins()
{
  getWeight();
  wrappersNeeded('p');
  wrappersNeeded('n');
  wrappersNeeded('d');
  wrappersNeeded('q');
  getAmount();
}

void Coins::getWeight()
{
  cout << "Enter the weight of each coin." << endl;
  cin >> pTotalWeight;
  cin >> nTotalWeight;
  cin >> dTotalWeight;
  cin >> qTotalWeight;
}

void Coins::wrappersNeeded(char type)
{
  const int pennyWrap = 50;
  const int nickelWrap = 40;
  const int dimeWrap = 50;
  const int quarterWrap = 40;
  int numPennies;
  int numNickels;
  int numDimes;
  int numQuarter;

  if(type == 'p')
  {
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

void Coins::displayWrappers(char type)
{
  switch (type)
  {
    case 'p':
      cout << "You need " << pWrappers << " penny wrappers." << endl;
      break;
    case 'n':
      cout << "You need " << nWrappers << " nickel wrappers." << endl;
      break;
    case 'd':
      cout << "You need " << dWrappers << " dime wrappers." << endl;
      break;
    case 'q':
      cout << "You need " << qWrappers << " quarter wrappers." << endl;
  }
}

void Coins::getAmount()
{
  double totalAmount = 0;

  totalAmount += (pWrappers * 0.5);
  totalAmount += (nWrappers * 2);
  totalAmount += (dWrappers * 5);
  totalAmount += (qWrappers * 10);

  cout << "Your total is: $" << totalAmount << endl;
}

//125 200 113.4 226.8
