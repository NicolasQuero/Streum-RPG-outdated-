#include <iostream>
#include <fstream>
#include <vector>

#include "GameMap.h"

using namespace std;


bool storeMap(const string mapPath, vector<string> &mapStrings) {
    string line;
    ifstream mapfile (mapPath);
    if (mapfile.is_open()) {
        while( getline( mapfile, line ) )
            mapStrings.push_back(line);
        mapfile.close();
        return true;
    }
    return false;
}

GameMap::GameMap() {
    storeMap("", mapStrings);
}
GameMap::GameMap(const string MAP_PATH) {
    storeMap(MAP_PATH, mapStrings);
}
GameMap::GameMap(const GameMap &gamemap) {
    mapStrings = gamemap.getMapStrings();
}

vector<string> GameMap::getMapStrings() const { return mapStrings; }
