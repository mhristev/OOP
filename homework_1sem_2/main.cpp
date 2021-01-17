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

    string getUploader() {
        return uploader;
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
        string str = Torrent::toString() + "Platform: " + platform + ", Rating: " + maturity_rating + "\n+-------------------------------------------------------+";
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
        string str = Torrent::toString() + "director: " + director + ", Length: " + to_string(length) + ", Language: " + language + "\n+-------------------------------------------------------+";
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
                int p = 0;
                int flag = 0;

                for (int i = 0; i < version.size(); i++) {
                    if (isalpha(version[i])){
                        flag = 1;
                    } else if (!isdigit(version[i])){
                        p++;
                    }
                }

                if (p != 2 || flag != 0) {
                    throw "Non valid version!";
                }
    }

    Program(Program &program_): Torrent(program_), creator(program_.creator), OS(program_.OS), version(program_.version) {}

    string toString() {
        string str = Torrent::toString() + "Creator: " + creator + ", OS: " + OS + ", Version: " + version + "\n+-------------------------------------------------------+";
        return str;
    }

    string getMajor() {
        char *vers = strdup(version.c_str());
        char *token;
        token = strtok(vers, ".");

        return token;
    }
  
};


class Server {
    vector <Torrent*> torrents;
    vector <string> users;
public:

    void add_torrent(Torrent &t) {
        for (int i = 0; i < users.size(); i++) {
            if (t.getUploader().compare(users[i])) {
                torrents.push_back(&t);
                return;
            }
        } 
        torrents.push_back(&t);
        //throw "This user is not in the server!";        
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
        cout << "+Searching for games..." << endl;

        for (auto t : torrents) {
            Game *g = dynamic_cast<Game*>(t);
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

        if (films.empty())
            cout << "We didn't find this director in the current torrents!" << endl;

        return films;
    }

   vector<Program*> search_by_major(string major) {
        vector<Program*> programs;
        cout << "+Searching major..." << endl;
        

        for (auto t : torrents) {
            Program *p = dynamic_cast<Program*>(t);
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

};
template<class T>
ostream& operator<<(ostream& out, vector <T*> torr) {
    for (auto i : torr) {
        out << i->toString();
    }
    return out;
}


int main() {
    try {
        Torrent tor("empty", 1, "empty", 1);
        Game game("swag", 10, "az", 10, "ne", 'M');
        Server serv;
        Film film("film", 12, "film", 10, "az", 100, "bg");
        Program prog("program", 10, "program", 1, "creator", "winwos", "1.23.7");
        serv.add_torrent(prog);
        serv.add_torrent(game);
        serv.add_torrent(tor);
        serv.add_torrent(film);
        vector <Game*> torr = serv.search_games_by_rating('M');
        //cout << torr << endl;
        //serv.search_by_director("az");
        vector <Program*> progr = serv.search_by_major("1");
        //cout << progr << endl;

        
        
    } catch(const char* error) {
        cout << error << endl;
    }

}