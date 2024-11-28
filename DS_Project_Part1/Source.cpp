#include"SparseSet.h"
int main() {
	try {
		LinkedList<Music> m1;
		Music M("Ebi",2020,"I Love you  ");
		Music M2("Hayede", 2010, "ye rooz in gele kardam");
		m1.push_back(M2);
		m1.push_back(M);
		Singer singer("Negin",m1);
		
		SparseSet<Singer> sparsesinger(4,10);
		sparsesinger.addsname(singer);
		sparsesinger.findId(singer.getId());
	}
	catch (const std::exception& x) {
		cout << x.what();
	}
}
