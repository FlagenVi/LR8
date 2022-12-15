#include "Data.h"
#include <iomanip>
void print_table(vector<Data> EndTable)
{
	cout << setw(15) << "FileName" << setw(20) << right << "Lines" << setw(20) << "WordsCount" << setw(20) << "WordsFound" << endl;
	for (int i = 0; i < EndTable.size(); i++)
	{
		cout << setw(15) << EndTable[i].get_FileName() << setw(20) << right << EndTable[i].get_Lines() << setw(20) << EndTable[i].get_WordsCount() << setw(20) << EndTable[i].get_WordsFound() << endl;
	}
}