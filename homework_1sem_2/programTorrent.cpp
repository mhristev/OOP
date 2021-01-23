#include "programTorrent.hpp"


ProgramTorrent::ProgramTorrent(string title_, int size_, string uploader_, int times_downloaded_, string creator_, string OS_, string version_): Torrent(title_, size_, uploader_, times_downloaded_), creator(creator_), OS(OS_), version(version_) {

    if (creator.length() == 0 || OS.length() == 0 || version.length() == 0)
        throw "Invalid input in program!";
    int p = 0;
    int flag = 0;

    for (int i = 0; i < version.size(); i++) {
        if (isalpha(version[i])){
            flag = 1;
        } else if (!isdigit(version[i])){
            if (version[i] == '.')
                p++;
        }
    }

    if (p != 2 || flag != 0) {
        throw "Non valid version!";
    }
}

ProgramTorrent::ProgramTorrent(ProgramTorrent &program_): Torrent(program_), creator(program_.creator), OS(program_.OS), version(program_.version) {}

string ProgramTorrent::toString() {
    string str = Torrent::toString() + ", Creator: " + creator + ", OS: " + OS + ", Version: " + version;
    return str;
}

string ProgramTorrent::getMajor() {
    char *vers = strdup(version.c_str());
    char *token;
    token = strtok(vers, ".");

    return token;
}
  
ostream& operator<<(ostream& out, vector <ProgramTorrent*> programs) {
    if (programs.empty()) {
        return out;
    }
    cout << endl;
    cout << "|------------------------------|" << endl;
    cout << "|      Printing programs:      |" << endl;
    cout << "|------------------------------|" << endl;
    for (auto i : programs) {
        out << i->toString() << endl;;
    }
    cout << endl;
    return out;
}
