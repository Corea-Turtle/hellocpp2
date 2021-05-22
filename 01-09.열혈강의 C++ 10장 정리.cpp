<10장> 연산자 오버로딩

1.연산자 오버로딩한다는 것은 어떤 의미인가?
  
  1)operator+ 라는 이름의 함수
  
   c++에서는 객체 사이에도 연산이 가능하다.
  
  2)객체 p + 3
  
    p.operator+(3)
  
2.연산자를 오버로딩 하는 두 가지 방법

  -멤버 함수에 의한 오버로딩
  -전역 함수에 의한 오버로딩
  -operator+는 멤버 함수로 존재 할 수 도 있고, 전역함수로 존재할 수도 있다.
  
  
  1)멤버 함수에 의한 연산자 오버로딩
  
        p1 + p2
      p1. operator+ (p2)
  
    Point p3 = p1 + p2
    
        Point operator+ (const Point&p) <여기서 p에 p2가 들어감
        {
            Point temp(x+p.x, y+p.y)
            return temp
        }
       
    Point p3 = "리턴 된 temp 객체"
                       temp 객체는 p1 + p2의 x y값을 더한 객체이다.
      
  2)전역 함수에 의한 오버로딩
    
    멤버 함수로 오버로딩 된 경우 p1.operator+ (p2)
    전역 함수로 오버로딩 된 경우 operator+ (p1,p2)
    
    전역함수로 연산자 오버로딩 된 경우 operator+라는 전역 함수를 호출 하면서
    왼쪽에있는 피연산자가 첫번째 인자, 오른쪽에 있는 피연산자가 두번째 인자로 전달
    
    전역함수로 operator+ 함수가 private 멤버함수를 직접 참조한다면 컴파일 에러가 발생한다.
    따라서 friend 선언을 통해서 참조를 허용해준다.
    ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
    class Point
    {
    private:
      int x, y
    public:
      Point(int _x=0, int _y=0):x(_x),y(_y){}
      void ShowPosition();
      friend Point operator+(const Point& p1, const Point& p2);
    };

    외부에 operator+를 정의 해줌.
    ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
    
    참조. + 연산자를 전역함수, 멤버함수 동시에 오버로딩하면 모호성이 생기면서 컴일 에러가 뜬다.
    따라서 두가지 방법 중 멤버 함수를 통한 연산자 오버로딩을 쓰는 것이 객체지향 프로그램에 더 적절한 표현이다.
     
    3)오버로딩이 가능한 연산자의 종류
     
     오버로딩이 불가능한 연산자들
    .  //멤버 접근 연산자
    .* //멤버 포인터 연산자
    :: //범위 지정 연산자
    ?: //3항 연산자
    sizeof //바이트 단위 크기 계산
    typeid //RTTI 관련 연산자
    static_cast //형변환 연산자
    dyynamic_cast //형변환 연산자
    const_cast //형변환 연산자
    reinterpret_cast //형변환연산자

    위의 연산자들의 제외한 나머지는 가능
    
    4)연산자 오버로딩에 있어서의 주의사항
    
      1.본 의도를 벗어난 연산자 오버로딩은 좋지 않다.
        -연산자 오버로딩을 잘 못 사용하면 프로그램이 오히려 복잡해진다. 의도에 맞게 적절히 사용해야한다.
      2.연산자 우선 순위와 결합성을 바꿀 수는 없다.
        -연산자는 오버로딩 되어도, 연산자가 지니는 우선순위과 결합성은 그대로 따르게 되어 있다.
      3.디폴트 매개 변수 설정이 불가능하다.
        -연산자 오버로딩 특성상 디폴트 매개 변수를 설정하게 되면 함수의 호출관계가 불투명해진다.
      4.디폴트 연산자들의 기본 기능까지 빼앗을 수는 없다.
        -기본적으로 제공되는 연산자들이 지니고 있는 기능을 변경하는 형태로 연산자를 오버로딩 시킬 수 없다.
         ex int operator+(int a, int b)
            {
              return a+b+3;
            }
          int형 덧셈은 그냥 + 를 통해 할수 있는데 operator+를 통해 재정의하여 변경 하는 것은 안된다.
            
     5)왜 "연산자 오버로딩"이라고 불리는가
     
     피연산자들의 종류에 따라서 실행되는 + 연산이 달라지지 때문에
     (같은 + 기호를 써도 객체끼리 더하는 것과 변수나 상수끼리 더하는 것은 다른 의미를 지니기 때문)
            
3.단항 연산자의 오버로딩

  이상 연산자와 단항 연산자의 차이 : 인자의 개수
  
  1)증가, 감소 연산자 오버로딩
  
    ++, --의 경우
    
    ++p ㅡ  멤버 함수로 오버로딩 된 경우 p.operator++()
        ㄴ  전역 함수로 오버로딩 된 경우 operator++(p)

    Point& Point::operator++(){       //멤버함수에 의한 오버로딩
      x++;
      y++;
      return *this
    }

    Point& operator--(Point p){       //전역함수에 의한 오버로딩
      p.x--;
      p.y--;
      return p;
    }
    
    ++p  // p객체의 x,y값이 1씩 증가
    
    ++(++p);// p객체의 x,y값이 2씩 증가
    
    --(--p);// p객체의 x,y값이 2씩 감소
   
    /*
    *this 리턴의 의미
    this는 객체 자신을 가리키는 포인터, 여기에 *를 붙이면 포인터가 가리키는 대상을 참조하겠다. 즉 자기 자신을 리턴하겠다는 뜻
    
    자기 자신을 리턴하지 않는다면 아무것도 입력하지 않았을 때 더이상 진행되지 않는 컴파일 에러가 발생
    
    리턴타입이 Point&이 아니라 Point라면 ++p에 의해 리턴되는 것은 p의 복사본이 되므로 1만 증가
    
    참조리턴       복사본 리턴
    ++(++p)       ++(++p)
    ++(p의 참조)   ++(p의 복사본)
    p값 2증가     p값 1증가 , p의 복사본 값 1 증가
    */

    2) 선 연산과 후 연산의 구분
    
      a++ : 선연산 후증가
      ++b : 선증가 후연사
      
      하지만 연산자의 이름도 같고 피연산자의 개수도 같기 때문에
      ++p -> p.operator++();
      p++ -> p.operator++();      둘이 같은 것으로 연산됨
      
      때문에 c++에서는 이 둘을 구분짓기 위해
      
      ++p -> p.operator++();
      p++ -> p.oeratort++(int); int를 붙혀준다.
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
      #include<iostream>
      using namespace std;

      class Point{
      private:
        int x, y;
      public:
        Point(int _x= 0, int _y=0):x(_x),y(_y){}
        void ShowPosition();
        Point& operator++();
        Point operator++(int);
      };
      void ShowPosition(){
         cout<<x<<"   "<<y<<endl;
      }
      void Point::operator++(){
          x++;
          y++;
          return *this;
      }
      Point& Point::operator++(int){
          Point temp(x, y); //Point temp(*this);
          x++;
          y++;            //++(*this)로 x++, y++ 줄이기 가능
          return temp;
      }
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ


4.교환 법칙 해결하기

  1)연산자를 오버로딩 하되, 전역 함수에 의한 오버로딩이 반드시 필요한 상황
  
    10+p와 같은 경우
  
    멤버 함수에의한 연산자 오버로딩의 경우 10.operator+(p)라는 말도 안되는 문장이 되어
  
    전역 함수에의한 연산자 오버로딩을 써주어야한다. operator+(10,p);는 말이 된다.
  
    따라서 p+10이나 10+p는 같은 경우이므로
  
    Point operator+(int val, Poin& p)
    {
        return p+val;      //단순히 피연산자의 위치만 변경
    }
    을 operator+함수 정의 아래에 추가해주면 p+10 과 10+p 모두 사용이 가능하다.
    
  2)임시 객체의 생성
  
    임시 객체란 임시적으로 생성되었다가 소멸되는 객체이다.
      
      ex) Point(3,4);
  
    int main(void)
    {
       AAA aaa("aaa obj");
       cout<< " 임시객체 생성 전"<<endl;
       AAA("Temp obj");     // 임시객체이기 때문에 aaa처럼 이름이 없다   
       cout<< " 임시객체 생성 후"<<endl;
       return 0;
    }
    임시객체는 생성 즉시 소멸한다.(한 줄이 넘어가면)
      
    //aaa Obj 객체 생성
    //임시객체 생성 전
    //Temp obj 객체 생성
    //Temp obj 객체 소멸
    //임시 객체 생성 후
    //aaa obj 객체 소멸
    
    =임시객체는 경우에 따라(컴파일러 종속적) retrun 뒤에 사용하면 최적화도 되고 코드 줄 수도 줄여 줄 수 있다.
      
5.cout, cin 그리고 endl의 비밀

  1) cout, cin, endl의 구현 이해
  
     함수 오버로딩을 통해 구현 (int, string, double 등을 모두 각각 설정
    ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ  
    #include<stdio.h>

    namespace mystd // mystd라는 소속 시작
    {
        char endl = '\n';
        class ostream // 클래스 ostream 정의
       {
        public:
           ostream& operator<<(const char* str) {       //const를 붙히면 제대로 출력되지만 안붙히면 오류가 뜬다.
                printf("%s", str);                      //const char* 는 문자배열(""에 쓰는데 프로그램 시작부터 쓰기 불가능한 영역에 \n을 써놓고 
               return *this;                            //그곳을 가리키는 포인터를 return하기 때문이다
            }
            ostream& operator<<(int i) {
                printf("%d", i);
                return *this;
            }
           ostream& operator<<(double i) {
                printf("%e", i);
               return *this;
            }
            ostream& operator<<(char i) {                   //endl이 출력되기 위해
                printf("%c", i);
                return* this;
            }                                         

        };
        ostream cout; //cout 객체 생성
     } //mystd 소속 끝

    using mystd::cout;
    using mystd::endl;

    int main()
    {
        cout << "Hello " << endl<< 3 << endl << 3.14 << endl;
       return 0;
    }
    ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
    
    2)<<,>> 연산자의 오버로딩
    
      
