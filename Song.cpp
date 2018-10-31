// Ana Ashrafi and Jessica Cruz (aa76288, jmc8624)
// Section 16225

#include "Song.h"
#include <iostream>

Song::Song()
{
    artist = "";
    title = "";
    size = 0;
}

Song::Song(string _artist, string _title, int _size)
{
    artist = _artist;
    title = _title;
    size = _size;
}

string Song::getTitle() const
{
    return title;
}

void Song::setTitle(string t)
{
    title = t;
}

string Song::getArtist() const
{
    return artist;
}

void Song::setArtist(string a)
{
    artist = a;
}

int Song::getSize() const
{
    return size;
}

void Song::setSize(int s)
{
    size = s;
}


bool Song::operator >(Song const &rhs)
{
    if (artist > rhs.artist)
        return true;
    else if (artist < rhs.artist)
        return false;
    else
    {
        if (title > rhs.title)
            return true;
        else if (title < rhs.title)
            return false;
        else
        {
            if (size > rhs.size)
                return true;
            else
                return false;
        }
    }
}

bool Song::operator <(Song const &rhs)
{

    if (artist < rhs.artist)
        return true;
    else if (artist > rhs.artist)
        return false;
    else
    {
        if (title < rhs.title)
            return true;
        else if (title > rhs.title)
            return false;
        else
        {
            if (size < rhs.size)
                return true;
            else
                return false;
        }
    }
}

bool Song::operator ==(Song const &rhs)
{
    return (title == rhs.title && artist == rhs.artist && size == rhs.size);

}

