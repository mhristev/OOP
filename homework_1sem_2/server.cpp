#include "server.hpp"

void Server::add_torrent(Torrent &t) {
    for (int i = 0; i < users.size(); i++) {
        if (t.getUploader().compare(users[i])) {
            torrents.push_back(&t);
            return;
        }
    } 
    throw "This user is not in the server!";        
}

void Server::add_user(string name) {
    users.push_back(name);
}

vector<Torrent*> Server::search_by_title(string title) {
    vector<Torrent*> torrns;

    cout << "+Searching by title... "<< endl << endl;

    for (auto t : torrents) {
        if (t->getTitle().find(title) != string::npos) {
            torrns.push_back(t);
        }
    }

    if (torrns.empty()) {
        cout << "We didn't find anything in the torrents with that title!" << endl;
    }
    
    return torrns;
}

vector <GameTorrent*> Server::search_games_by_rating(char rating) {
    vector <GameTorrent*> games;
    int flag = 0;
    cout << "+Searching for games..." << endl;

    for (auto t : torrents) {
        GameTorrent *g = dynamic_cast<GameTorrent*>(t);
        if (g) {
            if (g->getRating() == rating) {
            
                games.push_back(g);
                flag = 1;
            }
        } 
    }

    if (games.empty())
        cout << "We didn't find this rating in the current torrents!" << endl;
    
    return games;
}

vector<FilmTorrent*> Server::search_by_director(string name) {
    cout << "+Searching director..." << endl;

    vector<FilmTorrent*> films;
    for (auto t : torrents) {
        FilmTorrent *f = dynamic_cast<FilmTorrent*>(t);
        if (f) {
            if (f->getDirector().compare(name) == 0) {
                films.push_back(f);
            }
        }
    }

    if (films.empty())
        cout << "We didn't find this director in the current torrents!" << endl;

    return films;
}

vector<ProgramTorrent*> Server::search_by_major(string major) {
    vector<ProgramTorrent*> programs;
    cout << "+Searching major..." << endl;
    
    for (auto t : torrents) {
        ProgramTorrent *p = dynamic_cast<ProgramTorrent*>(t);
        if (p) {
            if (p->getMajor().compare(major) == 0) {
                programs.push_back(p);
            }
        }
    }

    if (programs.empty())
        cout << "We didn't find this major in the current torrents!" << endl;

    return programs;
}

template<class T>
ostream& operator<<(ostream& out, vector <T*> torr) {
    for (auto i : torr) {
        out << i->toString();
    }
    return out;
}