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
        Torrent torr("TestTorrent", 300, "Tyler", 1);

        GameTorrent LastOfUs("The Last Of Us", 10000, "Tyler", 34, "Windows", 'M');
        GameTorrent AgeOfMythology("Age of Mythology", 4000, "Creator", 20, "Windows", 'E');
        
        FilmTorrent StarWars("Star Wars: The Last Jedi", 1200, "Tyler", 17, "Rian Johnson", 152, "ENGL");
        FilmTorrent TheSocialDilemma("The Social Dilemma", 700, "Tyler", 6, "Jeff Orlowski", 94, "ENGL");

        ProgramTorrent adobe("Adobe", 800, "Creator", 11, "Adobe", "Windows", "1.23.1");
        ProgramTorrent adobePhotoshop("Adobe Photoshop", 2000, "Creator", 5, "Adobe", "Windows", "1.4.1");

        Server server;
        server.add_user("Tyler");
        server.add_user("Creator");

        server.add_torrent(torr)
              .add_torrent(LastOfUs)
              .add_torrent(AgeOfMythology)
              .add_torrent(StarWars)
              .add_torrent(TheSocialDilemma)
              .add_torrent(adobe)
              .add_torrent(adobePhotoshop);

        
        vector <GameTorrent*> games = server.search_games_by_rating('M');
        cout << games << endl;
        vector<FilmTorrent*> films = server.search_by_director("Rian Johnson");
        cout << films << endl;
        vector <ProgramTorrent*> progr = server.search_by_major("1");
        cout << progr << endl;

        server.sort_by_alphabetical_order()
              .print_torrents();
        
        server.sort_by_size()
              .print_torrents();

        server.sort_by_times_downloaded()
              .print_torrents();
        
        
    } catch(const char* error) {
        cout << error << endl;
    }

}