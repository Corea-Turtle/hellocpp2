<11장> string 클래스 디자인
  string 클래스를 구현해보고 연산자 오버로딩을 더 공부함

1.C++ 표준 라이브러리

  - C++ 개발자가 되고 싶다면, 라이브러리에 레퍼런스(reference)성격을 가지는 책 한권 정도는 가지고 있는게 좋다.
  - 라이브러리에 있는 것을 가져다 쓰는 것도 좋지만 직접 그런 자료를 구현할 수 있는 능력을 기르는 것이 중요하다.
  
2.표준 string 클래스

  표준 stirng 클래스의 기능을 간단하게 구현하기 위한 요구사항
 ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ 
  1.생성자, 소멸자, 복사 생성자, 대입 연산자 정의
   -string클래스는 문자열을 저장하기 위한 용도
   -저장하려는 문자열의 길이가 일정하지 않음
   -따라서 저장할 배열을 생성자 내에서 동적 할당
   
   2.문자열을 인자로 전달받는 생성자를 정의
    -string 클래스의 객체 생성 과정에서 문자열을 인자로 전달받는 생성자 호출
     string str1 = "Good"  묵시적 변환->   string str1("Good");

   3.+연산자 오버로딩
     -str1+str2 와 같은 객체끼리 연산은 오버로딩된 +임
   
   4.<<연산자 오버로딩
     -<<연산자를 이용해서 string 객체가 지니는 문자열 출력
     
   5.+=연산자를 오버로딩
     -str1 문자열 뒤에 str2의 문자열 추가
   
   6.내용 비교하는 == 연산자 오버로딩
     -주의 사항 : string객체가 지니는 문자열 포인터 값을 비교 (x)
                 포인터가 가리키는 문자열의 내용 비교가 이뤄져야 함
  
   7. >>연산자 오버로딩
     -cin기능을 넣기 위한 오버로딩
  ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

3.사용자 정의 string 클래스

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using std::endl;
using std::cout;
using std::cin;

using std::ostream;
using std::istream;

//첫번째 요구사항 생성자,소멸자,복사생성자, 대입 연산자의 정의
class string {
    int len; //null 문자를 포함하는 문자열의 길이
    char* str;
public:
    string(const char* s = NULL);
    string(const string& s);
    ~string();

    string& operator=(const string& s);
    string& operator+=(const string& s);
    bool operator==(const string& s);
    string operator+(const string& s);

    friend ostream& operator<<(ostream& os, const string& s);
    friend istream& operator>>(istream& is, string& s);
};

string::string(const char* s) {       //문자열을 인자로 받을 수 있는 생성자, 디폴트 매개 변수가 설정되어 있으므로
    len = (s != NULL ? strlen(s) + 1 : 1); //       string str; 로도 객체 생성 가능. 이때 NULL이지만 길이를 0이 아닌 1로 설정하는 이유는
    str = new char[len];               // NULL이라도 최소한의 동적할당을 여기서 해줘야 하기 때문이다    
                                     //왜냐하면 소멸자는 무조건 포인터 str이 가리키는 메모리 공간을 delete하기 때문이다.
    if (s != NULL)                        //0으로 공간이 없게 되면 소멸자가 메모리 해제할 공간이 없으므로 컴파일 에러
        strcpy(str, s);
}
//string클래스의 소멸자와 깊은 복사를 하는 복사 생성자의 정의
string::string(const string& s) {
    len = s.len;
    str = new char[len];
    strcpy(str, s.str);
}
string::~string() {
    delete[] str;
}
//생성자내 동적 할당이 있기 때문에 대입연산자에도 적절한 정의 필요(메모리 유출 방지 코드 한줄 추가
string& string::operator=(const string& s) {
    delete[]str; //메모리 유출 방지 코드

    len = s.len;
    str = new char[len];
    strcpy(str, s.str);

    return *this; //연속적인 대입 연산을 허용하기 위해
}
//세번째 요구사항 + 연산자의 오버로딩, 두개의 피연산자를 참조해서 새로운 객체 생성
string string::operator+(const string& s) {
    char* tStr = new char[len + s.len - 1];  //len이 null문잒지 포함된 길이이기 때문에 널이 2개 되므로 하나를 빼준다.
    strcpy(tStr, str);      //문자열 복사
    strcat(tStr, s.str);     //문자열 추가

    string temp(tStr);
    delete[] tStr;
    return temp;
}//세번째 요구사항은 operator+=함수를 이용해서 보다 쉽게 구현 가능. 그러나 여기서는 일반적인 형태로 정의하였다.
//네번째 요구사항 <<를 오버로딩(전역변수 형태)
ostream& operator<<(ostream& os, const string& s) {
    os << s.str;
    return os;
}
//다섯번째 요구사항 += 오버로딩. 기존의 객체에 문자열을 추가하는 기능
string& string::operator+=(const string& s) {
    len = len + s.len - 1;
    char* tStr = new char[len];
    strcpy(tStr, str); //문자열 복사
    delete[] str;

    strcat(tStr, s.str); //문자열추가
    str = tStr;
    return *this;
}
//여섯번째 요구사항 내용비교 ==연산자 오버로딩
bool string::operator==(const string& s) {
    return strcmp(str, s.str) ? false : true;    //strcmp로 문자열 내용비교, 같다면 0 아니면 0이외 다른 수
}
//일곱번째 요구사항 >>연산자 오버로딩 : 입력
istream& operator>>(istream& is, string& s) {
    char str[100];      //문자를 입력받기 위해 충분히 큰 배열 선언
    is >> str;

    s = string(str);        //입력받은 문자열을 가지고 임시객체(string(str)) 생성. 그리고 입력대상이 되는 string객체 s에 대입
    return is;            //이 과정에서 string 객체의 오버로딩된 대입 연산자가 호출. 앞에서 정의 했으므로 적절한 결과가 나옴
}

int main()
{
    string str1 = "Good ";
    string str2 = "Morning ";
    string str3 = str1 + str2;

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;

    str1 += str2;

    if (str1 == str3) {
        cout << "equal!" << endl;
    }

    string str4;

    cout << "문자열 입력: ";
    cin >> str4;
    cout << "입력한 문자열: " << str4 << endl;

    return 0;
}

 
