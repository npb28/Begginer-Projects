
//Program allows the user to check whether a given number is armstrong number or not.

#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

class ArmstrongNumber {
  private:
    int usersNumber; //holds user's number imputed
    bool validNumber; //holds if numbered entered by user is valid
    int *numberArr; //points to a dynamic array
    int totalDigits; //holds total digits in number
    int calculatedNumber; //holds post power calculated number

  public:
    ArmstrongNumber(); //constructor
    void getUserInput(); //ask user for a number
    void putNumsInArray(int); //put each digit in a array
    void validateNumber(int); //check user's input
    void getTotalDigits(int); //count digits in user's number
    void doCalculations(); //update digits in the array
    void compare(); //compare calculated number and user's number
    void deleteArray(); //delete dynamic array

};

int main()
{
  ArmstrongNumber number; //create class object

  return 0;
}

ArmstrongNumber::ArmstrongNumber() //default constructor
{
  getUserInput();
  getTotalDigits(usersNumber);
  numberArr = new int[totalDigits]; //dynamically allocate an array
  putNumsInArray(usersNumber);
  doCalculations();
  compare();

}

void ArmstrongNumber::getUserInput() //get user's number and validate it
{
  validNumber = false;

  cout << "Enter a number that's greater than 0." << endl;
  cin >> usersNumber;

  do
  {
    validateNumber(usersNumber);

  }while(validNumber == false);
}

void ArmstrongNumber::putNumsInArray(int num) //put each digit in array
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

void ArmstrongNumber::getTotalDigits(int num) //count digits in user's number
{
  int count = 0;

  while(num != 0)
  {
    num = num / 10;
    count++;
  }

  totalDigits = count; //store number of digits
}

void ArmstrongNumber::validateNumber(int num) //validate user's input
{
  if(num > 0)
  {
    validNumber = true;
  }
}

void ArmstrongNumber::doCalculations()//calculate the power of each digit/update
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

void ArmstrongNumber::compare() //compare new number with user's number
{
  if(calculatedNumber == usersNumber)
  {
    cout << usersNumber << " is a Armstrong Number." << endl;
  }
  else
  {
    cout << usersNumber << " is not a Armstrong Number." << endl;
  }
}

void ArmstrongNumber::deleteArray() //delete dynamic array
{
  delete [] numberArr;
}
