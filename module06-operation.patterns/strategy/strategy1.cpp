#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Strategy;

class TestBed {
public:
    enum StrategyType {
        Dummy, Left, Right, Center
    };

    TestBed() {
        strategy_ = NULL;
    }

    // setter injection
    void setStrategy(int type, int width);

    void doIt();

private:
    Strategy *strategy_;
};

class Strategy {
public:
    Strategy(int width) : width_(width) {}

    void format() {
        char line[120], word[30];
        ifstream inFile("..\\strategy\\quote.txt", ios::in);
        line[0] = '\0';

        inFile >> word;
        strcat(line, word);
        while (inFile >> word) {
            if (strlen(line) + strlen(word) + 1 > width_)
                justify(line);
            else
                strcat(line, " ");
            strcat(line, word);
        }
        justify(line);
    }

protected:
    int width_;
private:
    virtual void justify(char *line) = 0;
};

class LeftStrategy : public Strategy {
public:
    LeftStrategy(int width) : Strategy(width) {}

private:
    void justify(char *line) override {
        cout << line << endl;
        line[0] = '\0';
    }
};

class RightStrategy : public Strategy {
public:
    RightStrategy(int width) : Strategy(width) {}

private:
    void justify(char *line) override {
        char buf[80];
        int offset = width_ - strlen(line);
        memset(buf, ' ', 80);
        strcpy(&(buf[offset]), line);
        cout << buf << endl;
        line[0] = '\0';
    }
};

class CenterStrategy : public Strategy {
public:
    CenterStrategy(int width) : Strategy(width) {}

private:
    void justify(char *line) override {
        char buf[120];
        int offset = (width_ - strlen(line)) / 2;
        memset(buf, ' ', 120);
        strcpy(&(buf[offset]), line);
        cout << buf << endl;
        line[0] = '\0';
    }
};

void TestBed::setStrategy(int type, int width) {
    delete strategy_;
    if (type == Left)
        strategy_ = new LeftStrategy(width);
    else if (type == Right)
        strategy_ = new RightStrategy(width);
    else if (type == Center)
        strategy_ = new CenterStrategy(width);
}

void TestBed::doIt() {
    strategy_->format();
}

int main() {
    TestBed test; // Factory method
    int answer, width;
    cout << "Exit(0) Left(1) Right(2) Center(3): ";
    cin >> answer;
    while (answer) {
        cout << "Width: ";
        cin >> width;
        test.setStrategy(answer, width); // injection ? user
        test.doIt();
        cout << "Exit(0) Left(1) Right(2) Center(3): ";
        cin >> answer;
    }
    return 0;
}