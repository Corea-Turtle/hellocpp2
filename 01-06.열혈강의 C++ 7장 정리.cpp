<7장? 상속

1. 상속의 기존 의미
   -기존에 쓰이던 의미 : 기존에 정의해 놓은 클래스를 재활용하기 위해서 필요한 문법적 요소
   -but 상속으로 인해 유지보수가 엄청나게 용이해짐(단순 재활용이 아니다)
    
2. 기본 개념
   -철수는 아버지로부터 좋은 목소리와 큰 키를 물려받았다(상속했다).
   -Student 클래스가 Person 클래스를 상속한다.
        Student 클래스는 Person클래스가 지니고 있는 모든 멤버 변수와 멤버 함수를 물려받는다.
        =Student 객체는 -> Student 클래스에 선언되어있는 멤버 + Person 클래스에 선언되어 있는 멤버 모두 가짐
   
   -상속 한다는 선언
   
   class Student : public Person
   
   student 객체
   ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
   Person 클래스에 선언된 멤버}
   Student 클래스에 선언된 멤버}  - 이 순서대로 멤버가 구성됨
   ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
   
   상속되는(부모)클래스 - Super 클래스 Base 클래스
   상속받는(자식)클래스 - Sub 클래스 Derived 클래스
   
3. 상속하는 클래스(자식)의 객체 생성 및 소멸 과정
   
   +생성 과정+
   
   1)메모리 공간의 할당, 이 떄 상속되는 클래스(부모)를 감안해서 메모리 공간 할당
   2)Base 클래스의 생성자 실행
   3)Derived 클래스의 생성자 실행
   
   중요:  메모리를 할당 후 조건에 맞는 Derived 클래스의 생성자를 찾고 - Derived 생성자의 몸체는 실행 안되고 
   Base 생성자에 조건에 맞는 (조건이 없으면 void 생성자) 생성자 몸체를 호출 - 이후에 Derived 생성자의 몸체 실행.
     
   생성자(부모) 조건 입력 BBB(int j) : AAA(j) {} - int j 를 받을 수 있는 AAA의 생성자를 호출하라 
     
   +소멸과정+
     
   자식클래스의 소멸자 소멸 - > 부모 클래스의 소멸자 소멸
   
4. protected 멤버

  -protected 멤버는 외부에서 보면 private로 보이고, 상속 관계에서 보면 public으로 보인다.
     
5. 상속의 세가지 형태

  -public 상속, protected 상속, private 상속
  
  class 자식클래스 : public, protected, private 중 택 부모클래스
  ex) class Derived : protected Base
  
     상속형태      public 상속        protected 상속         private 상속
  Base 클래스
                      
  public 멤버      public             protected             private
  protected 멤버   protected          protected             private
  private 멤버     접근불가            접근불가              접근불가
  
  -접근 불가와 private는 다르다. private는 object 객체 내엥서 직접 접근이 가능. 접근 불가는 내부에서 직접 접근 불가능
   둘다 base클래스의 public, protected 멤버 함수를 통해서 간접적인 형태로 접근하는 것은 가능하다.
     
6. 상속을 하는 이유
  
   - 클래스들의 공통되는 부분을 Base 클래스로 추상화하고, 이를 상속하면서 각각의 특징을 드러낼 수 있도록 Derived 클래스를 정의 
 
  
  
