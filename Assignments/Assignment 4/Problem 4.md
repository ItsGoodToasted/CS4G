1. It outputs the variable values that int main() and void someFunction have access to.

2. Scope in programming is the visibility within a program. Variable a is declared at file scope. Everything has access. With the variable b, it exists both in main and someFunction, but not with the same assigned value. They are independent b variables restricted to their respective function.
3.  The a variable is at file scope, where as two distinct b variables are within the main() and someFunction functions. The c variable exists only in main.

4. No, but the function could be called within main and fed the variable if it weren't void.

5. You're god damn right it can. Everyone has access to a.

6. Local. 

7. We can't. It's in a closed room we can't access. It may as well not exist to us.

8. Declare the variable outside of the functions at a global scope.

9. Limiting dependency in the code. Things related to function f(x) should stay with f(x). f(y) could have identical variables with different data. Bad data in f(x) would not effect f(y).

