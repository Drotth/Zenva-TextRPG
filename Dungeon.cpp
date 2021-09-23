#include "Dungeon.h"
#include <iostream>

using namespace std;

Dungeon::Dungeon(Player p)
{
    player = p;
}

int Dungeon::runDungeon()
{
    cout << "Welcome to the dungeon! Inside you will find treasure but also enemies. Enter at your peril.\n";

    player.currentRoom = &rooms[0];
    player.previousRoom = &rooms[0];

    while (true)
    {
        enterRoom(player.currentRoom);
    }
}

void Dungeon::enterRoom(Room *room)
{
    if (room->enemies.size() != 0)
    {
        handleRoomWithEnemy(room);
    }
    else if (room->items.size() != 0)
    {
        handleRoomWithChest(room);
    }
    else
    {
        handleEmptyRoom(room);
    }
}

void Dungeon::handleEmptyRoom(Room *room)
{
    cout << "You enter the room but it is empty.\n";
    string actions[] = {"a. Move to another room"};
    while (true)
    {
        printActions(1, actions);
        string input;
        cin >> input;
        if (input == "a")
        {
            return;
        }
        else
        {
            cout << "Incorrect choice.\n";
        }
    }
}

void Dungeon::handleRoomWithChest(Room * room)
{
    cout << "You enter the room and see a large chest in the middle.\n";
    string actions[] = {
        "a. Loot the chest",
        "b. Move to another room"};

    while (true)
    {
        printActions(2, actions);
        string input;
        cin >> input;
        if (input == "a")
        {
            handleLootActions(room);
            return;
        }
        else if (input == "b")
        {
            return;
        }
        {
            cout << "Incorrect choice.\n";
        }
    }
}

void Dungeon::handleRoomWithEnemy(Room * room)
{
}

void Dungeon::handleLootActions(Room * room)
{
    Item item = room->items.front();
    int size = room->items.size();
    player.lootRoom(room);
    room->clearLoot();
    for (int i = 0; i < size; i++){
        cout << "You open the chest and find a " << item.name << ".\n";
        cout << "Your health is now" << player.currentHealth 
        << ", your attack is now " << player.attack 
        << ", and your defence is now " << player.defence << ".\n";
    }
}

void Dungeon::handleFightActions(Room * room)
{
}

void Dungeon::handleMovementActions(Room * room)
{
}

void Dungeon::printActions(int numActions, string actions[])
{
    cout << "Choose an action:\n";
    for (int i = 0; i < numActions; i++)
    {
        cout << actions[i] << "\n";
    }
}

int Dungeon::performEndGameLogic()
{
}