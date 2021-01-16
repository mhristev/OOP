#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

class Torrent {
    string title;
    int size;
    string uploader;
    int times_downloaded;
public:
    Torrent(string title_, int size_, string uploader_, int times_downloaded_):
            title(title_), size(size_), uploader(uploader_), times_downloaded(times_downloaded_) 
    {
        if (title_.length() == 0 || uploader_.length() == 0)
            throw "Invalid atribut in torrent";
    }

    Torrent(const Torrent& torr): size(torr.size), title(torr.title), uploader(torr.uploader), times_downloaded(torr.times_downloaded) {}

    virtual string toString() {
        string str = "Title: " + title + ", Size: " + to_string(size) + ", Uploader: " + uploader + ", Downloaded: " + to_string(times_downloaded) + "\n";
        return str;  
    }

    string getTitle() {
        return title;
    }

};



class Game: public Torrent {
    string platform; //Windows, Linux, PS4
    char maturity_rating; // E-for everyone, M-over 15 yo, P - over 18 yo
public:
    Game(string title_, int size_, string uploader_, int times_downloaded_, string platform_, char maturity_rating_): Torrent(title_, size_, uploader_, times_downloaded_),
        platform(platform_), maturity_rating(maturity_rating_) { 
            if (platform.length() == 0)
                throw "Invalid platform!";
            if (maturity_rating_ != 'M' && maturity_rating_ != 'E' && maturity_rating_ != 'P')
                throw "Invalid maturity rating!";
        }

    Game(Game &game_): Torrent(game_), platform(game_.platform), maturity_rating(game_.maturity_rating) {} 

    string toString() {
        string str = Torrent::toString() + "Platform: " + platform + ", Rating: " + maturity_rating + "\n+-------------------------------------------------------+\n";
        return str;
    }

    char getRating() {
        return this->maturity_rating;
    }
    
};

class Film: public Torrent {
    string director;
    int length;
    string language;
public:
    Film(string title_, int size_, string uploader_, int times_downloaded_, string director_, int length_, string language_): Torrent(title_, size_, uploader_, times_downloaded_),
        director(director_), length(length_), language(language_) {
            if (director.length() == 0 || language.length() == 0)
                throw "Invalid user ot language!";
        }

    Film(Film &film_): Torrent(film_), director(film_.director), length(film_.length), language(film_.language) {}

    string toString() {
        string str = Torrent::toString() + "director: " + director + ", Length: " + to_string(length) + ", Language: " + language + "\n+-------------------------------------------------------+\n";
        return str;
    }

    string getDirector() {
        return director;
    }
};

class Program: public Torrent {
    string creator;
    string OS; // for which operation system is the program
    string version; // 3.11.5 major.minor.patch
public:
    Program(string title_, int size_, string uploader_, int times_downloaded_, string creator_, string OS_, string version_): Torrent(title_, size_, uploader_, times_downloaded_),
            creator(creator_), OS(OS_), version(version_) {
                if (creator.length() == 0 || OS.length() == 0 || version.length() == 0)
                    throw "Invalid input in program!";
                //TODO check version input
    }

    Program(Program &program_): Torrent(program_), creator(program_.creator), OS(program_.OS), version(program_.version) {}

    string toString() {
        string str = Torrent::toString() + "Creator: " + creator + ", OS: " + OS + ", Version: " + version + "\n+-------------------------------------------------------+\n";
        return str;
    }
  
};


class Server {
    vector <Torrent*> torrents;
    vector <string> users;
public:

    void add_torrent(Torrent &t) {
        torrents.push_back(&t);
    }

    void add_user(string name) {
        users.push_back(name);
    }

    void search_by_title(string title) {
        int flag = 0;
        cout << "+Searching by title... "<< endl << endl;
        for (auto t : torrents) {
            if (t->getTitle().find(title) != string::npos) {
                cout << t->toString() << endl;
                flag++;
            }
        }
        if (flag == 0) {
            cout << "We didn't find anything in the torrents with that title!" << endl;
        }

        
    }

    vector <Game*> search_games_by_rating(char rating) {
        vector <Game*> games;
        int flag = 0;
       
        for (auto t : torrents) {
            Game *g = dynamic_cast<Game*>(t);
            if (g) {
                if (g->getRating() == rating) {
                
                    games.push_back(g);
                    flag = 1;
                }
            } 
        }

        if (flag == 0)
            cout << "We didn't find this rating in the current torrents!" << endl;
        
        return games;

    }

    vector<Film*> search_by_director(string name) {
        cout << "+Searching director..." << endl;
        vector<Film*> films;
        for (auto t : torrents) {
            Film *f = dynamic_cast<Film*>(t);
            if (f) {
                if (f->getDirector().compare(name) == 0) {
                    films.push_back(f);
                }
            }
        }
        return films;
    }
/*
    void search_by_major(string major) {
        cout << "+Searching major..." << endl;
        for (auto i : torrents) {
            if (i->getMajor().compare(major) == 0) {
                cout << i->toString() << endl;
            }
        }
    }
*/

};




int main() {
    try {
        Torrent tor("empty", 1, "empty", 1);
        Game game("swag", 10, "az", 10, "ne", 'M');
        Server serv;
        Film film("film", 12, "film", 10, "az", 100, "bg");
        Program prog("program", 10, "program", 1, "creator", "winwos", "as");
       // serv.add_torrent(prog);
        serv.add_torrent(game);
        serv.add_torrent(tor);
        serv.add_torrent(film);
        //serv.search_by_title("ag");
        vector <Game*> torr = serv.search_games_by_rating('M');
        for (auto t : torr) {
            cout << t->toString() << endl;
        }
        //serv.search_by_director("az");
        //serv.search_by_major("23");

        
        
    } catch(const char* error) {
        cout << error << endl;
    }

}