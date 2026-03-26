/*************************************************************
 * 객체 지향 프로그래밍에서 클래스를 사용하는 프로그램       *
 *************************************************************/
#include <iostream>
using namespace std;

/************************************************************
 * 클래스 정의                                              *
 * 데이터 멤버와 멤버 함수를 선언                           *
 ************************************************************/
class Circle
{
private:
    double radius;
public:
    //constructor 
    Circle() {
        cout << this << "원 객체 생성 (기본생성자)\n";
    }
    Circle(double r) {
        cout << this << "원 객체 생성 (매개변수 생성자)\n";
        radius = r;
    }
    Circle(const Circle& c) {
        radius = c.radius;
        cout << this << "복사생성자\n";
    }
    ~Circle() { 
        cout << this << "원 객체 소멸\n";//소멸되는 시점의 객체 this
    }
    double getRadius() const;
    double getArea() const;
    double getPerimeter() const;
    void setRadius(double value);
};
/**************************************************************
 * 멤버 함수 정의 부분                                        *
 * 멤버 함수들은 클래스 선언 부분에서 선언                    *
 **************************************************************/
 // getRadius 멤버 함수의 정의
double Circle::getRadius() const
{
    return radius;
}
// getArea 멤버 함수의 정의
double Circle::getArea() const
{
    const double PI = 3.14;
    return (PI * radius * radius);
}
// getPerimeter 멤버 함수의 정의
double Circle::getPerimeter() const
{
    const double PI = 3.14;
    return (2 * PI * radius);
}
// setRadius 멤버 함수의 정의
void Circle::setRadius(double value)
{
    radius = value;
}

Circle circle5;

void test() {
    Circle circle6(2.0);
}
/********************************************************
 * 애플리케이션 부분                                    *
 * 클래스를 인스턴스화해서 객체를 만들고 활용           *
*********************************************************/
int main()
{
   
    cout << "Circle 1" << endl;
    Circle circle1; //첫번째 원 객체 //기본생성자
    circle1.setRadius(10.0);
    cout << "반지름: " << circle1.getRadius() << endl;
    cout << "넓이: " << circle1.getArea() << endl;
    cout << "둘레: " << circle1.getPerimeter() << endl << endl;

    test(); // 
   
    cout << "Circle 2" << endl;
    Circle circle2; //두번째 원 객체 //복사생성자
    circle2.setRadius(20.0);
    cout << "반지름: " << circle2.getRadius() << endl;
    cout << "넓이: " << circle2.getArea() << endl;
    cout << "둘레: " << circle2.getPerimeter();
    return 0;

    Circle circle3(5.0);
    return 0;


    Circle circle4(circle2);
    cout << "radius" << circle4.getRadius() << endl;
    return 0;
}   // 메인함수의 지역변수와 파라미터는 stack 함수에 lifo로 입력됨 그리고 끝나면 pop 그래서 반대로 pop이 될때도 역순으로 실행됨