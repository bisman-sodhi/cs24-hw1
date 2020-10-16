#include <iostream>
#include <vector>

using namespace std;

class stat{
    public:
    stat(double a);
    stat();
    // constructor
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
    private:
    //int num;
    double sum;
    int length;
    double last;
    double min;
    double max;
    double mean;
    //vector<int> seq;
};

    //vector<int> seq;


int main(){

    cout << "start of mystat" << endl;
    stat mystat;
    mystat.next_number(8.7);
    mystat.next_number(3.2);
    mystat.next_number(17);
    cout << "len" << mystat.getlength() << endl;
    cout << "min" << mystat.getmin() << endl;
    cout << "max" << mystat.getmax() << endl;
    cout << "last" << mystat.getlast() << endl;
    cout << "sum" << mystat.getsum() << endl;
    cout << "mean" << mystat.getmean() << endl;


    return 0;
}

//constructor
stat::stat(): length{0}, sum{0}, min{0}, max{0}, mean{0}, last{0}{


}
stat::stat(double a): length{1}, sum{a}, min{a}, max{a}, last{a}{

}

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


stat::~stat(){}


