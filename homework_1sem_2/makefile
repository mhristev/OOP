all: server

torrent.o: torrent.hpp torrent.cpp
filmTorrent.o: filmTorrent.hpp filmTorrent.cpp
gameTorrent.o: gameTorrent.hpp gameTorrent.cpp
programTorrent.o: programTorrent.hpp programTorrent.cpp
server.o: server.hpp server.cpp
main.o: main.cpp torrent.hpp filmTorrent.hpp gameTorrent.hpp programTorrent.hpp server.hpp

server: main.o server.o programTorrent.o gameTorrent.o filmTorrent.o torrent.o
	g++ main.o server.o programTorrent.o gameTorrent.o filmTorrent.o torrent.o -o server

clean:
	rm -f *.o server