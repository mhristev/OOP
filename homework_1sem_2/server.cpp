#include "server.hpp"

Server& Server::add_torrent(Torrent &t) {
    for (int i = 0; i < users.size(); i++) {
        if (t.getUploader().compare(users[i]) == 0) {
            torrents.push_back(&t);
            return *this;
        }
    } 
    throw "This user is not in the server!";      
}

void Server::add_user(string name) {
    users.push_back(name);
}

vector<Torrent*> Server::search_by_title(string title) {
    vector<Torrent*> torrns;

    cout << "+Searching by title... ";

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
    cout << "+Searching for games...";

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
    cout << "+Searching director...";

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
    cout << "+Searching major...";
    
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


struct nameCompare {
    bool operator()(Torrent& a, Torrent& b) {
        return a.getTitle() < b.getTitle();
    }
};

Server& Server::sort_by_alphabetical_order() {
    for (int i = 0; i < torrents.size(); i++) {
        for (int k = i+1; k < torrents.size(); k++){
            // check if we have two non-capital characters
            if(int(torrents[i]->getTitle()[0]) >= int('a') && int(torrents[k]->getTitle()[0]) >= int('a')){
                if (torrents[i]->getTitle()[0] > torrents[k]->getTitle()[0]) {
                    swap(torrents[i], torrents[k]);
                }
            // check if we have two capital characters
            } else if (int(torrents[i]->getTitle()[0]) < int('a') && int(torrents[i]->getTitle()[0]) >= int('A') && int(torrents[k]->getTitle()[0]) < int('a') && int(torrents[k]->getTitle()[0]) >= int('A')) {
                if (torrents[i]->getTitle()[0] > torrents[k]->getTitle()[0]) {
                    swap(torrents[i], torrents[k]);
                }
            // check if first char is capital and the second is non-capital
            } else if (int(torrents[i]->getTitle()[0]) < int('a') && int(torrents[i]->getTitle()[0]) >= int('A') && int(torrents[k]->getTitle()[0]) >= int('a')){
                if (int(torrents[i]->getTitle()[0] + (int('a') - int('A'))) > int(torrents[k]->getTitle()[0])) {
                    swap(torrents[i], torrents[k]);
                }
            // check if first char is non-capital and the second is capital
            } else if (int(torrents[i]->getTitle()[0]) >= int('a') && int(torrents[k]->getTitle()[0]) < int('a') && int(torrents[k]->getTitle()[0]) >= int('A')) { 
                if (int(torrents[i]->getTitle()[0] - (int('a') - int('A'))) > int(torrents[k]->getTitle()[0])) {
                    swap(torrents[i], torrents[k]);
                }
            }
        }
    }
    return *this;
}

Server& Server::sort_by_size() {
    for (int i = 0; i < torrents.size(); i++) {
        for (int k = i+1; k < torrents.size(); k++) {
            if (torrents[i]->getSize() < torrents[k]->getSize()) {
                swap(torrents[i], torrents[k]);
            }
        }
    }
    return *this;
}

Server& Server::sort_by_times_downloaded() {
    for (int i = 0; i < torrents.size(); i++) {
        for (int k = i+1; k < torrents.size(); k++) {
            if (torrents[i]->getTimesDownloaded() < torrents[k]->getTimesDownloaded()) {
                swap(torrents[i], torrents[k]);
            }
        }
    }
    return *this;
}

void Server::print_torrents() {
    cout << endl;
    cout << "|------------------------------|" << endl;
    cout << "|      Printing torrents:      |" << endl;
    cout << "|------------------------------|" << endl;
    for (auto i : torrents) {
        cout << i->toString() << endl;
    }
}



