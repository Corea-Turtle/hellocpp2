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
    
    
                                                                      
    
