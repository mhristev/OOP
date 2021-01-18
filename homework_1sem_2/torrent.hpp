#ifndef TORRENT_HPP
#define TORRENT_HPP

#include <string>
using namespace std;

class Torrent {
    string title;
    int size;
    string uploader;
    int times_downloaded;
public:
    Torrent(string title_, int size_, string uploader_, int times_downloaded_);

    Torrent(const Torrent& torr);

    virtual string toString();

    string getTitle();

    string getUploader();

};

#endif