#include <iostream> 
using namespace std;
class Complex {
    double real ;
    double img;
    public:
     
        Complex(double real=0 ,double img=0 ){
            
            this->real=real;
            this->img=img;
        }
        double getReal()const{
            return real;
        }

        double getImg()const{
            return img;
        }

        void setComplex(int real,int img){
            this->real=real;
            this->img=img;
        }
       
        void getComplex() const{
            //cout<<this->real<<this->real;
            if(real !=0){
                cout<<real;
            }
            if(img !=0 ){
                   if(img >0){
                        cout<<"+"<<img<<"j"<<endl;
                    }
                    else{
                        cout<<img<<"j"<<endl;
                    }
            }

        }

        Complex operator+ (const Complex & ob) const {
            
            return Complex(real+ob.real,img+ob.img);  //complex + complex
        }
        Complex operator+ (int x)const{
           
            return Complex(this->real+x,this->img);  // complex + int
        }

        Complex operator- (const Complex & ob) const {
            
            return Complex(this->real-ob.real,this->img-ob.img);  //complex - complex
        }

       Complex operator-(int x) const {
            return Complex(this->real - x, img);  //complex - int
        }

        Complex operator*(const Complex& ob) const {
            return Complex(real * ob.real , img * img); //complex * complex
                }
             
        Complex& operator+=(const Complex& ob){   //+=
            this->real += ob.real;
            this->img += ob.img;
            return *this;

        }

        Complex& operator-=(const Complex& ob){    //-=
            this->real -= ob.real;
            this->img -= ob.img;
            return *this;

        }

        Complex& operator*=(const Complex& ob){   // *=
            this->real *= ob.real;
            this->img *= ob.img;
            return *this;

        }
        
        bool operator==(const Complex& ob) const {  //==
        return (real == ob.real && img == ob.img);
        }

        bool operator!=(const Complex& ob) const { //!==
        return (real != ob.real || img != ob.img);
        }
        

        

        Complex & operator++(){    //prefix ++
            this->real++;
            this->img++;
            return *this;

        };

        Complex operator++(int){   //postfix ++
            Complex old=*this;
            this->real++;
            this->img++;
            return old;


        };

        Complex & operator--(){    //prefix  --
            this->real--;
            this->img--;
            return *this;

        };



        Complex operator--(int){   //postfix --
            Complex old=*this;
            this->real--;
            this->img--;
            return old;


        };

        

            
        friend ostream& operator<<(ostream& out, const Complex& c);
        friend istream& operator>>(istream& in, Complex& c);
        friend Complex operator+(int x, const Complex& c); 

      
};
// ostream& operator<<(ostream& out, const Complex& c) {
//     out << c.real << " + " << c.img << "j";
//     return out;
// }
ostream& operator<<(ostream& out, const Complex& c) {
    out << c.real;

    if (c.img > 0)
        out << " + " << c.img << "j";
    else if (c.img < 0)
        out << " - " << -c.img << "j";

    return out;
    };

istream& operator>>(istream& in, Complex& c) {
    cout << "Enter real part: ";
    in >> c.real;

    cout << "Enter imaginary part: ";
in >> c.img;

return in;
}
Complex operator+(int x, const Complex& c) {
    return Complex(x + c.real, c.img);
}
int main(){
    Complex c1(10, 20);
    Complex c2(5, 6);
    
    // Complex c3 = c1 + c2;
    // Complex c4 = c1 + 5; 
    // Complex c5;
    cout<<"complex + Integer = "<<c1 + 6<<endl;
    cout<<"complex + complex = "<<c1 + c2<<endl; 

    cout<<"complex - Integer = "<<c1 - 5<<endl;
    cout<<"complex - complex = "<<c1-c2<<endl; 
    
    cout<<"c1-- = "<<c1--<<endl;
    cout<<"c1++ = "<<c1++<<endl;
    
    cout<<"c1 * c2 = "<<c1 * c2<<endl;
    cout << "c1 += c2 = " << (c1 += c2) << endl;
    cout << "c1 -= c2 = " << (c1 -= c2) << endl;
    cout << "c1 *= c2 = " << (c1 *= c2) << endl;
    Complex c3, c4;

    cin >> c3;
    cin >> c4;

    cout << "C3 = " << c3 << endl;
    cout << "C4 = " << c4 << endl;

    cout << "C3 + C4 = " << c3 + c4 << endl;

    int x;
    cin>>x;
}