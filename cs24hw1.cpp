#include <iostream>
#include <vector>

using namespace std;

class stat{
    public:
    stat(double a);
    stat();
    ~stat(); // destructor
    void setNum(double a);
    double getNum() const;
    void next_number(double a);
    int getlength();
    double getlast();
    double getsum();
    double getmin();
    double getmax();
    double getmean();
    void setlen(double a);
    void setlast(double a);
    void setsum(double a);
    void reset();
    //copy constructor
    stat(const stat& s);
    //assignment operator
    stat& operator=(const stat& s);
    // + operator
    stat& operator+(const stat& s);

    private:
    double sum, last, min, max, mean;
    int length;

};

int main(){

    stat mystat;
    mystat.next_number(8.7);
    mystat.next_number(3.2);
    mystat.next_number(17);

    stat s1{mystat};
    cout << "mystat len" << mystat.getlength() << endl;
    cout << "s1 len" << s1.getlength() << endl;

    stat cas;
    cas = mystat;

    cout << "cas min" << cas.getmin() << endl;

    stat pas;

    pas = mystat + cas;
    cout << "pas " << pas.getlength() << endl;

    mystat.reset();

    return 0;
}

//constructor
stat::stat(): length{0}, sum{0}, min{0}, max{0}, mean{0}, last{0}{

}
stat::stat(double a): length{1}, sum{a}, min{a}, max{a}, last{a}{

}
// copy constructor
stat::stat(const stat& s){
    last = s.last;
    sum = s.sum;
    min = s.min;
    mean = s.mean;
    length = s.length;
    max = s.max;
}

//assignmenet operator
stat& stat::operator=(const stat& s){
    last = s.last;
    sum = s.sum;
    min = s.min;
    mean = s.mean;
    length = s.length;
    max = s.max;
    return *this;
}

//+ operator
stat& stat::operator+(const stat& s){
    last += s.last;
    sum += s.sum;
    min += s.min;
    max += s.max;
    length +=s.length;
    mean += s.mean;
    return *this;
}

//destructor
stat::~stat(){}

void stat::next_number(double a){

    last = a;
    sum += a;

    if (length == 0){
        min = a;
        max = a;
    }
    else{
        if (a < min) {min =  a;}
        if (a > max) {max = a;}
    }
    length++;
    mean = sum/length;
}

int stat::getlength(){
    return length;
}

double stat::getlast(){
    return last;
}

double stat::getsum(){
    return sum;
}

double stat::getmin(){
    return min;
}

double stat::getmax(){
    return max;
}

double stat::getmean(){
    return mean;
}

void stat::reset(){
    this->length = 0;
    this->min = 0;
    this->max = 0;
    this->mean = 0;
    this->sum = 0;
    this->last = 0;
}




