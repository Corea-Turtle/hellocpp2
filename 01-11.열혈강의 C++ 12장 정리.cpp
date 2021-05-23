<12장> 템플릿

1. 템플릿은 기능은 결정되어 있고 자료형은 결정되지 않은 상태
   
   template <typename T>  // T라는 이름(typename)에 대해서, 다음에 정의하는 대상을 템플릿으로 선언한다.
   T Add(T a, T b)        // typename이 표준이지만 class를 써도 된다(과거에는 class를 써서 호환성을 높히려고 가능하게 만듬)
   {                      // T대신 다른 문자를 써도 됨
        return a+b;
   }
   
   -템플릿으로 정의된 함수의 자료형이 결정되는 시점은 인자가 전달되는 시점이다.(cout 등)
     
2. 함수 템플릿 (템플릿임을 강조. 함수가 아니라는 말은 아님)

   의적 홍길동 - 홍길동이 주 
   
   1)둘 이상의 타입에 대해서 템플릿화 하기
   
     template <typenmae T> 로 할 경우
     T Add(T a, T b)       일때 입력되는 두 변수의 자료형이 같아야한다.
                           그렇지 않으면 컴파일 에러가 난다.
      
     만약 입력되는 두 변수가 달라도 템플릿이 잘 실행되게 하려면 두개를 선언해주면 된다.
     template <typename T1, typename T2>
     void ShowData(T1 a, T2 b)
     
   2)함수 템플릿의 특수화(template specialization)
     
     template<typename T>
     int sizeof(T a)
     {
       return sizeof(a);
     }
     
     위와 같이 템플릿을 선언했지만 어떤 값은 원하는 방식으로 따로 템플릿을 특수화하여 선언할 수 있다
     
     template<> //함수 템플릿 특수화 선언;
     int sizeof(char *a)//전달인자가 char* 인경우에는 이 함수를 호출
     {
        return strlen(a); //a문자열의 길이를 출력
     }
     
      -템플릿 특수화 표현은 다음과 같이 한줄에  표현하는 것이 보통이다
      1. template<> int sizeof(char* a)
      2. template<> int sizeof<>(char* a)
      3. template<> int sizeof<char*>(char* a) //가장 정확한 표현 1,2는 3을 줄여쓴 표현    

3.클래스 템플릿
        
      1)클래스 템플릿의 정의
      
      #include<iostream>
      using std::endl;
      using std::cout;

      template<typename T>
      class Data
      {
          T data;
       public:
          Data(T d){
              data=d;
          }
          void SetData(T d){
              data=d;
          }
          T GetData(){
                return data;
          }
       };

        int main(void)
        {
            Data<int> d1(0);      //T를 int로 간주하고 객체 생성
            d1.SetData(10);
            Data<char> d2(' a ');  //T를 char로 간주하고 객체 생성
          
            cout<<d1.GetData()<<endl;
            cout<<d2.GetDAta()<<endl;
        }

        //클래스 템플릿에 적절한 자료형을 먼저 선언하고 객체 생성하는 이유는
        //객체 생성 과정에 있다. 객체가 생성될 때 먼저 메모리를 할당하고 생성자가 호출되는데
        //자료형을 선언해주지 않으면 메모리 할당을 어떻게 할지 컴파일러가 결정하지 못하여 에러가 발생한디.

        2)클래스 템플릿의 선언과 정의 분리
          
          template<typename T> //아래의 T가 무엇인지 설명, 멤버함수를 정의할 때마다 꼭 붙혀줘야한다. 안그러면 컴파이에러
          Data<T>::SetData(T d){ //Data<T> : 클래스의 템플릿 타입
                data=d;
          }
          
          클래스 템플릿 Data와 클래스 Data는 구분되는 것이기 때문에<T>를 붙혀서 구분
          Data::SetData() 는 클래스 Data를 나타내고 Data<T>::SetData는 클래스 템플릿 Data를 나타냄
          
        3)스택(stack)클래스의 템플릿화
        
          스택의 기능 두 가지 : 1.push(저장, 쌓아올림) 2.pop (출력, 꺼내놓음)
            
          스택 클래스를 템플릿화 하면 여러가지 자료형을 스택할 수 있다.(하나의 자료형에 종속되지 않고 쓸 수 있음)
            
4.템플릿의 원리 이해

  템플릿을 설정하고 호출시
  
  1. 자료형에 맞는 함수가 컴파일러에 의해 생성된다.
  2. 이미 만드어져있던 자료형에 해당하는 함수는 해당 자료형을 호출시 다시 사용된다.
  
  -이러한 함수들을 "템플릿 함수"라고 하고
   이렇게 함수가 생성되는 현상을 "함수 템플릿의 인스턴스화(instantiation)"이라고 부른다.        
  
  -클래스 템플릿도 같은 원리이다.
            
  -템플릿을 처리해주는 것은 컴파일러이기 때문에 템플릿 클래스는 선언과 정의를 다른 파일에 분리시켜놓을 수 없다.
   (다른 파일을 합치는 역할은 링커의 역할이기 때문이다.)
            
