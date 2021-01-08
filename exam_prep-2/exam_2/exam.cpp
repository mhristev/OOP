#include <iostream>
#include <vector>

using namespace std;

class Colection;

class Song{
    string artist;
    string name;
    string genre;
    static int count;
public:
    Song(string artist, string name, string genre){
        this->artist = artist;
        this->name = name;
        this->genre = genre;
        this->count += 1;
    }
    static int get_count(){
        return count;
    }

    string getGenge(){
        return genre;
    }

    bool operator==(const Song& second){
        if(this->name == second.name && this->artist == second.artist){
            return true;
        }else{
            return false;
        }

    }

    friend Colection;
    friend ostream& operator<<(ostream& out, const Colection& col);

};

class Colection{
    string name;
    vector <const Song*> songs;
public:
    Colection(string name){
        this->name = name;
    }

    void add(const Song& song){
        songs.push_back(&song);
    }

    const Song* getByIndex(int index)const{
        return songs[index];
    }

    void print(){
        cout << "Colection " << this->name << endl;
        for(int i = 0; i < songs.size(); i++){
            cout << "Song " << i << ", genre: " << songs[i]->genre << " artist: " << songs[i]->artist << endl;
        }
    }

    friend ostream& operator<<(ostream& out, const Colection& col);



};

ostream& operator<<(ostream& out, const Colection& col) {
    out << "Colection: " << col.name << endl;
    for(int i = 0; i < col.songs.size() ; i++){
        cout << "Song " << i+1 << ", genre: " << col.songs[i]->genre << ", artist: " << col.songs[i]->artist << ", name: " << col.songs[i]->name << endl;
    }
    return out;
}


class Library{
    vector <Song> array_songs;
public:
    Library(){}

    Song& getsong1(){
        return array_songs[0];
    }

    const Song& add(string artist, string name, string genre){
        Song new_song(artist, name, genre);
        array_songs.push_back(new_song);
        return array_songs[array_songs.size()]; 
    }

    Colection* getByGenre(string name, string genre){
        Colection* by_genre = new Colection(name);
        for(int i = 0; i < array_songs.size(); i++){
            if(array_songs[i].getGenge() == genre){
                by_genre->add(array_songs[i]);
            }
        }
        return by_genre; 
    }

    Colection* getByIndexRange(string name, int min, int max){
        Colection* my_colection = new Colection(name);
        if(max > array_songs.size()){
            throw("Max index is outside the array");
        }
        for(int i = min; i <= max; i++){
           my_colection->add(array_songs[i]);
        }
        return my_colection;
    }

};



int Song:: count = 0;



int main(){
try{
    Song my_song("Slipknot", "Duality", "alternative metal");

    Library my_library;
    my_library.add("Arctic Monkeys", "Do I Wanna Know", "alternative rock");
    my_library.add("Korn", "All in the family", "alternative rock");
    my_library.add("Slipknot", "Duality", "alternative metal");


    cout << Song::get_count() << endl;

    Colection* my_col1 = my_library.getByGenre("al rock", "alternative rock");
    cout << *my_col1; 

    Colection *my_col2 = my_library.getByIndexRange("0-2", 0, 2); //all songs in the library
    cout << *my_col2;

    if(my_song == my_library.getsong1()){
        cout << "They are the same!" << endl;
    }else{
        cout << "Not the same song!" << endl;
    }


    delete my_col1;
    delete my_col2;
}catch(const char* error){
    cout << error << endl;
}

}
