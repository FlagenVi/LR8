#include "Main.h" //mamka
//mama
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	vector<Data> EndTable;
	Data tmp1("file1.txt");
	tmp1.find();
#ifdef TEST
	tmp1.print_to_file();
#endif
	EndTable.push_back(tmp1);
	Data tmp2("file2.txt");
	tmp2.find();
#ifdef TEST
	tmp2.print_to_file();
#endif
	EndTable.push_back(tmp2);
	Data tmp3("file3.txt");
	tmp3.find();
#ifdef TEST
	tmp3.print_to_file();
#endif	
	EndTable.push_back(tmp3);
	print_table(EndTable);

	system("pause");
	return 0;
}