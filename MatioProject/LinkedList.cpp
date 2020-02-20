#include "LinkedList.h"
#include "sstream"
using namespace std;

// Пей си пинко розовата пантера
// TODO
bool LinkedList::empty() const
{
	return false;
}

// TODO
// Препоръчвам големината на листа да се държи като private variable в листа
// и да се ъпдейтва, вместо тази функция да се опитва да я изчислява всеки пътс
size_t LinkedList::size() const
{
	return 0;
}

// TODO
T LinkedList::front() const {
	return 0;
}

// TODO
T LinkedList::back() const {
	return 0;
}

T& LinkedList::at(size_type pos) {

	/* 
		Това се нарича ламбда функция
		Не се притеснявай, не е важно да я знаеш засега, а и не е сложна
		Просто е convenient начин да събереш код, който използваш повече от веднъж
		Считай, че когато викам report_error(), все едно копвам и пействам кода вътре
	*/ 
	auto report_error = [this, pos]()
	{
		stringstream s;
		s << "The list is too small. Size: " << this->size() << " Pos: " << pos;
		cout << s.str() << endl;
		throw std::out_of_range("You went too far, bucko!");
	};

	if (pos >= size()) {
		report_error();
	}

	// Почваме от главата на листа
	Node* node = head;

	for (auto i = 0; i < pos; i++) {
		
		if (node == NULL) {
			// Помни NULL = None в питон
			// NULL също така = 0 интерпретирано като пойнтер
			// Никога не трябва да стигаме дотук, горната проверка
			// би трябвало да свърши работа
			// Но засега, преди да се импzz:
			report_error();
		}
		else {
			// Пътуваме през децата докато не стигнем до нужната позиция
			node = node->next;
		}
	}

	return node->get();
}

// TODO
void LinkedList::assign(size_type n, T value) {}

void LinkedList::pop_front(){}

// TODO
void LinkedList::push_front(T value){}

void LinkedList::pop_back(){}

// TODOOOOO
void LinkedList::push_back(T value){}

// TODODODO
void LinkedList::insert(size_type pos, T value){}

void LinkedList::clear(){}
