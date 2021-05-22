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
  
     함수 오버로딩을 통해 구현 (int, string, double 등을 모두 각각 설정)
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
                printf("%c", i);                            //const char* endl="/n"; 으로 바꿔주면 이부분은 생략 가능
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
    
    객체 자체를 <<를 통해 바로 프린트할 수 있을까? std에 정의 되어 있지 않으므로 안된다.
    따라서 객체의 멤버함수를 <<,>>연산자를 통해 바로 프린트 하고 싶다면
    <<,>> 연산자를 오버로딩하여 객체를 바로 연산 가능하도록 선언 및 정의 해줘야한다.
      
    멤버 함수로 정의하려면 cout<<p => cout.operator<<(p)가 가능해야하는데 이는 C++표준에서 미리 정의되어 있지 않기 때문에 안된다.(변경도 불가능)
      
    따라서 전역 함수를 통해 정의 해줘야한다.
      
    ostream& operator<<(ostream& os, const Point& p) 이런 식으로 오버로딩 해준다.
      
    ostream& os에서 os는 ostringstream이다.
    ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
    #include<iostream>
    using namespace std;

    class Point{
    private:
      int x, y;
    public:
      Point(int _x=0, int _y=0):x(_x), y(_y){}
      friend ostream& operator<<(ostream& os, const Point& p);
    };

    ostream& operator<<(ostream&os, const Point& p)
    {
      os<<"["<<p.x<<", "<<p.y<<"]"<<endl;
      retrun 0;
    }
    ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
    
6.배열의 인덱스 연산자 오버로딩의 예

  -배열 요소에 접근하는 [ ] 연산자의 오버로딩

  1)기본 자료형 데이터를 저장할 수 있는 배열 클래스 만들기
    
    ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
     #include<iostream>
     using namespace std;

     const int SIZE = 3; // 저장소의 크기

     class Arr{
     private:
       int arr[SIZE];
       int idx;
     public:
       Arr():idx(0){}           //생성자 Arr(), 멤버함수 idx는 0으로 초기화
       int GetElem(int i);       //요소를 참조하는 함수
       void SetElem(int i, int elem); //저장된 요소를 변경하는 함수
       void AddElem(int elem);         //배열에 데이터를 저장하는 함수
       void ShowAllDatd();     
     };
      int Arr::GetElem(int i){
          return arr[i];
      }
      void Arr::SetElem(int i, int elem){
          if(idx<=i){
              cout<<"존재하지 않는 요소!"<<endl;
              return;
          }
          arr[i] = elem;
      }
      void Arr::AddElem(int elem){
          if(idx>=SIZE) {
              cout<<"용량 초과!"endl;
              return;
          }
          arr[idx++]=elem
      }
      void Arr::ShowAllData(){
          for(int i=0, i<idx; i++)
            cout<<"arr["<<i<<"]="<<arr[i]<<endl;
      }

      int main(void)
      {
        Arr arr;
        arr.AddElem(1);
        arr.AddElem(2);
        arr.AddElem(3);
        arr.ShowAllData();
        
        //개별요소 접근 및 변경
        arr.SetElem(0, 10);          //배열의 느낌으로 하려면 arr[1] = 10 이렇게 해야함  arr[i] => arr.operator[](i)
        arr.SetElem(1, 20);          //따라서 클래스 선언과 아래 정의에 아래 코드를 추가한다. 값을 넣으면 변해야하므로 참조자를 사용
        arr.SetElem(2, 30);          //int& Arr::operator[](int i){ 
                                     //     return arr[i]; 
        cout<<arr.GetElem(0)<<endl;  //}
        cout<<arr.GetElem(1)<<endl;
        cout<<arr.GetElem(2)<<endl;

        return 0;
        }
    ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
    
      2)객체를 저장할 수 있는 배열 클래스
      
        객체를 배열에 저장할 때 고려해야 할 요소들
        
        1.객체의 저장방식 : 단순히 객체의 포인터를 저장하는 형태 | 객체 자체를 저장하는 형태
        2.포인터를 저장하는 형태 - 배열 클래스의 객체 복사가 이뤄질 때 어떤 형태의 복사를 진행할 것인지
                 단순히 포인터만 복사(얕은 복사) | 포인터가 가리키는 대상까지 복사(깊은 복사)
        3.배열 클래스가 지녀야할 기능 - 해답은 없음, 구현해야할 프로그램의 성격에 따라 달라짐
        
    ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ    
        #include<iostream>
        using namespace std;
        using std::ostream;
        /******************Point Class******************/
        class Point{
        private:
          int x, y;
        public:
          Point(int _x=0,int _y=0):x(_x),y(_y){}
          friend ostream& operator<<(ostream& os, const Point& p); //만약 p객체가 선언 안되고 임시객체가 되더라도 출력됨
        };

        ostream& operator<<(ostream&os, const Point&p)
        {
            os<<"["<<p.x<<","<<p.y<<"]";
            return os;
        }

        /***************PointArr Class********************/
        const int SIZE = 5; // 저장소의 크기
        
        class PointArr {
        private:
           Point arr[SIZE];
           int idx;
        public:
           PointArr():idx(0){}
           void AddElem(const Point& elem);
           void ShowAllData();
           Point& operator[](int i) //배열 요소에 접근   
        };
        void PointArr::AddElem(const Point& elem){
            if(idx>=SIZE){
                cout<<"용량 초과"<<endl;
                return ;
            }
            arr(idx++) = elem;
        }
        void PointArr::ShowAllData(){
              for(int i=0; i<idx; i++)
                  cout<<"arr["<<i<<"]="<<arr[i]<<endl;
        }
        Point& PointArr::operator[](int i){
            return arr[i];
        }

        int main(void)
        {
        PointArr arr;
          
        arr.AddElem(Point(1,1));  //임시객체를 매개변수로 사용해서 arr[0]에 Point class의 멤버 변수 x = 1, y = 1을 넣었다.
                                  //임시객체는 생성되자마자 배열에 값이 복사 되고 바로 사라진다.
        //개별 요소 접근 및 변경
        arr[0]= Point(10.10);
          
        cout<<arr[0]<<endl;
          
        return 0;
        }
        
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ

7.반드시 해야만 하는 대입 연산자의 오버로딩

  1)오버로딩 된 대입 연산자의 존재: 디폴트 대입 연산자
    - 디폴트 생성자, 소멸자, 복사 생성자와 같이 프로그래머가 operator=을 정의해주지 않아도 정의 되어 있는 "대입연산자" 이다
    리턴 타입은 클래스&형이고 자기 자신을 리턴한다. 리턴 타입이 void형이면 다음 문장이 에러가 난다.
                                         
                                                p1=p2=p3
     Point& Point::operator=(const Point& p)
     {
          x=p.x
          y=p.y
          return *this;
     }

  2)디폴트 대입 연산자의 문제점
  
     -디폴트 복사 생성자가 지니고 있는 문제점과 개념적으로 일치
        = 메모리 유출과, 얕은 복사
     따라서 프로그래머가 직접 정의해주는 대입 연산자에서는, 깊은 복사가 이뤄지도록 정의해야한다.
    
    얕은 복사 - A가 가리키고 있는 대상을 B도 가리킨다. 
               이때 메모리 해제가 되게 되면 A가 가리키는 대상은 소멸하는데 B는 여전히 소멸된 A의 대상을 가리킨다. - 에러발생
    
    메모리 유출 - A와 B모두 A의 대상을 가리킬때 원래 B가 가리키던 대상은 동적으로 할당된 메모리 공간이기 때문에
                 접근은 불가하지만 프로그램 종료시까지 메모리에 남아있다.
  
    디폴트 대입 연산자의 형태(이러한 문제점을 일으키는)
    Person& Person::operator=(const Person& p)
    {
        name=p.name;
        return *this                                //멤버대 멤버를 복사하는 형태(얕은 복사)
    }
    
    p1 객체 -> "Lee"                   p1객체   x  "Lee"    
                        대입연산->             \
    p2 객체 -> "Kim"                   p2객체 ㅡ > "Kim"


  3)깊은 복사를 하는 대입 연산자
  
    Person& Person::operator=(const Person&p)
    {
          delete[] name;
          name= new char[strlen(p.name)+1];
          strcpy(name,p.name);
          return *this;
    }

    -delete[] name은 디폴트 연산자의 메모리 유출을 막기 이한 것.
    -그 아래 두줄은 깊은 복사를 위한 문장(복사 생성자와 동일한 문장의 형태를 구성)
     
    결론 : 생성자 내에서 메모리 공간을 동적 할당하게 되면,
           할당된 메모리를 해제하는 용도의 소멸자를 정의해야 하며,
            복사 생성자와 대입 연산자도 깊은 복사를 하도록 정의해야한다.
              
             
