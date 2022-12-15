
#include "Data.h"
void Data::ReadFile()
{
	ifstream ifs(FileName);
	if (!ifs.is_open()) {
		cout << "�� ������� ������� ��� ������ ���� "
			<< FileName << endl; return;
	}
	const char ch = '\n';
	string a;
	while (!ifs.eof())
	{
		getline(ifs, a, ch);
		Lines++;
		data.push_back(a);
	}
	ifs.close();

#ifdef TEST
	cout << "������ ���� ";
	print_data();
#endif
}

void Data::print_data()
{
	cout << FileName << endl;;
	for (int i = 0; i < data.size(); i++)
	{
		cout << data[i] << endl;
	}
	cout << endl;
}

void Data::print_dataFind()
{
	for (int i = 0; i < dataFind.size(); i++)
	{
		cout << dataFind[i] << endl;
	}
	cout << endl;
}

Data::Data(string filename1)
{
#ifdef TEST
	cout << endl << "�������� ����������� ������ Data ��� " << filename1 << endl << endl;
#endif
	FileName = filename1;
	ReadFile();
}

Data::~Data()
{
#ifdef TEST
	cout << endl << "�������� ���������� ������ Data ��� " << FileName << endl << endl;
#endif
}

bool Data::isvowel(char ch)
{
	static std::string vowels("AEIOUYaeiouy");
	return vowels.find(ch) != std::string::npos;
}


void Data::find()
{
	for (int i = 0; i < data.size(); i++)
	{
		char* next = 0;
		string str = data[i];
		char* chars = &str[0];
		char* pch = strtok_s(chars, " ,.-?!",&next);
		while (pch != NULL)
		{
			WordsCount++;
			if (isvowel(pch[0]))
			{
				dataFind.push_back(string(pch));
				WordsFound++;
			}
			pch = strtok_s(NULL, " ,.-!?",&next);
		}

	}
#ifdef TEST
	cout << "��������� ������� find" << endl;
#endif
}

string Data::get_FileName()
{
	return FileName;
}

int Data::get_Lines()
{
	return Lines;
}

int Data::get_WordsCount()
{
	return WordsCount;
}

int Data::get_WordsFound()
{
	return WordsFound;
}

void Data::print_to_file()
{
	string FileNameNew = "find_" + FileName;
	//string FileNameNew = FileName;
	ofstream ofs(FileNameNew);
	if (!ofs.is_open()) {
		cout << "�� ������� ������� ��� ������ ���� "
			<< FileNameNew << endl; return;
	}
	for (int i = 0; i < WordsFound; i++)
	{
		ofs << dataFind[i] << endl;
	}
	ofs.close();
#ifdef TEST
	cout << "��������� ������ � ���� " << FileNameNew << endl;
	print_dataFind();
#endif
}
