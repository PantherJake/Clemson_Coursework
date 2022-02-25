#include <iostream>
#include <string>
#include <iomanip>

class testClass {
      private:
             int x;
             string testName;
             friend void demoClass::nameSet(aClass &c, int b);

 };

class OtherClass {
   public:
            void nameSet(aClass &c, int a) {  c.x = a;  }

};
