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
			std::cout << "Нужно ввести число от 1 до 6(включительно)\n";
			chose = check();
		}

		switch (chose)
		{
		case 1:
			std::cout << "Введите количество элементо\n";
			int count;
			std::cin >> count;

			list = list->createFromTail(count);
			break;

		case 2:
			std::cout << "Введите значение нового элемента\n";
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
		std::cout << "0-завершить работу программы, 1-продолжить\n";
		chose = check();

		while (chose < 0 || chose>1)
		{
			std::cout << "Нужно ввести 0 или 1\n";
			chose = check();
		}
	}
	return 0;
}

void menu() {
	std::cout << "1- заполнить очередь\n";
	std::cout << "2-добавить эелемент\n";
	std::cout << "3-удалить элемент\n";
	std::cout << "4-просмотр первого элемента\n";
	std::cout << "5- очистка очереди\n";
	std::cout << "6-печать очереди\n";
}

int check() {
	int x;
	std::cin >> x;
	while (!std::cin)
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "нужно ввести число" << std::endl;
		std::cin >> x;
	}
	return x;
}