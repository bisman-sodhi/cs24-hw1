#include <iostream>
#include <cstdlib>
using namespace std;

class throttle{
    public:
        // MODIFICATION MEMBER FUNCTIONS
        void shut_off();
        void shift(int amount);
        // CONSTANT MEMBER FUNCTIONS
        double flow() const;
        bool is_on() const;

    private:
        int position;
};

int main(){

    throttle sample;
    int user_input;

    // Set the sample to user indicated position
    cout << "I have a throttle with 6 positions" << endl;
    cout << "Where would you like to set the throttle?" << endl;
    cout << "Please type a number from one to zero" << endl;
    cin >> user_input;
    sample.shut_off();
    sample.shift(user_input);

    //Shift the throttle to zero, printing out the flow along the way
    while(sample.is_on()){

        cout << "The flow is now " << sample.flow() << endl;
        sample.shift(-1);
    }

    cout << "The flow is now off" << endl;

    return 0;
}

void throttle::shut_off(){

    //Pre condition: None
    //Post condition: The throttle has been turned off

    position = 0;
}

void throttle::shift(int amount){
    //Pre condition: shut_off has been called at least once to initialize
    //Post conditino: The throttle's position has been moved at least once
    //but not below zero or above six

    position += amount;

    if (position < 0)
        position = 0;
    else if (position > 6)
        position = 6;
}

double throttle::flow() const{
    //Pre condition: shit_off has been called at least once to initialize
    //Post condition: The value returned is the current flow ratio flow/6

    return position / 6.0;
}

bool throttle::is_on() const{
    //Pre condition: shut_off has been called at least once
    //Post condition: If flow is above 0 then return true

    return (flow()> 0);
}