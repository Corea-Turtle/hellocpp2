<13장> 예외 처리(Exception Handling)
  
1.기존의 예외 처리 방식

  1)예외를 처리하지 않는 프로그램의 오류
      
    ex)나눗셈을 하는 프로그램에서 나누는수(제수)가 0인 경우
    
  2)전통적인 스타일의 예외 처리
  
    "예외 처리를 위한 코드 부분과 일반적인 프로그램의 흐름을 위한 코드부분을 명확하게 구분 짓지 못한다."
    -작성과 유지보수 모두 불편한 상황
    
2.C++의 예외 처리 메커니즘

  -C++은 구조적으로 예외를 처리할 수 있는 메커니즘을 제공한다. = 예외 처리 코드 부분 독립 가능
   ->코드의 가독성과 유지보수성이 좋아짐
   
   1)기본적인 예외 처리 매커니즘(try, catch, throw)
     1.try - 예외 발생에 대한 검사 범위를 설정할 때 사용(try블록 안에서 검사)
      
      try{
          //예외 발생 예상 지역
      }

     2.catch - 예외를 처리하는 코드 블록을 선언할 때 사용. try 블록 내에서 발생한 예외 상황을 
               처리하는 코드가 존재하는 영역, 형태는 리턴 없는 함수와 유사
               
     catch(처리되어야 할 예외의 종류){
        //예외를 처리하는 코드가 존재할 위치
     }
     
     catch는 항상 try 뒤에 바로 이어서 등장해야한다. 
     
      try{
          //예외 발생 예상 지역
      }
       catch(처리되어야 할 예외의 종류){
        //예외를 처리하는 코드가 존재할 위치
      }

      3.throw - 예외 상황이 발생하였음을 알릴 때 사용
      
        throw ex;   //ex를 가리켜 보통은 그냥 "예외"라고 표현을 한다.
                    //ex는 변수, 상수, 객체 등등 대부분의 데이터가 될 수 있다.
        "throw 문에 의해 던져진 예외는, 예외를 감싸는 try 블록 다음에 등장하는 catch 블록에 의해 처리 된다."
 
        ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
        try{
          //예외 발생 예상 지역
             if(예외 상황 발생)
               throw ex       //1.throw에 의한 예외 발생
        }
        catch(excepton ex){                //2.예외의 전달
        //예외 상황 처리
        }
        ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
        
     2)예외 처리 매커니즘의 적용
     
        
        
        
