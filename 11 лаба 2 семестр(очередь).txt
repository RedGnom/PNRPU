#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct Node
{
	T data;
	Node* next;
};

template <typename T>
struct Queue {
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	int size = 0;
};

template <typename T>
void enqueue(Queue<T>& q, T a) {
	Node<T>* new_node = new Node<T>;
	new_node->data = a;
	new_node->next = nullptr;
	if (q.tail != nullptr) {
		q.tail->next = new_node;
	}
	else {
		q.head = new_node;
	}
	q.tail = new_node;
	q.size++;
}

template <typename T>
void dequeue(Queue<T>& q) {
	Node<T>* delete_node = q.head;
	q.head = delete_node->next;
	if (q.head == nullptr) {
		q.tail = nullptr;
	}
	delete delete_node;
	q.size--;
}

template <typename T>
T front(Queue<T>& q) {
	return q.head->data;
}

template <typename T>
void print(Queue<T>& q1, Queue<T>& q2) {
	int p = q1.size;
	if (p == 0) cout << "Очередь пуста";
	else {
		for (int i = 0; i < p; i++) {
			cout << front(q1) << ' ';
			enqueue(q2, front(q1));
			dequeue(q1);
		}
	}
	cout << '\n';
}

int main()
{
	setlocale(LC_ALL, "ru");
	int n;
	Queue<string> q1, q2;
	cout << "Введите количество элементов в очереди:";
	cin >> n;
	cout << "Вводите элементы очереди:";
	cin.ignore();
	for (int i = 0; n > i; i++) {
		string a;
		getline(cin, a);
		enqueue(q1, a);
	}
	cout << "Очередь: ";
	print(q1, q2);
	cout << "Введите ключ для удаления: ";
	string key;
	getline(cin, key);
	for (int i = 0; i < n; i++) {
		if (front(q2) == key) {
			dequeue(q2);
		}
		else {
			enqueue(q1, front(q2));
			dequeue(q2);
		}
	}
	cout << "Очередь после удаления: ";
	print(q1, q2);
	cout << "Введите количество новых элементов: ";
	int k, s;
	cin >> k;
	cout << "C какого номера их вставить? ";
	cin >> s;
	s = n - s+1;
	cin.ignore();
	n = q2.size;
	for (int i = 0; i < n - s + 1; i++) {
		enqueue(q1, front(q2));
		dequeue(q2);
	}
	cout << "Вводите новые элементы: ";
	for (int i = 0; i < k; i++) {
		string a;
		getline(cin, a);
		enqueue(q1, a);
	}
	while (q2.head != nullptr) {
		enqueue(q1, front(q2));
		dequeue(q2);
	}
	cout << "Очередь после добавления: ";
	print(q1, q2);
}