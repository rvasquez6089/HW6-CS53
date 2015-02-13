//Programmer: Ryan Vasquez
//Date: October 11, 2013
//Class: CS53 Section F
//Purpose: This is program will act as a slot machine for Moe's homemade
//slot machine. It can transfer money and calculate wins and losses
//for the user

#include "slot_mach.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void greeting()
{
  //------_This section welcomes the user to the program----//
    cout<<"Welcome to Moe's homemade slot machine!"<<endl;
    cout<<"Step right up and try your luck!"<<endl;
    cout<<"      .-------."<<endl;
    cout<<"   oO{-JACKPOT-}Oo"<<endl;
    cout<<"   .=============. __"<<endl;
    cout<<"   | [a] [X] [o] |(  )"<<endl;
    cout<<"   | [$] [$] [$] | ||"<<endl;
    cout<<"   | [X] [o] [$] | ||"<<endl;
    cout<<"   |             |_||"<<endl;
    cout<<"   | $$$ ::::::: |--'"<<endl;
    cout<<"   |      __ === |"<<endl;
    cout<<"   |_____/__\\____|"<<endl;
    cout<<"  /###############\\"<<endl;
    cout<<" /#################\\"<<endl;
    cout<<"|###################|"<<endl;
}

int menu_display(int& Menu_choice, const int& Game_balance,
                 const int& Bankk_balance)
{
  if(Bankk_balance >=5 || Game_balance >= 5)//This logic statement checks if the
      //user has more than 5 dollars in his bankk account
      {
        do
        {
          cout<<"---------------------------------------"<<endl;
          cout<<"             Options                  |"<<endl;
          cout<<"---------------------------------------"<<endl;
          cout<<"1. Check Bankk balance                |"<<endl;
          cout<<"2. Transfer funds to game             |"<<endl;
          cout<<"3. Play                               |"<<endl;
          cout<<"4. Leave (cash out)                   |"<<endl;
          cout<<"---------------------------------------"<<endl;
          cout<<"Please enter your menu choice now: "; //Prompts the user for a
          //menu choice
          cin>>Menu_choice;
        }while (Menu_choice < 1 || Menu_choice >4);
      }
      else if (Game_balance < 5 && Bankk_balance >= 5)//This logic line will
      //take away the option to play if he has no money is his game balance
      //but he has money in his bankk balance.
      {
        do
        {
          cout<<"---------------------------------------"<<endl;
          cout<<"             Options                  |"<<endl;
          cout<<"---------------------------------------"<<endl;
          cout<<"1. Check Bankk balance                |"<<endl;
          cout<<"2. Transfer funds to game             |"<<endl;
          cout<<"4. Leave (cash out)                   |"<<endl;
          cout<<"---------------------------------------"<<endl;
          cout<<"Please enter your menu choice now: "; //Prompts the user for a
          //menu choice
          cin>>Menu_choice;
        }while(Menu_choice != 1 && Menu_choice != 2 && Menu_choice != 4);
      }
      else //If the user does not have any money in either account he is given
      //no option but to leave or continue to check his balance.
      {
        do
        {
          cout<<"---------------------------------------"<<endl;
          cout<<"             Options                  |"<<endl;
          cout<<"---------------------------------------"<<endl;
          cout<<"1. Check Bankk balance                |"<<endl;
          cout<<"4. Leave (cash out)                   |"<<endl;
          cout<<"---------------------------------------"<<endl;
          cout<<"Please enter your menu choice now: "; //Prompts the user for a
          //menu choice
          cin>>Menu_choice;
        }while(Menu_choice != 1 && Menu_choice != 4);
      }

  return Menu_choice;
}

void balance_display(const int& Game_balance, const int& Bankk_balance)
{
  cout<<" \n Your Bankk Balance is $"<< Bankk_balance<<endl;
  cout<<" \n Your Game Balance is $"<< Game_balance<<endl;
}

void transfer_funds(int& Game_balance, int& Bankk_balance)
{
  int Transfunds;
  cout<<" \n Please enter the amount of money you would like"<<endl;
  cout<<"transfer to the game. $";
  cin>>Transfunds;
  if (Transfunds > Bankk_balance)
  {
    cout<<"Transfer Unsuccessful, you can't transfer more money "<<endl;
    cout<<"than your bankk account has in it."<<endl;
  }
  else
  {
    Game_balance = Game_balance + Transfunds; //This line adds the transfer
    //transfer amount to the game balance
    Bankk_balance = Bankk_balance - Transfunds; //This line subtracts the
    //transfer amount form the bankk balance
    cout<<"Your transfer was successful."<<endl; //Confirms a successful
    //transaction
  }

}

void play(int& Game_balance, const int& Bankk_balance)
{
  static int games_played = 0; //This static variable will keep count of
  //how many games the user plays and will help to make the player have a
  //forced loss after 5 games so that Moe can make a garunteed profit.
  char Rand_int1, Rand_int2, Rand_int3;
  int Num_games;
  srand(time(NULL));
  cout<<"Get ready to play!"<<endl<<endl;
  do
  {
    cout<<"How many games would you like to cycle through?"<<endl;
    cin>>Num_games;
  }while(Num_games <= 0);
  if (Num_games > 1)
  {
    multiple_play(Game_balance, Bankk_balance, Num_games, games_played);
  }
  else
  {
    games_played++;
    Rand_int1 = rand()%4 + 97;//This will generate the random number
    Rand_int2 = rand()%4 + 97;//This will generate the random number
    Rand_int3 = rand()%4 + 97;//This will generate the random number
    //The following section will output the results of the three
    //random numbers to the user in a user-friendly fasion.
    auto_lose(Rand_int1, Rand_int2, Rand_int3, games_played);
    //The auto_lose function will run everytime a game is played. If the number
    //of games played is more than 5 it will modify by reference the random
    //outputs so that the player loses.
    cout<<"_______________________"<<endl;
    cout<<"|                     |"<<endl;
    cout<<"|    "<<Rand_int1<<"  |  "<<Rand_int2<<"  |  "<<Rand_int3<<" "
    <<"   |"<<endl;
    cout<<"|                     |"<<endl;
    cout<<"-----------------------"<<endl<<endl;
    if( Rand_int1 == Rand_int2 && Rand_int2 == Rand_int3)//This logic
        //statement will check if three of the random number match and
        //add thirty dollars the game balance for the user.
    {
      Game_balance += THREEMATCH;
      cout<<"You won $30!!!!"<<endl;

    }
    else if ( Rand_int1 == Rand_int2 || Rand_int1 == Rand_int3 ||
          Rand_int3 == Rand_int2)//This logic statement will check if two
          //of the random numbers match and will add 1 dollar to the user
          //game balance.
    {
      Game_balance += TWOMATCH;
      cout<<"You won $1, congrats!"<<endl;
    }
    else
    {
      if(Game_balance < 5 && Bankk_balance >= 5)//This logic line
          //will check if the user has money in his bankk account but not
          //in his game balance and will prompt him to transfer more
          //money.
      {
        cout<<"Please transfer more money into the your"<<endl;
        cout<<"game account, you don't have enough money to "<<endl;
        cout<<"pay for this loss"<<endl;
      }
      else if(Game_balance < 5 && Bankk_balance < 5)
       //This logic line will prompt the user to leave the game if he
        //has no money in either account
      {
        cout<<"Please leave the game, you are all out of ";
        cout<<"money"<<endl;
      }
      else
      {
        Game_balance += NOMATCH;
        cout<<"You lost! Try again!"<<endl;
      }
    }
  }

}

void multiple_play(int& Game_balance, const int& Bankk_balance,
                   const int& Num_games, int& games_played)
{
  char Rand_int1;
  char Rand_int2;
  char Rand_int3;
  int Net_Change = 0;
  for(int i = 0; i < Num_games; i++) //The for loop will count
  //and repeat the play action until it reaches the number of
  //repetions the user input or until the user runs out of money
  //, whichever occurs first.
  {
    games_played++;
    Rand_int1 = rand()%4 + 97;//This will generate the random number
    Rand_int2 = rand()%4 + 97;//This will generate the random number
    Rand_int3 = rand()%4 + 97;//This will generate the random number
    //Ascii value 97 is equal to the char 'a', 98 = 'b' and so on. This is not
    //most easy to understand way to convert the numbers to letters, but it is
    //the fastest and shortest way to convert them for the computer.
    auto_lose(Rand_int1, Rand_int2, Rand_int3, games_played);
    cout<<Rand_int1<<"  "<<Rand_int2<<"  "<<Rand_int3<<"  ";
    if(Rand_int1 == Rand_int2 && Rand_int2 == Rand_int3)//This logic
    //statement will check if three of the random number match and
    //add thirty dollars the game balance for the user.
    {
      Game_balance += THREEMATCH;
      Net_Change +=THREEMATCH;
      cout<<"You won $30!"<<endl;
    }
    else if ( Rand_int1 == Rand_int2 || Rand_int1 == Rand_int3 ||
      Rand_int3 == Rand_int2)//This logic statement will check if two
      //of the random numbers match and will add 1 dollar to the user
      //game balance.
    {
      Game_balance += TWOMATCH;
      Net_Change += TWOMATCH;
      cout<<"You won $1!"<<endl;
    }
    else
    {
      if(Game_balance < 5 && Bankk_balance >= 5)//This logic line
      //will check if the user has money in his bankk account but not
      //in his game balance and will prompt him to transfer more
      //money.
      {
        cout<<"Please transfer more money into the your"<<endl;
        cout<<"game account, you don't have enough money to "<<endl;
        cout<<"pay for this loss"<<endl;
        i = Num_games; //This line will cause the for loop to exit
      }
      else if(Game_balance < 5 && Bankk_balance < 5)
      //This logic line will prompt the user to leave the game if he
      //has no money in either account
      {
        cout<<"Please leave the game, you are all out of ";
        cout<<"money"<<endl;
        i = Num_games; //This line will cause the for loop to exit
      }
      else
      {
        Game_balance += NOMATCH;
        Net_Change += NOMATCH;
        cout<<"You lose!"<<endl;
      }
    }
  }
  cout<<"Your net account change is $"<<Net_Change<<endl;
  cout<<"Your game balance is now $"<<Game_balance<<endl;
}

void auto_lose(char& Rand_int1, char& Rand_int2, char& Rand_int3,
                int& games_played)
{
  if(games_played > 5)
  {
    do
    {
      sleep(1);//This will ensure that every loss is different. With out the
      //sleep function the lose result will be the same everytime since its
      //seeded by time and the runs in less than a second.
      srand(time(NULL));
      Rand_int1 = rand()%4 + 97;//This will generate the random number
      Rand_int2 = rand()%4 + 97;//This will generate the random number
      Rand_int3 = rand()%4 + 97;//This will generate the random number
    }while ((Rand_int1 == Rand_int2 || Rand_int1 == Rand_int3 ||
      Rand_int3 == Rand_int2));
  }
  if(games_played >10)//If the number of games is more than 10 then the
  //auto_lose function will reset the counter back to zero. This will prevent
  //the games_played integer from being run past its maximum value and also it
  //will let the player win again so that he will not leave and get frustrated
  //with the game.
  {
    games_played = 0;
  }
}



void signoff(const int& Bankk_balance, const int& Game_balance)
{
  cout<<"Please play come another day goodbye"<<endl;
  cout<<" \n Your Bankk Balance is $"<< Bankk_balance<<endl;
  cout<<" \n Your Game Balance is $"<< Game_balance<<endl;
}

