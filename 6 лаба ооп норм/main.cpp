#include"DoubleList.h"

void menu();
int check();

int main()
{
	setlocale(0, "");

	DoubleList<int>* list = new DoubleList<int>;
	DoubleList<int>::iterator it(list);

	int chose = 1;
	while (chose)
	{
		menu();
		chose = check();
		while (chose < 1 || chose>6)
		{
			std::cout << "����� ������ ����� �� 1 �� 6(������������)\n";
			chose = check();
		}

		switch (chose)
		{
		case 1:
			std::cout << "������� ���������� ��������\n";
			int count;
			std::cin >> count;

			list = list->createFromTail(count);
			break;

		case 2:
			std::cout << "������� �������� ������ ��������\n";
			int value;
			std::cin >> value;
			list->addToTail(value);
			break;

		case 3:
			list->deleteHead();
			break;

		case 4:
			std::cout << list->getValueHead();
			break;

		case 5:
			list->clearList();
			break;

		case 6:
			it = list->begin();

			while (it != nullptr)
			{
				std::cout << *it << " ";
				it++;
			}
		}
		std::cout << "\n";
		std::cout << "0-��������� ������ ���������, 1-����������\n";
		chose = check();

		while (chose < 0 || chose>1)
		{
			std::cout << "����� ������ 0 ��� 1\n";
			chose = check();
		}
	}
	return 0;
}

void menu() {
	std::cout << "1- ��������� �������\n";
	std::cout << "2-�������� ��������\n";
	std::cout << "3-������� �������\n";
	std::cout << "4-�������� ������� ��������\n";
	std::cout << "5- ������� �������\n";
	std::cout << "6-������ �������\n";
}

int check() {
	int x;
	std::cin >> x;
	while (!std::cin)
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "����� ������ �����" << std::endl;
		std::cin >> x;
	}
	return x;
}