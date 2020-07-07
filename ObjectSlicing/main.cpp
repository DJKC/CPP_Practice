#include <vector>
#include <iostream>
#include <functional>
	
class Base{
    protected:
        int m_value;

    public:
        Base(int value) : m_value(value){}

        virtual const char* getName() const {return "Base";}
        int getValue() const {return m_value;}
};
 
class Derived: public Base{
    public:
        Derived(int value) : Base(value){}

        virtual const char* getName() const {return "Derived";}
};

int main(){
//    /////////////Wrong Way because derived gets set to base and extra derived variables are "sliced off"
//    std::vector<Base> x;
//    x.push_back(Base(5)); // add a Base object to our vector
//    x.push_back(Derived(6)); // add a Derived object to our vector
    
    /////////////Right Way
    std::vector<Base*> v;

    Base b(5); // b and d can't be anonymous objects
    Derived d(6);

    v.push_back(&b); // add a Base object to our vector
    v.push_back(&d); // add a Derived object to our vector

    // Print out all of the elements in our vector
    for(int count = 0; count < v.size(); ++count){
            std::cout << "I am a " << v[count]->getName() << " with value " << v[count]->getValue() << "\n";}

    ////////////Another Way
    Base bb(5);
    Derived dd(6);
    
    std::vector<std::reference_wrapper<Base>> vv;
    
    vv.push_back(bb);
    vv.push_back(dd);
    
    for (int count = 0; count < vv.size(); ++count){
        std::cout << "I am a " << vv[count].get().getName() << " with value " << vv[count].get().getValue() << "\n";}
    
    return 0;
}