#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Dice.h"
#include "Player.h"

using namespace std;

int main()
{  
      // creating Player p1 with 5 dices
      Player p1(5);
      Player p2(5);

      p1.playerRoll();
      p2.playerRoll();
      
      for (int i = 0; i < 5; i++){
            cout << p1.getDiceValueAtIndex(i) << " ";
      }
      cout << endl;
      
      for (int i = 0; i < 5; i++){
            cout << p2.getDiceValueAtIndex(i) << " ";
      }
      cout << endl;
      return 0;
}
