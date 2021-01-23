#include "gameTorrent.hpp"


GameTorrent::GameTorrent (string title_, int size_, string uploader_, int times_downloaded_, string platform_, char maturity_rating_): Torrent::Torrent(title_, size_, uploader_, times_downloaded_), platform(platform_), maturity_rating(maturity_rating_) { 
    if (platform.length() == 0)
        throw "Invalid platform!";
    if (maturity_rating_ != 'M' && maturity_rating_ != 'E' && maturity_rating_ != 'P')
        throw "Invalid maturity rating!";
}

GameTorrent::GameTorrent(GameTorrent &game_): Torrent::Torrent(game_), platform(game_.platform), maturity_rating(game_.maturity_rating) {} 

string GameTorrent::toString() {
    string str = Torrent::toString() + ", Platform: " + platform + ", Rating: " + maturity_rating;
    return str;
}

char GameTorrent::getRating() {
    return this->maturity_rating;
}

ostream& operator<<(ostream& out, vector <GameTorrent*> games) {
    if (games.empty()) {
        return out;
    }
    cout << endl;
    cout << "|------------------------------|" << endl;
    cout << "|      Printing games:         |" << endl;
    cout << "|------------------------------|" << endl;
    for (auto i : games) {
        out << i->toString();
    }
    cout << endl;
    return out;
}
    