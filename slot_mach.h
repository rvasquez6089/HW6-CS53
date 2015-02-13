//Programmer: Ryan Vasquez
//Date: October 11, 2013
//Class: CS53 Section F
//Purpose: This is program will act as a slot machine for Moe's homemade
//slot machine. It can transfer money and calculate wins and losses
//for the user
#ifndef SLOT_MACH_INCLUDED
#define SLOT_MACH_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


const int TWOMATCH = 1;
const int THREEMATCH = 30;
const int NOMATCH = -5;
void greeting();
//Desc: greeting(), This function will output a graphic and a greeting to the
//user.
//Input: None.
//Output: none.
int menu_display(int& Menu_choice, const int& Game_balance,
                 const int& Bankk_balance);
//Desc: menu_display(), This function will display the correct menu depending
//on the users balance and will
//give the Menu_choice back to the main() function.
//Input: The user will input his/her menu choice to the program.
//Output: Modify by reference the Menu_choice variable.
void balance_display(const int& Game_balance, const int& Bankk_balance);
//Desc: balance_display, This function will display the user's balances
//on the screen.
//Input: Game_balance, Bankk_balance.
//Output: none
void transfer_funds(int& Game_balance, int& Bankk_balance);
//Desc: Transer_funds, This function will transfer fund from the Bankk_balance
//to the Game_balance via the user input
//Input: Game_balance and the Bankk_balance
//Output: none, but modifies the Game balance and the Bankk Balance
void play(int& Game_balance, const int& Bankk_balance);
//Desc: The play function will allow the user to play the game
//and will display the outputs to the screen.
//Input:  Game balance, Bankk_balance
//Output: Outputs the results of the game to the screen. The function
//will also modify by refernce the Game_balance.
void multiple_play(int& Game_balance, const int& Bankk_balance,
    const int& Num_games, int& games_played);
//Desc: The multiple_play function will let the user play multiple
//times without having to manually intantiate each roll of the game
//Input: Game_balance, Bankk_balance, Num_games, games_played
//Output: None, this will modify the Game_balance depending on how many
//games the player wins and loses.
void auto_lose(char& Rand_int1, char& Rand_int2, char& Rand_int3,
                int& games_played);
//Desc: The auto_lose function will force the user lose after 5 games by
//changing the results of the game before they are output to the user.
//This function needs to be run everytime the user plays a game.
//Input: Rand_int1, Rand_int2, Rand_int3, games_played.
//Output: This will output nothing, but will change the values
//of the its inputs by reference.
void signoff(const int& Bankk_balance, const int& Game_balance);
//Desc: The signoff function will let the user know he/she has ended the
//program and that the program has completed successfully. The function
//will also let the user know his/her Bankk_balance and Game_balance.
//Input: Bankk_balance, Game_balance
//Output: Game_balance and Bankk_balance to the screen.



#endif // SLOT_MACH_INCLUDED
