#ifndef TORRENT_HPP
#define TORRENT_HPP

#include <string>
#include <vector>
#include <iostream>
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
    int getTimesDownloaded();
    string getTitle();
    int getSize();
    string getUploader();

};

#endif