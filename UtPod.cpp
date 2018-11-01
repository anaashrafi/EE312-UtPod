// Ana Ashrafi and Jessica Cruz (aa76288, jmc8624)
// Section 16225

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "UtPod.h"
#include "Song.h"

UtPod::UtPod()
{
    memSize = MAX_MEMORY;
    songs = NULL;
}

UtPod::UtPod(int size)
{
    if (size > MAX_MEMORY || size <= 0)
        memSize = MAX_MEMORY;
    else
        memSize = size;

    songs = NULL;
}


int UtPod::addSong(Song const &s)
{
    if (getRemainingMemory() <= 0 || s.getSize() > MAX_MEMORY || s.getSize() <= 0 || s.getSize() > getRemainingMemory())
        return NO_MEMORY;
    else
    {
        SongNode *temp = new SongNode;
        temp->s = s;    // putting song in temp node
        temp->next = songs; // add temp to the front of the linked list
        songs = temp;   // new head is temp
        return SUCCESS;
    }
}

int UtPod::removeSong(Song const &s)
{
    SongNode *traverse = songs;
    SongNode *trail = NULL;

    while (traverse != NULL)
    {

        if ((traverse->s) == s) // if the song exists in the linked list
        {
            if (trail == NULL)  // if it's the first node in the list
            {
                    songs = songs->next;    // move head to the next node
                    delete traverse;    // delete previous node
                    return SUCCESS;
            }

            else
            {
                trail->next = traverse->next;   // linking the list properly before removing
                delete traverse;    // remove the node
                return SUCCESS;
            }
        }
        else
        {
            trail = traverse;
            traverse = traverse->next;  // go to the next node if song not found yet
        }
    }

    return NOT_FOUND;
}

void UtPod::shuffle() {
    int numSongs = getNumSongs();

    if (numSongs < 2)
    {
        return;
    }


    unsigned int currentTime = (unsigned)time(0);
    //cout << "current time " << currentTime << endl;

    srand(currentTime);  //seed the random number generator


    for (int i = 0; i < (2 * numSongs); i++) {
        SongNode *p1 = songs;
        SongNode *p2 = songs;
        long song1 = (rand() % numSongs);   // generate random placement within the list
        long song2 = (rand() % numSongs);   // generate random placement within the list

        // move to the indicated location within the list
        for (int j = 0; j < song1; j++) {
            p1 = p1->next;
        }

        // move to the indicated location within the list
        for (int k = 0; k < song2; k++) {
            p2 = p2->next;
        }

        swap(p1, p2);   // swap the nodes at the random locations
    }
}

void UtPod::showSongList()
{
    SongNode *traverse = songs;
    while (traverse != NULL)
    {
        string title = (traverse->s).getTitle();
        string artist = (traverse->s).getArtist();
        int size = (traverse->s).getSize();
        cout << title << ", " << artist << ", " << size << " MB" << endl;
        traverse = traverse->next;
    }
}


void UtPod::sortSongList()
{
    if (getNumSongs() < 2)
        return;

    SongNode *start = songs;
    SongNode *traverse;
    SongNode *min;

    while (start != NULL)
    {
        min = start;    // use the first node as the minumum at the beginning
        traverse = start->next; // next node

        while (traverse != NULL)
        {
            // if the next node is less than min, then this node becomes the new min
            if (traverse->s < min->s)
            {
                min = traverse;
            }

            // go through the whole list to check
            traverse = traverse->next;
        }

        //swap them
        swap(start, min);

        // compare next node in list to the rest
        start = start->next;
    }
}

void UtPod::clearMemory()
{
    while (songs != NULL)
    {
        SongNode *traverse = songs;
        songs = songs->next;
        delete traverse;
    }
}

int UtPod::getRemainingMemory()
{
    int totalMemory = 0;

    SongNode *traverse = songs;
    while (traverse != NULL)
    {
        totalMemory = totalMemory + (traverse->s).getSize();
        traverse = traverse->next;
    }

    int remainingMemory = memSize - totalMemory;
    return remainingMemory;

}

int UtPod::getNumSongs()
{
    int numSongs = 0;
    SongNode *traverse = songs;
    while (traverse != NULL) {
        numSongs = numSongs + 1;
        traverse = traverse->next;
    }

    return numSongs;
}

UtPod::~UtPod()
{
    clearMemory();

}
