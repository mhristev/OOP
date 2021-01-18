#ifndef PROGRAM_TORRENT_HPP
#define PROGRAM_TORRENT_HPP

#include "torrent.hpp"
#include <string.h>
#include <string>
using namespace std;

class ProgramTorrent: public Torrent {
    string creator;
    string OS; // for which operation system is the program
    string version; // 3.11.5 major.minor.patch
public:
    ProgramTorrent(string title_, int size_, string uploader_, int times_downloaded_, string creator_, string OS_, string version_);
    ProgramTorrent(ProgramTorrent &program_);

    string toString();
    string getMajor();
};

#endif