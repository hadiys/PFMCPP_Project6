/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. there is only one reason for `compare` to return nullptr. Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>

struct T
{
    T(double pvalue, const char* pname) : value(pvalue), name(pname) {}  //1
    double value;   //2 
    std::string name;   //3
};

struct V                                //4
{
    T* compare(T* a, T* b) //5
    {
        if(a != nullptr && b != nullptr)
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }

        return nullptr;
    }
};

struct U
{
    float f1 { 0 }, f2 { 0 };
    float reduceDistance(float* newValue)      //12
    {
        if(newValue != nullptr)
        {
            std::cout << "U's f1 value: " << this->f1 << std::endl;
            this->f1 = *newValue;
            std::cout << "U's f1 updated value: " << this->f1 << std::endl;
            while( std::abs(this->f2 - this->f1) > 0.001f )
            {
                /*
                write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
                */
                this->f2 += 0.1f;
            }
            std::cout << "U's f2 updated value: " << this->f2 << std::endl;
            return this->f2 * this->f1;
            }

            std::cout << "ERROR: nullptr" << std::endl;
            return 0.f;
    }
};

struct StaticFunc
{
    static float reduceDistanceOfU(U* that, float* newValue )        //10
    {
        if(that != nullptr && newValue != nullptr)
        {
            std::cout << "U's f1 value: " << that->f1 << std::endl;
            that->f1 = *newValue;
            std::cout << "U's f1 updated value: " << that->f1 << std::endl;
            while( std::abs(that->f2 - that->f1) > 0.001f )
            {
                /*
                write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
                */
                that->f2 += 0.1f;
            }
            std::cout << "U's f2 updated value: " << that->f2 << std::endl;
            return that->f2 * that->f1;
        }
        
        std::cout << "ERROR: nullptr" << std::endl;
        return 0.f;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1(6.5, "t1");                                             //6
    T t2(8.7, "t2");                                             //6
    
    V f;                                            //7
    auto* smaller = f.compare(&t1, &t2);                              //8
    if(smaller != nullptr) 
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    
    U u1;
    float updatedValue = 5.f;
    std::cout << "reduceDistanceOfU() u1's multiplied values: " << StaticFunc::reduceDistanceOfU(&u1, &updatedValue) << std::endl;                  //11
    
    U u2;
    std::cout << "reduceDistance() u2's multiplied values: " << u2.reduceDistance(&updatedValue) << std::endl;
}
