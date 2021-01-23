#ifndef SERVER_HPP
#define SERVER_HPP

#include "torrent.hpp"
#include "gameTorrent.hpp"
#include "programTorrent.hpp"
#include "filmTorrent.hpp"
#include <vector>
#include <iostream>
using namespace std;

class Server {
    vector <Torrent*> torrents;
    vector <string> users;
public:
    Server& add_torrent(Torrent &t);
    void add_user(string name);

    vector<Torrent*> search_by_title(string title);
    vector<GameTorrent*> search_games_by_rating(char rating);
    vector<FilmTorrent*> search_by_director(string name);
    vector<ProgramTorrent*> search_by_major(string major);
    void print_torrents();
    Server& sort_by_alphabetical_order();
    Server& sort_by_size();
    Server& sort_by_times_downloaded();
};

#endif