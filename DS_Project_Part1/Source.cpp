#include"SparseSet.h"
int main() {
	try {
		/*LinkedList<Music> m1;*/
		/*Music M("ziba",2020,"I Love you  ");
		Music M2("love", 2010, "ye rooz in gele kardam");*/
	/*	m1.push_back(M2);
		m1.push_back(M);*/
		/*Singer singer("Negin",m1);
		Singer singer1("Ebi", m1);*/
		
		SparseSet<Singer> sparsesinger(4,10);
		sparsesinger.addsname("Ebi");
		sparsesinger.addsname("Googosh");
		//sparsesinger.findId(singer.getId());
		//sparsesinger.delseId(1);
		//sparsesinger.findId(singer.getId());
		//sparsesinger.prints();
		/*sparsesinger.cls();*/
		/*string input;
		while (true) {
			std::getline(std::cin, input); 
			if (input == "END") { 
				break;
			}
			multilineInput += line + "\n"; 
		}*/
	/*	sparsesinger.prints();*/
		sparsesinger.addms("Love", 2020,"banana", 1);
		sparsesinger.addms("nothing", 2020, "I Love you\nbaby\nhoney ", 1);
		 sparsesinger.addms("Love", 2018, "I hate you\nbaby\nhoney ", 0);
		sparsesinger.prints();
		/*sparsesinger.findmname("Love");*/
		SparseSet<PlayList> pl(4,10);
		/*pl.addpname("Bahar");
		pl.addmp(3, 0, sparsesinger);*/
		sparsesinger.delm(1, 0, pl);
		cout << endl << endl<<endl<<endl;
		sparsesinger.prints();

	}
	catch (const std::exception& x) {
		cout << x.what();
	}
}
