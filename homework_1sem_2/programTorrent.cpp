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
            p++;
        }
    }

    if (p != 2 || flag != 0) {
        throw "Non valid version!";
    }
}

ProgramTorrent::ProgramTorrent(ProgramTorrent &program_): Torrent(program_), creator(program_.creator), OS(program_.OS), version(program_.version) {}

string ProgramTorrent::toString() {
    string str = Torrent::toString() + "Creator: " + creator + ", OS: " + OS + ", Version: " + version + "\n+-------------------------------------------------------+";
    return str;
}

string ProgramTorrent::getMajor() {
    char *vers = strdup(version.c_str());
    char *token;
    token = strtok(vers, ".");

    return token;
}
  