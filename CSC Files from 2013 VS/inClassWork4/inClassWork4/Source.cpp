//Erkin George
//CSC 1230
//In class work

#include<iostream>
#include<string>

using namespace std;

void greetUser(string& userName);
void favoriteStuff(string& userName, string& favMovie, string& favBook);
void criticizeUser(string& userName, string& favMovie, string& favBook);

int main()
{
	string userName;
	string favMovie;
	string favBook;
	greetUser(userName);
	favoriteStuff(userName,favMovie,favBook);
	criticizeUser(userName, favMovie, favBook);
	return 0;

}

void greetUser(string& userName)
{
	cout << "Hello user! Please enter your name:" << endl;
	getline(cin, userName);
	return;
}

void favoriteStuff(string& userName,string& favMovie,string& favBook)
{
	cout << "Hello, " << userName << endl;
	cout << "What is your favorite book?" << endl;
	getline(cin,favBook);
	cout << "What is your favorite movie?" << endl;
	getline(cin, favMovie);
	return;
}

void criticizeUser(string& userName, string& favMovie, string& favBook)
{
	string temp;
	temp = userName + " loves the movie " + favMovie + " and also loves the book " + favBook;
	cout << "The user, " << temp << endl;
	return;
}