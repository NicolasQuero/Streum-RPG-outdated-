#ifndef GAMEMAP_H_INCLUDED
#define GAMEMAP_H_INCLUDED

#include <vector>

using namespace std;

class GameMap {
protected:
    vector<string> mapStrings;
public:
    GameMap();
    GameMap(const string MAP_PATH);
    GameMap(const GameMap& gamemap);
    vector<string> getMapStrings() const;

};



#endif // GAMEMAP_H_INCLUDED
