#include "filmTorrent.hpp"

FilmTorrent::FilmTorrent(string title_, int size_, string uploader_, int times_downloaded_, string director_, int length_, string language_): Torrent(title_, size_, uploader_, times_downloaded_), director(director_), length(length_), language(language_) {
    if (director.length() == 0 || language.length() == 0)
        throw "Invalid director ot language!";
}

FilmTorrent::FilmTorrent(FilmTorrent &film_): Torrent(film_), director(film_.director), length(film_.length), language(film_.language) {}

string FilmTorrent::toString() {
    string str = Torrent::toString() + "director: " + director + ", Length: " + to_string(length) + ", Language: " + language + "\n+-------------------------------------------------------+";
    return str;
}

string FilmTorrent::getDirector() {
    return director;
}
