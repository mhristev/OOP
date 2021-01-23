#include "filmTorrent.hpp"

FilmTorrent::FilmTorrent(string title_, int size_, string uploader_, int times_downloaded_, string director_, int duration_, string language_): Torrent(title_, size_, uploader_, times_downloaded_), director(director_), duration(duration_), language(language_) {
    if (director.length() == 0 || language.length() == 0)
        throw "Invalid director ot language!";
}

FilmTorrent::FilmTorrent(FilmTorrent &film_): Torrent(film_), director(film_.director), duration(film_.duration), language(film_.language) {}

string FilmTorrent::toString() {
    string str = Torrent::toString() + ", Director: " + director + ", Duration: " + to_string(duration) + ", Language: " + language;
    return str;
}

string FilmTorrent::getDirector() {
    return director;
}

ostream& operator<<(ostream& out, vector <FilmTorrent*> films) {
    if (films.empty()) {
        return out;
    }
    cout << endl;
    cout << "|------------------------------|" << endl;
    cout << "|      Printing films:         |" << endl;
    cout << "|------------------------------|" << endl;
    for (auto i : films) {
        out << i->toString();
    }
    cout << endl;
    return out;
}
