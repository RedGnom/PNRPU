#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Object {
public:
	virtual void print() = 0;
};
class person: public Object {
protected:
	int age;
	string name;

public:
	person() {
		age = 0;
		name = "";
	}

	friend istream& operator >>(istream& is, person& per) {
		cout << "Введите имя и фамилию: ";
		getline(is, per.name);
		cout << "Введите возраст: ";
		(is >> per.age).ignore();
		return is;
	}

	friend ostream& operator <<(ostream& os, person& stud) {
		cout << " Имя и фамилия: " << stud.name << endl;

		cout << " Возраст: " << stud.age << endl;
		return os;
	}

	void print() override {
		cout << this->name << " Имя" << endl;
		cout << this->age << " Возраст" << endl;
	}
};
class student : public person {
	string subject;
	int mark;
public:
	student() {
		subject = "";
		mark = 0;
		age = 0;
		name = "";
	}
	student(string name, int age, string subject, int mark) {
		this->subject = subject;
		this->age = age;
		this->name = name;
		this->mark = mark;
	}
	friend istream& operator >>(istream& is,student& stud) {
		cout << "Введите имя и фамилию: ";
		getline(is, stud.name);
		cout << "Введите возраст: ";
		(is >> stud.age).ignore();
		cout << "Введите предмет: ";
		getline(is, stud.subject);
		cout << "Введите оценку: ";
		(is >> stud.mark);
		return is;
	}
	friend ostream& operator <<(ostream& os, student& stud) {
		cout << " Имя и фамилия: " << stud.name << endl;
		cout << " Возраст: " << stud.age << endl;
		cout << " Предмет: " << stud.subject << endl;
		cout << " Оценка: " << stud.mark << endl;
		return os;
	}
};
class Vector
{
public:
	friend ostream& operator<<(ostream& out, const Vector& v) {
		if (v.size == 0) {
			cout << "\nВектор пустой" << endl;
		}
		else {
			Object** ptr = v.beg;
			for (int i = 0; i < v.cur; i++) {
				(*ptr)->print();
				ptr++;
			}
		}
		return out;
	}

	void Add(Object* ptr) {
		if (cur < size) {
			beg[cur] = ptr;
			cur++;
		}
	}


	Vector() {
		beg = 0;
		size = 0;
		cur = 0;
	}

	Vector(int lin) {
		beg = new Object * [lin];
		size = lin;
		cur = 0;
	}

	~Vector() {};
private:
	Object** beg;
	int size;
	int cur;
};

int main() {
	system("chcp 1251");

	Vector vec(4);
	person per;
	student stud;

	cin >> per;
	cout << per;

	cin >> stud;
	cout << stud;

	Object* p = &per;
	vec.Add(p);

	p = &stud;
	vec.Add(p);

	cout << vec;

	return 0;
}