#ifndef FILM_TORRENT_HPP
#define FILM_TORRENT_HPP

#include "torrent.hpp"
#include <string>
#include <vector>
using namespace std;

class FilmTorrent: public Torrent {
    string director;
    int duration;
    string language;
public:
    FilmTorrent(string title_, int size_, string uploader_, int times_downloaded_, string director_, int duration_, string language_);
    FilmTorrent(FilmTorrent &film_);

    string toString();
    string getDirector();
    friend ostream& operator<<(ostream& out, vector <FilmTorrent*> films);
};


#endif