#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

class ArmstrongNumber {
  private:
    int usersNumber;
    bool validNumber;
    int *numberArr;
    int totalDigits;
    int calculatedNumber;

  public:
    ArmstrongNumber();
    void getUserInput();
    void putNumsInArray(int);
    void validateNumber(int);
    void getTotalDigits(int);
    void doCalculations();
    void compare();

};

int main()
{
  ArmstrongNumber number;



  return 0;
}

ArmstrongNumber::ArmstrongNumber()
{
  getUserInput();
  getTotalDigits(usersNumber);
  numberArr = new int[totalDigits];
  putNumsInArray(usersNumber);
  doCalculations();
  compare();

}

void ArmstrongNumber::getUserInput()
{
  validNumber = false;

  cout << "Enter a number that's greater than 0." << endl;
  cin >> usersNumber;

  do
  {
    validateNumber(usersNumber);

  }while(validNumber == false);
}

void ArmstrongNumber::putNumsInArray(int num)
{
  int count = 0;
  int numberIntoArray = num;

  while(num != 0)
  {
    numberIntoArray = num % 10;
    num = num / 10;
    numberArr[count] = numberIntoArray;
    count++;
  }
}

void ArmstrongNumber::getTotalDigits(int num)
{
  int count = 0;

  while(num != 0)
  {
    num = num / 10;
    count++;
  }

  totalDigits = count;
}

void ArmstrongNumber::validateNumber(int num)
{
  if(num > 0)
  {
    validNumber = true;
  }
}

void ArmstrongNumber::doCalculations()
{
  int calculatedNum = 0;

  for(int index = 0; index < totalDigits; index++)
  {
    numberArr[index] = pow(numberArr[index], totalDigits);
  }

  for(int index = 0; index < totalDigits; index++)
  {
    calculatedNum += numberArr[index];
  }
  calculatedNumber = calculatedNum;
}

void ArmstrongNumber::compare()
{
  if(calculatedNumber == usersNumber)
  {
    cout << usersNumber << " is a ArmstrongNumber." << endl;
  }
  else
  {
    cout << usersNumber << " is not a ArmstrongNumber." << endl;
  }
}
