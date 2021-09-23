#ifndef DUNGEON_H
#define DUNGEON_H

#include "Player.h"

class Dungeon
{
    public:
        Player player;
        Room rooms[4];
        Dungeon(Player);
        int runDungeon();
        void enterRoom(Room*);
        void handleEmptyRoom(Room*);
        void handleRoomWithCheat(Room*);
        void handleRoomWithEnemy(Room*);
        void handleLootActions(Room*);
        void handleFightActions(Room*);
        void handleMovementActions(Room*);
        void printActions(int, string[]);
        int performEndGameLogic();
};

#endif