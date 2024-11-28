#include"SparseSet.h"
int main() {
	try {
		LinkedList<Music> m1;
		Music M("ziba",2020,"I Love you  ");
		Music M2("love", 2010, "ye rooz in gele kardam");
		m1.push_back(M2);
		m1.push_back(M);
		Singer singer("Negin",m1);
		Singer singer1("Ebi", m1);
		
		SparseSet<Singer> sparsesinger(4,10);
		sparsesinger.addsname(singer);
		sparsesinger.addsname(singer1);
		//sparsesinger.findId(singer.getId());
		//sparsesinger.delseId(1);
		//sparsesinger.findId(singer.getId());
		sparsesinger.prints();
	}
	catch (const std::exception& x) {
		cout << x.what();
	}
}
