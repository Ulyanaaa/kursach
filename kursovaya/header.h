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

using namespace std;

// ��������� ��������
struct Shop {
    char name[20];
    char color[20];
    int hight;
    int grow;
    int bloom;
    
    int start_bloom[6];
    int end_bloom[6];
};


void write_new(fstream& p);
void vivod(fstream& p);
Shop vvod(fstream& p);