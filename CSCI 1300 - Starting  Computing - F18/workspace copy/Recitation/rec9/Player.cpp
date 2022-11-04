#include "Player.h"
#include "Dice.h"

Player::Player(int nD){
    nDice = nD;
    //Dice d1[nDice];
    for (int i = 0; i < nDice; i++){
        //d1[i].roll();
        myDice[i] = Dice();
        
        /*
        add Dice object created to array of Dices
        */
    }
}

void Player::setNumDice(int number){
    nDice = number;
}

void Player::playerRoll(){
    for (int i = 0; i < nDice; i++)
    {
        myDice[i].roll();
    }
    /*
    complete function to roll all the dices
    */
}

int Player::getDiceValueAtIndex(int i) const{
    
    return myDice[i].getFaceValue();
}