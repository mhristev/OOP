#include <iostream>
#include <string>
#include <vector>
#include <string.h>

#include "torrent.hpp"
#include "filmTorrent.hpp"
#include "gameTorrent.hpp"
#include "programTorrent.hpp"
#include "server.hpp"

using namespace std;



int main() {
    try {
        Torrent tor("empty", 1, "empty", 1);
        GameTorrent game("swag", 10, "az", 10, "ne", 'M');
        Server serv;
        FilmTorrent film("film", 12, "film", 10, "az", 100, "bg");
        ProgramTorrent prog("program", 10, "program", 1, "creator", "winwos", "1.23.7");
        serv.add_torrent(prog);
        serv.add_torrent(game);
        serv.add_torrent(tor);
        serv.add_torrent(film);
        vector <GameTorrent*> torr = serv.search_games_by_rating('M');
        //cout << torr << endl;
        //serv.search_by_director("az");
        vector <ProgramTorrent*> progr = serv.search_by_major("1");
        //cout << progr << endl;

        
        
    } catch(const char* error) {
        cout << error << endl;
    }

}