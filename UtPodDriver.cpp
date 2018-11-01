// Ana Ashrafi and Jessica Cruz (aa76288, jmc8624)
// Section 16225

#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

void printOutcome(Song s, int result)
{
    cout << "Adding " << s.getTitle() << "...";
    string outcome;
    if (result == 0)
        outcome = "Successful!";
    else
        outcome = "Unsuccessful.";
    cout << outcome << endl;
}

void printRemoving(Song s, int result)
{
    cout << "Removing " << s.getTitle() << "...";
    string outcome;
    if (result == 0)
        outcome = "Successful!";
    else
        outcome = "Unsuccessful.";
    cout << outcome << endl;
}

int main(int argc, char *argv[])
{
//--------------------SAMI'S UTPOD----------------------
    // create UtPod with MAX_MEMORY
    UtPod Sami;
    cout << "Initial memory in Sami's UtPod = " << Sami.getRemainingMemory() << " MB" << endl << endl;

    Song s1("Pharrell", "Happy", 20);
    int result = Sami.addSong(s1);
    printOutcome(s1, result);

    Song s2("B.o.B", "So Good", 27);
    result = Sami.addSong(s2);
    printOutcome(s2, result);

    Song s3;
    s3.setArtist("Bastille");
    s3.setTitle("Happier");
    s3.setSize(2);
    result = Sami.addSong(s3);
    printOutcome(s3, result);

    Song s4("Ariana Grande", "God is a woman", 12);
    result = Sami.addSong(s4);
    printOutcome(s4, result);

    Song s5("Travis Scott", "STARGAZING", 100);
    result = Sami.addSong(s5);
    printOutcome(s5, result);

    Song s6("DNCE", "Toothbrush", 50);
    result = Sami.addSong(s6);
    printOutcome(s6, result);

    Song s7("Coldplay", "Yellow", 50);
    result = Sami.addSong(s7);
    printOutcome(s7, result);

    Song s8("Cardi B", "I Like It", 100);
    result = Sami.addSong(s8);
    printOutcome(s8, result);

    Song s9("Travis Scott", "SICKO MODE", 78);
    result = Sami.addSong(s9);
    printOutcome(s9, result);

    Song s10("Travis Scott", "SICKO MODE", 78);
    result = Sami.addSong(s10);
    printOutcome(s10, result);

    cout << Sami.getRemainingMemory() << " MB remaining." << endl << endl;

    // sort Sami's songs
    Sami.sortSongList();

    // show Sami's songs
    cout << "Sorted Playlist: " << endl;
    Sami.showSongList();
    cout << endl;

    // shuffle playlist
    Sami.shuffle();
    cout << "Shuffled Playlist: " << endl;
    Sami.showSongList();
    cout << endl;

    //remove songs
    result = Sami.removeSong(s1);
    printRemoving(s1, result);

    result = Sami.removeSong(s7);
    printRemoving(s7, result);

    result = Sami.removeSong(s4);
    printRemoving(s4, result);

    cout << Sami.getRemainingMemory() << " MB remaining." << endl << endl;

    cout << "New Playlist: " << endl;
    Sami.showSongList();
    cout << endl;

    cout << "New Sorted Playlist: " << endl;
    Sami.sortSongList();
    Sami.showSongList();
    cout << endl;

    // clear all songs
    Sami.clearMemory();
    cout << "Clearing memory...";
    Sami.showSongList();
    cout << "No songs in playlist." << endl << endl;

//--------------------SETH'S UTPOD----------------------
    // When size is 0, UtPod should have MAX_MEMORY
    UtPod Seth(0);
    cout << "Initial memory in Seth's UtPod = " << Seth.getRemainingMemory() << " MB" << endl << endl;

    // Tested if you can add a song that's too big
    Song song1("Kendrick Lamar", "HUMBLE", 10982);
    result = Seth.addSong(song1);
    printOutcome(song1, result);

    Song song2("Justin Bieber", "Baby", 349);
    result = Seth.addSong(song2);
    printOutcome(song2, result);

    // show playlist
    cout << endl << "Playlist: " << endl;
    Seth.showSongList();
    cout << endl;

    // Testing removing a song that doesn't exist
    result = Seth.removeSong(song1);
    printRemoving(song1, result);


//--------------------ANA'S UTPOD----------------------
    // When size is negative, UtPod should have MAX_MEMORY
    UtPod Ana(-12);
    cout << endl << "Initial memory in Ana's UtPod = " << Ana.getRemainingMemory() << " MB" << endl << endl;

    Song sg1("Dua Lipa", "New Rules", 453);
    result = Ana.addSong(sg1);
    printOutcome(sg1, result);

    // Testing the sort of only 1 song
    Ana.sortSongList();
    cout << endl << "Sorted Playlist: " << endl;
    Ana.showSongList();
    cout << endl;

    // Testing the shuffling of only 1 song
    Ana.shuffle();
    cout << "Shuffled Playlist: " << endl;
    Ana.showSongList();
    cout << endl;

//--------------------JESSICA'S UTPOD----------------------
    // When size exceeds MAX_MEMORY, UtPod should have MAX_MEMORY
    UtPod Jessica(527);
    cout << "Initial memory in Jessica's UtPod = " << Jessica.getRemainingMemory() << " MB" << endl << endl;

    Song one("Shakira", "Hips Don't Lie", 200);
    result = Jessica.addSong(one);
    printOutcome(one, result);

    Song two("Killers", "Mr. Brightside", 6);
    result = Jessica.addSong(two);
    printOutcome(two, result);

    Song three("Shakira", "Hips Don't Lie", 200);
    result = Jessica.addSong(three);
    printOutcome(three, result);

    Song four("Childish Gambino", "This is America", -30);
    result = Jessica.addSong(four);
    printOutcome(four, result);

    // Testing adding a song that has no size - unsuccessful
    Song five("Beyonce", "Crazy in Love", 0);
    result = Jessica.addSong(five);
    printOutcome(five, result);

    cout << endl << "Playlist: " << endl;
    Jessica.showSongList();
    cout << endl;

    // Testing the removal of the first instance of a song
    result = Jessica.removeSong(three);
    printRemoving(three, result);

    cout << endl << "New Playlist: " << endl;
    Jessica.showSongList();
    cout << endl;

//--------------------PRIEBE'S UTPOD----------------------
    // create UtPod with specific memory size
    UtPod Priebe(200);
    cout << "Initial memory in Priebe's UtPod = " << Priebe.getRemainingMemory() << " MB" << endl << endl;
    cout << "Total Memory = " << Priebe.getTotalMemory() << " MB" << endl;
}
