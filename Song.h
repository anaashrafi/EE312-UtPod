// Ana Ashrafi and Jessica Cruz (aa76288, jmc8624)
// Section 16225

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H

#include <string>

using namespace std;

class Song {

    private:
        string title;
        string artist;
        int size;

        static const int MAX_MEMORY = 512;

    public:
        Song();
        Song(string artist, string title, int size);

        string getTitle() const;
        void setTitle(string t);

        string getArtist() const;
        void setArtist(string a);

        int getSize() const;
        void setSize(int s);

        bool operator >(Song const &rhs);
        bool operator <(Song const &rhs);
        bool operator ==(Song const &rhs);

};


#endif //UTPOD_SONG_H
