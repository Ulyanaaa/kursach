#include "header.h"

void vivod(fstream& p)
{
	p.clear();
	p.seekg(0, fstream::beg);
	// ������� ����� � ������� �����
	while (read(p, zap))
	{
		out(zap);
	}
	cout << 
}

void write_new(fstream& p)
{
	p.clear(); // ������ ������
	p.seekg(0, fstream::beg);
	Shop zap;
	zap = vvod(p);   // ����� ������
	p.write(p,zap);    // ���������� ������� � ����

}

Shop vvod(fstream& p)
{

}