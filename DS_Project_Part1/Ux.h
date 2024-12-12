#pragma once
#include"SparseSet.h"
using namespace std;
void displaySingerMenu() {
    std::cout << "Menu Options:\n";
    std::cout << "1 - Add a singer name (addsname)\n";
    std::cout << "2 - Delete an entry by singer ID (delseId)\n";
    std::cout << "3 - Find an entry by singer ID (findId)\n";
    std::cout << "4 - Print all entries (prints)\n";
    std::cout << "5 - Clear all data (cls)\n";
    std::cout << "6 - Find a music item by Id (findmname)\n";
    std::cout << "7 - Delete a music item (delm)\n";
    std::cout << "8 - Add a music item with details (addms)\n";
    std::cout << "9 - Search for substr in lyrics(search)\n";
    std::cout << "10 - Count words matching a pattern (countw)\n";
    std::cout << "Enter your choice: ";
}
void displayMainMenu() {
    std::cout << "Main Menu:\n";
    std::cout << "1 - Command for SingersSparseSet\n";
    std::cout << "2 - Command for PlayListSparseSet\n";
    std::cout << "0 - Exit\n";
    std::cout << "Enter your choice: ";
}
void sparsSinger(SparseSet<Singer>& S, SparseSet<PlayList>& P) {
    int choice = -1;
    do {
        displaySingerMenu();
        std::cin >> choice;
        cout << endl;
        switch (choice) {
        case 1:
        {
            string name;
            cout << "\nName : ";
            cin >> name;
            try {
                S.addsname(name);
            }
            catch (const std::exception& x) {
                cout << x.what();
            }
        }
        break;
        case 2:
        {
            int id;
            cout << "\nId : ";
            cin >> id;
            try {
                S.delseId(id);
            }
            catch (const std::exception& x) {
                cout << x.what();
            }
        }
        break;
        case 3:
        {
            int id;
            cout << "\nId : ";
            cin >> id;
            try {
                S.findId(id);
            }
            catch (const std::exception& x) {
                cout << x.what();
            }
        }
        break;
        case 4:
        {
            try {
                S.prints();
            }
            catch (const std::exception& x) {
                cout << x.what();
            }
        }
        break;
        case 5:
        {
            try {
                S.cls();
            }
            catch (const std::exception& x) {
                cout << x.what();
            }
        }
        break;
        case 6:
        {
            string Name;
            cout << "\nName : ";
            cin >> Name;
            try {
                S.findmname(Name);
            }
            catch (const std::exception& x) {
                cout << x.what();
            }
        }
        break;
        case 7:
        {
            int artist_Id;
            cout << "\nartist_Id : ";
            cin >> artist_Id;
            int music_id;
            cout << "\nmusic_id : ";
            cin >> music_id;
            try {
                S.delm(artist_Id, music_id, P);
            }
            catch (const std::exception& x) {
                cout << x.what();
            }
        }
        break;
        case 8: {
            std::string music_name;
            int year;
            std::string lyrics;
            int artist_Id;
            MyString mystring;
            std::cin.ignore();
            cin >> music_name;
            cin >> year;


            // std::cout << "\nEnter lyrics line by line (each line must start and end with \"). Enter a line without \" to finish:\n";
            std::cin.ignore();

            string line;
            while (true) {
                std::getline(std::cin, line);
                if (line.empty() || line.front() != '"' || line.back() != '"') {
                    break;
                }
                //lyrics += line.substr(1, line.size() - 2) + "\n"; 
                lyrics += mystring.substr(line, 1, mystring.len(line)) + "\n";  //Implement concat
            }


            artist_Id = stoi(line);
            try {

                S.addms(music_name, year, lyrics, artist_Id);
                std::cout << "\nMusic added successfully!";
            }
            catch (const std::exception& e) {
                std::cout << "\nError: " << e.what();
            }
            break;
        }

        case 9:
        {
            int artist_Id;
            cout << "\nartist_Id : ";
            cin >> artist_Id;
            int music_id;
            cout << "\nmusic_id : ";
            cin >> music_id;
            string lyrics;
            cout << "\nName : ";
            cin >> lyrics;
            try {
                S.search(artist_Id, music_id, lyrics);
            }
            catch (const std::exception& x) {
                cout << x.what();
            }
        }
        break;
        case 10:
        {
            int artist_Id;
            cout << "\nartist_Id : ";
            cin >> artist_Id;
            int music_id;
            cout << "\nmusic_id : ";
            cin >> music_id;
            string lyrics;
            cout << "\nName : ";
            cin >> lyrics;
            try {
                S.countw(artist_Id, music_id, lyrics);
            }
            catch (const std::exception& x) {
                cout << x.what();
            }
        }
        }

    } while (choice);
}
void displayPlayListMenu() {
    std::cout << "1 - Add a playlist name (addpname)\n";
    std::cout << "2 - Add a music to a specific playlist item (addmp)\n";
    std::cout << "3 - Search a playlist by ID (searchpid)\n";
    std::cout << "4 - Search for a music item in PlayList (searchm)\n";
    std::cout << "5 - Delete a music item from PlayList (delmp)\n";
    std::cout << "6 - Show details of a playlist (showp)\n";
    std::cout << "7 - Add to playlist queue by ID (addqpid)\n";
    std::cout << "8 - Remove from the playlist queue (pop)\n";
    std::cout << "Enter your choice: ";
}
void sparsePlayList(SparseSet<Singer>& S, SparseSet<PlayList>& P) {
    int choice = -1;
    do {
        displaySingerMenu();
        std::cin >> choice;
        cout << endl;
        switch (choice) {
        case 1:
        {
            string name;
            cout << "\nName : ";
            cin >> name;
            try {
                P.addpname(name);
            }
            catch (const std::exception& x) {
                cout << x.what();
            }
        }
        break;
        case 2:
        {
            int music_id, playlist_id;
            cout << "\nmusic_Id : ";
            cin >> music_id;
            cout << "\nplaylist_Id : ";
            cin >> playlist_id;
            try {
                P.addmp(music_id, playlist_id, S);
            }
            catch (const std::exception& x) {
                cout << x.what();
            }
        }
        break;
        case 3:
        {
            int id;
            cout << "\nId : ";
            cin >> id;
            try {
                P.searchpid(id);
            }
            catch (const std::exception& x) {
                cout << x.what();
            }
        }
        break;
        case 4:
        {
            int music_id, playlist_id;
            cout << "\nmusic_Id : ";
            cin >> music_id;
            cout << "\nplaylist_Id : ";
            cin >> playlist_id;
            try {
                P.searchm(playlist_id, music_id);
            }
            catch (const std::exception& x) {
                cout << x.what();
            }
        }
        break;
        case 5:
        {
            int music_id, playlist_id;
            cout << "\nmusic_Id : ";
            cin >> music_id;
            cout << "\nplaylist_Id : ";
            cin >> playlist_id;
            try {
                P.delmp(playlist_id, music_id);
            }
            catch (const std::exception& x) {
                cout << x.what();
            }
        }
        break;
        case 6:
        {
            int playlist_id;
            cout << "\nplaylist_Id : ";
            cin >> playlist_id;
            try {
                P.showp(playlist_id);
            }
            catch (const std::exception& x) {
                cout << x.what();
            }
        }
        break;
        case 7:
        {
            int playlist_id;
            cout << "\nplaylist_Id : ";
            cin >> playlist_id;
            try {
                P.addqpid(playlist_id);
            }
            catch (const std::exception& x) {
                cout << x.what();
            }
        }
        break;

        case 8:
        {
            try {
                P.pop();
            }
            catch (const std::exception& x) {
                cout << x.what();
            }
        }
        break;
        }

    } while (choice);
}