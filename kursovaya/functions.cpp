#include "header.h"

// ���� ������ ��������
int menu()
{
	setlocale(LC_ALL, "Russian");
	int choise;
	cout << endl << endl << "�������� �������� (������� �����,��������������� ������ ������): " << endl;
	cout << "1 - �������� ������� �������� " << endl;
	cout << "2 - �������� ����� �������� " << endl;
	cout << "3 - ������ ����� �������� ����� ������ � ������������ ���������� �������" << endl;
	cout << "4 - �������� ��� ��������" << endl;
	cout << "5 - ����� ������ �� ��������" << endl;
	cout << "6 - ������� ����������" << endl;
	cout << "7 - �����" << endl;

	cin >> choise;
	return choise;
}




// ���� �����
void write_new(fstream& p)
{
	SetConsoleCP(1251);   // ��� �������� �����
	
	p.clear();
	p.seekg(0, fstream::end);
	Shop zap;
	zap = vvod(p);   // ���� ������
	write(p, zap, 0);    // ���������� ������ � ����
}


Shop vvod(fstream& p)
{
	Shop zap;
	setlocale(LC_ALL, "rus");
	cout << "������� �������� �����:  "; cin >> zap.name;
	cout << "������� ���� ��������:  "; cin >> zap.color;
	cout << "������� ������ ��������� ��������:  "; cin >> zap.hight;
	cout << "������� ���-�� ���� �� ������� �� ������ ��������:  "; cin >> zap.grow;
	cout << "������� ������� ���� ������������� ��������:  ";  cin >> zap.bloom;
	strcpy(zap.marka, "+");
	return zap;
}


// ������ � ����
void write(fstream& p, Shop zap, int num)
{
	p.clear();
	if (num)
	{
		p.seekg((num - 1) * len, ios::beg);
	}
	p.write((char*)&zap, len);
}






// ���� ������
void vivod(fstream& p)
{
	SetConsoleCP(1251);   // ��� �������� �����
	p.clear();    // ������ �����
	p.seekg(0, ios::beg);
	Shop zap;
	cout << dividing_line << endl;
	cout<< shapka;
	cout << dividing_line << endl;
	while (read(p, zap))
	{
		print(zap);
	}
	cout << endl << dividing_line << endl;
}

void print(Shop zap) 
{
	setlocale(LC_ALL, "ru");
	cout << endl
		<< setw(15) << zap.name
		<< setw(15) << zap.color
		<< setw(15) << zap.hight
		<< setw(25) << zap.grow
		<< setw(25) << zap.bloom
		<< setw(15) << zap.marka;
}



// ������ �����
fstream& read(fstream& p, Shop& zap, int num)
{
	p.clear();
	if (num)
		p.seekg((num - 1) * len, ios::beg);
	p.read((char*)&zap, len);
	return p;
}






// �������, �������������� �������������� �������
void print_res_bloom(fstream& p, int start_bloom[], int end_bloom[])
{
	p.clear();
	Shop zap;
	p.seekp(0, ios::beg);


	// ��� ������� ���������������� 123-128 ������, ������������������ 132	
	// ������ ����� ������ ����
	SYSTEMTIME st;
	GetLocalTime(&st);
	int array_now_date[2];
	array_now_date[0] = st.wDay;
	array_now_date[1] = st.wMonth;
	int now_date = perevod_dat(array_now_date);
	

	// ���������� ���������� ��� ����������� ����
	//int now_date = 145;
	
	
	// ���������� ��������
	int count = 0; int count_index = 0;

	// ���������� ������������ �������� � ����
	int start_otr;
	int end_otr;
	start_otr = perevod_dat(start_bloom);
	end_otr = perevod_dat(end_bloom);
	
	// ������ �������� ������ � ������� �����
	int array[2][100];

	// ������ �������� �� ��������, ������� � ���� ������
	while (read(p, zap))
	{
		if (((now_date + zap.grow) <= (start_otr)) && ((end_otr) <= (now_date + zap.grow + zap.bloom)))
		{
			array[0][count_index] = count;
			array[1][count_index] = zap.hight;
			count_index++;
		}
		count++;
	}

	// ���������� ������ �� ���������� ��� ������� ��� ������� ��������
	int* array_max_to_min = new int[count_index];
	int ind = 0;
	for (int i = 0; i < count_index; i++)
	{
		// ������� ������������ ������
		int not_main_znach = array[1][0];
		for (int j = 0; j < count_index; j++)
		{
			if (array[1][j] >= not_main_znach)
			{
				not_main_znach = array[1][j];
				array_max_to_min[i] = array[0][j];
				ind = j;
			}
		}

		// ������ ���� �� ��� ����� ��� �� ��������
		array[1][ind] = -100;
	}

	// �������
	cout << dividing_line << endl;
	cout << shapka;
	cout << dividing_line << endl;
	for (int i = 0; i < count_index; i++)

	{
		if (read(p, zap, array_max_to_min[i] +1))
		{
			print(zap);
		}	
	}
	cout << endl << dividing_line << endl;
}




// ������,����������� ���� � ���-�� ���� �� ������ ����
int perevod_dat(int array[])
{
	// ������ � ���-��� ���� � ������ ������
	int days_in_maonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int count = 0;

	int day = array[0];
	int month = array[1];

	for (int i = 0; i < month; i++)
	{
		count += days_in_maonth[i];
	}
	count += day;
	return count;
}





// ���� ��� �����
// ������� �� ��������
 void metka_for_delete(fstream& p, char* sort)
{
	 p.clear();
	 Shop zap;
	 p.seekp(0, ios::beg);

	 for (int i = 1; read(p, zap, i); i++)
	 {
		 if (strcmp(zap.name, sort) == 0)
		 {
			 strcpy_s(zap.marka, "-");
			 write(p, zap, i);
			 break;
		 }
	 }
}




// ����� ������� �� ��������
void delete_marks(fstream& p)
{
	p.clear();
	Shop zap;
	p.seekp(0, fstream::beg);
	for (int i = 1; read(p, zap, i); i++)
	{
		if (strcmp(zap.marka, "-") == 0)
		{
			strcpy_s(zap.marka, "+");
			write(p, zap, i);
		}
	}
}




// ������� ���������� ������
void delet_who_with_mark(fstream& p)
{
	fstream p2("dop.txt", fstream::app);
	p.clear();
	Shop zap;
	p.seekp(0, fstream::beg);
	for (int i = 1; read(p, zap, i); i++)
	{
		if (strcmp(zap.marka, "+") == 0)
		{
			write(p2, zap);
		}
	}
	p2.close();
	p.close();
	remove(fname);
	rename("dop.txt", fname);
	p.open(fname, fstream::in | fstream::out | fstream::binary);
}