//Programmer: Ryan Vasquez
//Date: October 11, 2013
//Class: CS53 Section F
//Purpose: This is program will act as a slot machine for Moe's homemade
//slot machine. It can transfer money and calculate wins and losses
//for the user
#include <iostream>

#include "slot_mach.h"
using namespace std;

int main()
{
    int Game_balance = 0;//Initializes Game_balance to 0 so that the user does
    //not get junk when he/shee checks thier balance for the first time.
    int Bankk_balance = 0;
    int Menu_choice;
    bool money_transferred = 0;
    srand(time(NULL));
    Bankk_balance = rand()%801 + 200; //This line of program seeds the intial
    //bankk balance between $200-$1000 for the user
    greeting();
    do
    {
      menu_display(Menu_choice, Game_balance, Bankk_balance);
      switch(Menu_choice)
      {
        case 1: //Will display the bankk balance and the game balance
          balance_display(Game_balance, Bankk_balance);
          break;
        case 2: //This will transfer funds from the bank to the game
          transfer_funds(Game_balance, Bankk_balance);
          money_transferred = 1;
          break;
          case 3:
          if (money_transferred == 1)//This will make sure that the user
          //tranfers money to thier account before they play.
          {
            play(Game_balance, Bankk_balance);
          }
          else
          {
            cout<<"Please Transfer money into you Game account"<<endl;
          }
          break;
        case 4:
            signoff(Bankk_balance, Game_balance);
            break;
        default:
            cout<<"Please Enter a valid menu choice"<<endl;
            break;
      }
    }while( Menu_choice != 4); //This logic statement will make the loop
    //continue until the user has chosen to leave the game.
}
