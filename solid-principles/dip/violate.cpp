#include <bits/stdc++.h>
using namespace std;

class SqlDB
{
public:
    void saveToSql() {
        cout << "Saving to SQL" << endl;
    }
};

class MongoDB {
    public:
    void saveToMongo() {
        cout << "Saving to MongoDb" << endl;
    }
};


class UserService {
    SqlDB s;
    MongoDB mg;

    public:
    UserService(SqlDB sq, MongoDB m) {
        this->s = sq;
        this->mg = m;
    }

    void saveToSql() {
        s.saveToSql();
    }

    void saveToMongo() {
        mg.saveToMongo();
    }
};

int main() {

    UserService *us = new UserService(SqlDB(), MongoDB());
    us->saveToSql();
    us->saveToMongo();

	return 0;
}