#ifndef GAME_TORRENT_HPP
#define GAME_TORRENT_HPP

#include "torrent.hpp"
#include <string>
#include <vector>
using namespace std;

class GameTorrent: public Torrent {
    string platform; //Windows, Linux, PS4
    char maturity_rating; // E-for everyone, M-over 15 yo, P - over 18 yo
public:
    GameTorrent (string title_, int size_, string uploader_, int times_downloaded_, string platform_, char maturity_rating_);
    GameTorrent(GameTorrent &game_);

    string toString();
    char getRating();
    friend ostream& operator<<(ostream& out, vector <GameTorrent*> games);
};

#endif