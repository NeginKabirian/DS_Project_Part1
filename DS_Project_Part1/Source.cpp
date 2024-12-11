#include"SparseSet.h"
//int main() {
//	try {
//		/*LinkedList<Music> m1;*/
//		/*Music M("ziba",2020,"I Love you  ");
//		Music M2("love", 2010, "ye rooz in gele kardam");*/
//	/*	m1.push_back(M2);
//		m1.push_back(M);*/
//		/*Singer singer("Negin",m1);
//		Singer singer1("Ebi", m1);*/
//		
//	//	SparseSet<Singer> sparsesinger(4,10);
//	//	sparsesinger.addsname("Ebi");
//	//	sparsesinger.addsname("Googosh");
//	//	//sparsesinger.findId(singer.getId());
//	//	//sparsesinger.delseId(1);
//	//	//sparsesinger.findId(singer.getId());
//	//	//sparsesinger.prints();
//	//	/*sparsesinger.cls();*/
//	//	/*string input;
//	//	while (true) {
//	//		std::getline(std::cin, input); 
//	//		if (input == "END") { 
//	//			break;
//	//		}
//	//		multilineInput += line + "\n"; 
//	//	}*/
//	///*	sparsesinger.prints();*/
//	//	sparsesinger.addms("Love", 2020,"banana", 1);
//	//	//cout<<endl<<"index: "<< sparsesinger.search(1, 0, "for")<<endl;
//	//	//cout << "index: " << sparsesinger.countw(1, 0, "gee");
//	//	sparsesinger.addms("nothing", 2020, "I Love you\nbaby\nhoney ", 1);  
//	//	sparsesinger.addms("nothing", 2020, "Iopop", 1);
//	//	 sparsesinger.addms("Love", 2018, "I hate you\nbaby\nhoney ", 0);
//		//sparsesinger.prints();
//		/*sparsesinger.findmname("Love");*/
//		
//		//sparsesinger.delm(1, 0, pl);
//		//cout << endl << endl<<endl<<endl;
//		//sparsesinger.prints();
//		/*Sort<int> sort;*/
//		/*int arr[8] = { 2, 24, 45, 66, 75, 90, 170, 802 };
//		sort.Radix(arr,8);
//		for (int i = 0; i < 8; ++i) {
//			cout << arr[i] << " ";
//		}*/
//		/*pl.addpname("Bahar");
//		pl.addmp(0, 0, sparsesinger);
//		pl.addmp(1, 0, sparsesinger);
//		pl.addmp(2, 0, sparsesinger);
//		pl.addmp(3, 0, sparsesinger);*/
//		//.searchm(,10);
//		//pl.delmp(0, 0);
//		//cout << pl.searchm(0,0).getLyrics();
//	  // pl.searchpid(0);
//	  /* pl.showp(0);*/
//	}
//	catch (const std::exception& x) {
//		cout << x.what();
//	}
//	SparseSet<Singer> sparsesinger(4, 10);
//	sparsesinger.addsname("Ebi");
//	sparsesinger.addsname("Googosh");
//	sparsesinger.addms("Love", 2025, "banana", 1);
//	//cout<<endl<<"index: "<< sparsesinger.search(1, 0, "for")<<endl;
//	//cout << "index: " << sparsesinger.countw(1, 0, "gee");
//	//try {
//		sparsesinger.addms("nothing", 2030, "I Love you\nbaby\nhoney ", 1);
//		sparsesinger.addms("nothing", 2020, "Iopop", 1);
//		sparsesinger.addms("Love", 2018, "I hate you\nbaby\nhoney ", 0);
//		SparseSet<PlayList> pl(4, 10);
//		pl.addpname("Bahar");
//		pl.addpname("B");
//		pl.addpname("C");
//		pl.addpname("D");
//		pl.addmp(0, 0, sparsesinger);
//		pl.addmp(1, 0, sparsesinger);
//		pl.addmp(2, 0, sparsesinger);
//		pl.addmp(3, 0, sparsesinger);
//		pl.showp(0);
//		pl.addqpid(0);
//		pl.addqpid(1);
//		pl.addqpid(2);
//		pl.addqpid(3);
//		pl.pop();
//
//	//}
//	//catch (const std::exception& x) {
//	//	cout << x.what();
//	////}
//	
//}
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
    std::cout << "10 - Search for a music item by ID (searchmId)\n";
    std::cout << "Enter your choice: ";
}
void displayPlayListMenu() {
    std::cout << "1 - Add a playlist name (addpname)\n";
    std::cout << "7 - Add a singer to a specific music item (addmp)\n";
    std::cout << "10 - Count words matching a pattern (countw)\n";
    std::cout << "14 - Search for a music item in SparseSet (searchm)\n";
    std::cout << "15 - Delete a music item from SparseSet (delmp)\n";
    std::cout << "16 - Search a playlist by ID (searchpid)\n";
    std::cout << "17 - Show details of a playlist (showp)\n";
    std::cout << "18 - Add to playlist queue by ID (addqpid)\n";
    std::cout << "19 - Remove from the playlist queue (pop)\n";
    std::cout << "Enter your choice: ";
}
void displayMainMenu() {
    std::cout << "Main Menu:\n";
    std::cout << "1 - Create SparseSet for Singers\n";
    std::cout << "2 - Create SparseSet for PlayLists\n";
    std::cout << "0 - Exit\n";
    std::cout << "Enter your choice: ";
}
void sparsSinger(SparseSet<Singer>& S,SparseSet<PlayList>& P) {
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
        //    case 8: {
        //        string music_name = "";
        //        cout << "\nmusic_name : ";
        //        cin >> music_name;
        //        int year;
        //        cout << "\nyear : ";
        //        cin >> year;
        //        
        //        string lyrics = "";
        //        bool in_quotes = false;
        //        char c1 , c2;
        //        cin.ignore();
        //        c1 = getchar();
        //        //while (1) {
        //        //    c2 = getchar();
        //        //    while (c2 != '“') {
        //        //        c2 = getchar();
        //        //        lyrics += c2;
        //        //    }
        //        //    lyrics += '\n';
        //        //    c1 = getchar();
        //        //    if (c1 != '“')
        //        //        break;
        //        //}
        //        while (true) {
        //            string line;
        //            getline(cin, line); 
 
        //            for (char ch : line) {
        //                if (ch == '“') {
        //                    in_quotes = !in_quotes;
        //                }
        //            }
        //            if (!in_quotes && line.empty()) {
        //                break;
        //            }

        //            lyrics += line + "\n";    
        //        }

        //        if (lyrics.empty()) {
        //            cout << "No lyrics provided." << endl;
        //            break;
        //        }
        //        getchar();
        //        int artist_Id;
        //        cout << "\nartist_name : ";
        //        cin >> artist_Id;
        //        try {
        //            S.addms(music_name, year, lyrics, artist_Id);
        //        }
        //        catch (const std::exception& x) {
        //            cout << x.what();
        //        }
        //    }
        //      break;
        }
    } while (choice);
}
int main() {
    int Mainchoice;
    SparseSet<PlayList> P(4, 10);
    do {
        displayMainMenu();
        std::cin >> Mainchoice;
        cout << endl;
        switch (Mainchoice) {
            case 1 :
                int scapacity;
                int smaxvalue;
                std::cout << "Creating a new Singer SparseSet...\n";
                cout << "Capacity : ";
                cin >> scapacity;
                cout << "\nMax value : ";
                cin >> smaxvalue;
                try {
                    SparseSet<Singer> S(scapacity, smaxvalue);
                    sparsSinger(S,P);
                }
                catch (const std::exception& x) {
                    cout << x.what();
                }
               
            break;
            case 2:
                int capacity;
                int maxvalue;
                std::cout << "Creating a new Singer SparseSet...\n";
                cout << "Capacity : ";
                cin >> capacity;
                cout << "\nMax value : ";
                cin >> maxvalue;
                try {
                    SparseSet<PlayList>(capacity, maxvalue);
                }
                catch (const std::exception& x) {
                    cout << x.what();
                }
                break;
        }
            
    } while (Mainchoice != 0);
}