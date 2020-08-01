#include<iostream>
#include<string.h>
using namespace std;

class String {
public:
    String(const char* data);
    String();
    String(const String& str);
    String& operator=(const String &str);
    ~String();

    inline char* get_c_str() const { return m_data; }

private:
    char* m_data;
};

// 构造函数
inline String::String(const char* data) {
    m_data = new char[strlen(data) + 1];
    strcpy(m_data, data);
}

inline String::String() {
    m_data = new char[1];
    *m_data = '\0';
}

// 析构函数
inline String::~String() {
    delete[] m_data;
}

String::String(const String& str) {
    int size = strlen(str.get_c_str()) + 1;
    m_data = new char[size];
    strcpy(m_data, str.get_c_str());
}

// 拷贝复制函数
inline String& String::operator=(const String& str) {
    if (m_data == str.get_c_str()) {
        return *this;
    }


    if (*m_data == *str.get_c_str()) {
        return *this;
    }

    delete[] m_data;
    int size = strlen(str.get_c_str()) + 1;
    m_data = new char[size];
    memcpy(m_data, str.get_c_str(), size*sizeof(char*));
    return *this;
}

ostream& operator<<(ostream& os, const String& str) {
    return os << str.get_c_str();
}

int main() {
    String name("王者");
    String game1 = "吃鸡";
    String game2(game1);
    cout << name << "," << game1 << "，" << game2 << endl;
    game2 = game1;
    cout << name << "," << game1 << "，" << game2 << endl;
}