<9장> virtual의 원리와 다중 상속

1.클래스 멤버함수는 사실 어디에

  멤버 변수는 각 객체 내에 존재, 멤버 함수는 각 객체들이 같은 메모리에 존재하는 함수를 공유하는 방식 
  
2.가상함수가 동작하는 원리

  1개 이상의 가상함수를 포함하는 클래스 
  -> 컴파일러가 가상함수 테이블을 만듬 = VTable(Virtual Table)
                                                key값(함수구분)    value값(위치)
  VTable은 각 가상함수의 위치정보를 저장해둔다. ex)void A::Func1()    0x1100번지
  
  객체를 생성한다면 각 virtual 함수를 포함하는 클래스마다 VTable을 위한 포인터가 멤버로 추가된다.(접근 가능한 포인터는 아님)
  
  추신. 가상함수가 포함되지 않는 클래스는 VTable이 생성되지 않는다.
  
3.다중 상속에 대한 이해

  다중상속 : 하나의 자식클래스가 여러 부모 클래스를 상속하는 것 = 클래스간 관계가 복잡해지므로 안쓰는게 좋음
                                                             다중상속을 해야만 풀수 있는 문제는 존재하지 않는다.
  
  다중상속을 할 경우 - 부모 클래스 들에 같은 이름의 함수가 존재할 경우 모호성 때문에 범위(::)를 정확히 지정해줘야 호출 가능 따라서 안쓰는게 더 좋다.
 
  
4.virtual Base 클래스

  A ㅡ  B  \  
    ㄴ  C  / \_>  D  B c는 A를 상속하고 D는 B, C 를 상속하게 되면 D는 A함수를 두번 상속하게 되어 모호성이 발생한다.
    
 이때 B, C가 A를 상속하는 것을 class B : virtual public A 이런식으로 버츄얼 상속해주면 해결된다.
 
 하지만 결국 다중 상속을하면 코드와 클래스사이의 관계가 복잡해지므로 다중 상속은 쓰지 않는게 좋다.
