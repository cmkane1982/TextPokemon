#ifndef __BATTLE_H__
#define __BATTLE_H__

#include "Character.h"
#include "Rival.h"
#include "Pokemon.h"

void combat(Character* myChar, Rival* myRival);
void combat(Character* myChar);
void combatDisplay(Pokemon* myPokemon, Pokemon* enemyPokemon);
int displayInventory(Inventory myInv);
int displayMoves(Pokemon *pokemon);
int displayPokemon(Character* myChar);
void attack(Character* myChar, Rival* myRival, int attackNum);

#endif