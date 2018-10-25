#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

struct book
{
	string name;
	int author;
	int status;
	/*
	* 0: in shelf
	* 1: borrowed
	* 2: returned
	*/
};

vector<book> books;
vector<string> authors;

int add_author(string auth)
{
	for (int i = 0; i < authors.size(); i++) {
		if (auth == authors[i]) {
			return i;
		}
	}
	authors.push_back(auth);
	return authors.size() - 1;
}

bool cmp(book a, book b)
{
	if (authors[a.author] == authors[b.author]) {
		return a.name < b.name;
	}
	return authors[a.author] < authors[b.author];
}

int change_state(string name, int state)
{
	for (int i = 0; i < books.size(); i++) {
		if (name == books[i].name) {
			books[i].status = state;
			return i;
		}
	}
	return -1;
}

void shelve(int id)
{
	bool flag = true;
	for (int i = id - 1; i >= 0; i--) {
		if (books[i].status == 0) {
			flag = false;
			cout << "Put " << books[id].name << " after " << books[i].name << endl;
			break;
		}
	}
	if (flag) {
		cout << "Put " << books[id].name << " first" << endl;
	}
	books[id].status = 0;
}

int main()
{
	string x, temp;
	book new_book;
	stack<int> rets;
	while (getline(cin, temp)) {
		if (temp == "END")
			break;
		int p = temp.find(" by ");
		new_book.name = temp.substr(0, p);
		new_book.author = add_author(temp.substr(p+4));
		new_book.status = 0;
		books.push_back(new_book);
	}
	sort(books.begin(), books.end(), cmp);
	while (cin >> x) {
		if (x == "END") 
			break;
		if (x == "BORROW") {
			cin.get();
			getline(cin, temp);
			change_state(temp, 1);
		}
		if (x == "RETURN") {
			cin.get();
			getline(cin, temp);
			rets.push(change_state(temp, 2));
		}
		if (x == "SHELVE") {
			while (!rets.empty()) {
				shelve(rets.top());
				rets.pop();
			}
			cout << "END" << endl;
		}
	}
	return 0;
}