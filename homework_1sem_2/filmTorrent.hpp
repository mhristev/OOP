#ifndef FILM_TORRENT_HPP
#define FILM_TORRENT_HPP

#include "torrent.hpp"
#include <string>
using namespace std;

class FilmTorrent: public Torrent {
    string director;
    int length;
    string language;
public:
    FilmTorrent(string title_, int size_, string uploader_, int times_downloaded_, string director_, int length_, string language_);
    FilmTorrent(FilmTorrent &film_);

    string toString();
    string getDirector();
};


#endif