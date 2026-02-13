#include <bits/stdc++.h>
using namespace std;


class Persistence {
    public:
    virtual void save() {}
};

class SqlDB : public Persistence
{
public:
    void save() override {
        cout << "Saving to SQL" << endl;
    }
};

class MongoDB : public Persistence {
    public:
    void save() override {
        cout << "Saving to MongoDb" << endl;
    }
};


class UserService {
    Persistence *db;

    public:
    UserService(Persistence &db) {
        this->db = &db;
    }

    void saveToDb() {
        db->save();
    }
};

int main() {

    UserService *us = new UserService(*new SqlDB());
    us->saveToDb();

	return 0;
}