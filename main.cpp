#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "md5.h"

using std::string;

class User {
	std::string username;
	string password_hash;

public:
	User(string username_, string password_) {
		username = username_;
		set_password_hash(password_);
	};
	void set_password_hash(string password_) {
		password_hash = md5(password_);
	};
	string get_username() {
		return username;
	}
	string get_password_hash() {
		return password_hash;
	}
};

std::unordered_map<string, string> username_password_hashtable;

bool check_username_unique(string username) {
    if (username_password_hashtable.count(username) > 0) return false;
    else return true;
}

void add_user(string username, string password) {
    if (check_username_unique(username)) {
        username_password_hashtable.insert({username, md5(password)});
    }
}

int main()
{
    add_user("tom", "1234");
    add_user("ted", "1234");
}
