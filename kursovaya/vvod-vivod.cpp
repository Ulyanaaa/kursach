#include "header.h"

ostream& shapka(ostream& stream)
{
	setlocale(LC_ALL, "rus");
	stream << setw(15) << "����"
		<< setw(15) << "����"
		<< setw(15) << "������"
		<< setw(25) << "������������ �����"
		<< setw(25) << "������������ ��������"
		<< setw(15) << "�����" << endl;
	return stream;
}


ostream& dividing_line(ostream& stream) {
	stream << setfill('-') << setw(120) << ' ' << setfill(' ');
	return stream;
}
