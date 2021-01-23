#include "torrent.hpp"


Torrent::Torrent(string title_, int size_, string uploader_, int times_downloaded_): title(title_), size(size_), uploader(uploader_), times_downloaded(times_downloaded_) {
        if (title_.length() == 0 || uploader_.length() == 0)
            throw "Invalid atribut in torrent";
}

Torrent::Torrent(const Torrent& torr): size(torr.size), title(torr.title), uploader(torr.uploader), times_downloaded(torr.times_downloaded) {}

string Torrent::toString() {
        string str = "Title: " + title + ", Size: " + to_string(size) + ", Uploader: " + uploader + ", Downloaded times: " + to_string(times_downloaded);
        return str;  
}

string Torrent::getTitle() {
    return title;
}

string Torrent::getUploader() {
    return uploader;
}

int Torrent::getSize() {
    return size;
}
int Torrent::getTimesDownloaded() {
    return times_downloaded;
}

