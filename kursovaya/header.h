/*
70
��������� ����� �������� ������ �������� ��������� ��������� ���������� ��
���������� ������. � ������ ����� ������� � ���� ������������ ��������� ������:
�������� �����, �������� �����, ������ ��������� ��������, ����� � ���� �� ��� �������
�� ������ ��������, ����������������� ��������. ��������� ���������� ������ ������,
�������, ������ �������� � ���� �������, ������������ �������� � �������� ���������
�������� (���� ������ ��������, � ���� ����� �������� �������� � ����������). ����� �
������ ����������� � ������� ���������� ������ ��������.
*/

// ����������
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib> // ��� ������� exit()
#include <cstring>
#include <string.h>
#include <algorithm>
#include <iomanip>
#include <windows.h>

using namespace std;

extern int len;
extern const char* fname;

// ��������� ��������
struct Shop {
    char name[20];
    char color[20];
    int hight;
    int grow;
    int bloom;
    
    int start_bloom[6];
    int end_bloom[6];

    char marka[2];
};


// ���������(�����) ������������ �����
ostream& shapka(ostream& stream);
ostream& dividing_line(ostream& stream);



//���������
int menu();

void write_new(fstream& p);
void vivod(fstream& p);
void print(Shop zap);
void print_res_bloom(fstream& p, int start_bloom[], int end_bloom[]);
int perevod_dat(int array[]);
void write(fstream& p, Shop zap, int num = 0);

fstream& read(fstream& p, Shop& zap, int num = 0);
Shop vvod(fstream& p);

int metka_for_delete(fstream& p, char* sort);
void delete_marks(fstream& p);
int delet_who_with_mark(fstream& p);

