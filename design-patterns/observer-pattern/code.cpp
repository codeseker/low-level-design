#include <bits/stdc++.h>
using namespace std;


class Video {
    string title;
    double duration;
    public:
    Video(string title, double duration) {
        this->duration = duration;
        this->title = title;
    }

    string getVideoInfo() {
        return "[Video: Title => " + this->title + " Duration => " + to_string(this->duration) + " ]";
    }
};

class IUser {
    public:
    virtual void update() = 0;
};

class IChannel {
    public:
    virtual void subscribe(IUser *u) = 0;
    virtual void unsubscribe(IUser *u) = 0;
    virtual void notify() = 0;
};

class Channel : public IChannel {
    set<IUser* > users;
    vector<Video> videos;

    string name;

    public:

    Channel(string name) {
        this->name = name;
    }

    void subscribe(IUser *u) override {
        users.insert(u);
    }

    void unsubscribe(IUser *u) override {
        users.erase(u);
    }

    void notify() override {
        for(auto it: users) {
            it->update();
        }
    }

    void uploadVideo(Video &v) {
        videos.push_back(v);
        notify();
    }

    string getVideoDetail() {
        return videos.back().getVideoInfo();
    }

    string getName() {
        return this->name;
    }

};


class Subscriber : public IUser {
    Channel* channel;
    string name;
    public:
    Subscriber(string name, Channel* ch) {
        this->name = name;
        this->channel = ch;
    }

    void update() override {
        cout << "Hey " << this->name << " The channel " << channel->getName() << " has uploaded New Video" << endl;
        cout << channel->getVideoDetail() << endl;
    }
};



int main() {

    Channel *first = new Channel("LLDCamp");
    Subscriber* u1 = new Subscriber("Ayush", first);
    Subscriber* u2 = new Subscriber("John", first);

    first->subscribe(u1);
    first->subscribe(u2);

    Video v("Introduction to LLD", 17.52);
    first->uploadVideo(v);


    first->unsubscribe(u2);

    Video u("UML Basics", 10.0);
    first->uploadVideo(u);



    return 0;
}


