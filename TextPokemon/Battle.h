#ifndef __BATTLE_H__
#define __BATTLE_H__

#include "Character.h"
#include "Rival.h"
#include "Pokemon.h"

bool combat(Character* myChar, Rival* myRival);
bool combat(Character* myChar);
void combatDisplay(Pokemon* myPokemon, Pokemon* enemyPokemon);
int displayInventory(Inventory myInv);
int displayMoves(Pokemon *pokemon);
int displayPokemon(Character* myChar);
void attack(Pokemon* myChar, Pokemon* myRival, int attackNum);

#endif