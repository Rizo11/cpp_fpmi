### 1.3 Types of errors and undefined behavior.
- __CE (compilation error, compile-time error)__
  - no ';'
  - using undeclared functions
  - double defining variable in the same scope
  - x++ = b+a : can't assign value to left hand-side arg, which is x++
  - Lexical errors
    - *lexical analysis*
    - Tokens
    - `(std) (::) (cout) (<<) (x) (;)`
    - `(std) vs. (std:)`
  - Syntatic errors
    - lack of `;`
  - Semantic errors
    - trying to do operations to objects which does not support that operation
    - referencing to undeclared vars(names)
    - ambiguous usage of variables
    - <img title="a title" alt="Alt text" src="lib/Screenshot from 2023-01-16 01-16-19.png">
  - error vs. fatal error : compiler stops analyzing when
  - it meets fatal error (e.g `#include <not_lib>`), but with error keeps analysing
- __RE (Runtime errors)__
  - Segmentation fault: referencing to the memory location that program don't have access
    - going too far from array bound
      - `int a[100]; a[10000000] = 1;`
    - infinite recursion
  - decimal zero division?? results in floating point exception
- __Undefined behavior__ (worst error)
  - going beyond array boundary
  - `int` overflow
- __Unspecified behavior__
  - <img title="a title" alt="Alt text" src="lib/Screenshot from 2023-01-16 02-07-31.png">
  - 12 or 21
  - `f() + g();`
  - `h(f(), g());`
- `g++ -O2 --std=c++17 test.cpp`
- `-O3` max optimizer
- `g++ -Werror --std=c++17 test.cpp` : treating warnings like error
- `-Wall` : warn about all warnings : `g++ -Wall --std=c++17 test.cpp`
- `-Wextra` : warn more
- `g++ -Werror -Wall -Wextra --std=c++17 test.cpp` : will not compile for even a smallest warning


### 1.4 Declarations, definitions and scopes.
- `type id [=init];`
- `type f_id(type1 id1, ... typen idn);`
- `struct S;`
- `class C;`
- `union U;`
- `namespace N {}`
- `alias`
  - `typedef new_name old_long_type_name;`
  - `typedef vvi vector<vector<int>>;` alternative `using vvi vector<vector<int>>;`
- definition : declare + define
- <img title="a title" alt="Alt text" src="lib/Screenshot from 2023-01-16 02-30-08.png">
- __One definition rule__ : define vars, functions only once. (You can declare as much as possible)
- scopes: global vs. local
  - `int x = 4; { int x = 5; std::cout << x; } std::cout<< x;`
  - `output: 54`
  - `std::cout << ::x` - referring to the global x
  - `std:cout << some_namespace::x` - referring to the variable from some_namespace
  - `using std::cout;` no `cout` can be used without `std::` in given scope
  - unqualified-id
    - `x`
  - qualified-id
    - `::x`


### 1.5 Basic types and supported operations
- statistically typed language : every var should have type and that type must be know during compilation
- static : compiletime
- dynamic : runtime
- basic types : 
  - int: usually 4 bytes [ - 2^31; 2^31)], 2'147'483'648
  - short - usually 2 bytes
  - long - usually 4 bytes
  - long long - usually 8 bytes [-2^63; 2^63) - 3ll
  - unsigned int [0; 2^32) - 4u
  - int32_t : guaranteed 32 bit sized int, int and long might not give exactly that size sometimes
  - int64_t
  - int128_t
  - uint32_t
  - uint64_t
  - using size_t = uint64_t ?? (unsigned)
  -----------------
  - float - usually 4 bytes - 0.4f
  - double = 2 * (mem of float) = 8 bytes. by default double in cpp
  - <img title="a title" alt="Alt text" src="lib/Screenshot from 2023-01-16 17-18-21.png">
  - long double = 16 bytes
  -------------
  - char : 1 byte number
  - signed/unsigned char
  - wchar16_t
  - wchar32_t
  -------------
  - bool : true/false, 1 byte
  - &&, ||, !=, ==, !
- linux command to find factors of a number: `factor 125`
- problem of 2039th year
- while casting from narrow to wider type, `int + short = int, int+long long = long long` **integer promotion**
- `int + unsigned int  = unsigned int`
- possible bug: imagine u have empty vector`some_vector.size()-1` : here size() returns unsigned and result will look like `unsigned int - unsigned int = 0 - 1 = 18446744073709551615`
- **foating point promotion**

- **std::string**
  - std::string s = "abcdefg";
  - s[1] = 'v';
  - s.size(); -> unsigned
  - s.substr(2, 3) => "bcd"
  - s + 'h' or 'i' + s or s+s or s += 'j';
- **std::vector**
  - `std;:vector<int> v(10);` default initialized with 0's
  - `v[5] = 3;`
  - `v.resize(20);`
  - `v.push_back(4);` adding 4 to the end of the vector and size+1
  - `v.pop_back();` will delete last element and size-1
  - `v.front();` first element
  - `v.back()`; last element
- **std::stack<int> st;**
- **std::queue<int> q;**
  - no resize and indexing
  - `st.push(0); st.pop();`
  - `st.pop();`
  - `q.front();`
  - `st.empty();` bool
- **std::set<int> set;**
- **std::unordered_set<int> uset;**
  - set of ordered elements
  - set.insert(4);
  - set.erase(2);
  - set.count(3);
  - s.size();
- **std::map<std::string, int> m;**
- **std::unordered_map<std::string, int> m;**
  - ordered
  - `m["aaa"] = 8;`
  - `m["aaa"] = 3;`
  - `m.size();` => 1
  - `std::cout << m["bb"];` // 0
  - `m.size();` => 2
  - `m.count("aaa");`
  - `m.empty();`
  
### 1.6 Expressions and operators
- **Arithmetic operators.** rvalue
  - + - * / %
- **Bitwise operators.** rvalue
  - & | ^ ~ << >>
    - 5 << 2 = 101
- **Logical operators.** rvalue
  - && || !
  ```
  int a = 0;
  int b = 1;
  if (a++ && b++) {
    // will not enter here
  }
  cout << a << " " << b; // 1 1

  b = 1;
  a = 0;
  if (b++ || a++) {
    // will not enter here
  }
  cout << a << " " << b; // 0 2

  if (i < v.size() && v[i] == 0) {

  }
  ```
- **Comparison operator** rvalue
  - `== != < > <= >=`
- **increment and decrement**
  - postfix in/decrement : a++ : in/decrements numbers and returns old value
  - prefix in/decrement : ++a : in/decrements numbers and returns new value
   - better to use `++i` than `i++` because it will take less space. `i++` will take more space
   - `++i` lvalue
   - `i++` rvalue
   - increment requires its args to be __lvalue__
   - `++x++` => CE
     - `++x++` parsed as `++(x++)` not `(++x)++`
     - `(x++)` returns rvalue
     - increment requires lvalue,thus CE
   - `(++x)++;` => works
   - `++++++x;` => works `++(++(++x));` prefix returns lvalue and increment requires its args to be lvalue
   - `+++++x;` => CE `++(++(+x));` unary `+` returns rvalue and increment requires its args to be lvalue
 - **Assignment and compound assignment.** right-to-left, lvalue
   - `+= -= *= /= %= &= |= ^= <<= >>=` : more efficient and take less space
   - assignment operator returns assigned value, for example `a = b` return `b`. Hence, we can use `a = b = c` <=> `a = (b = c)`
 ```
  a = 0; b = 1; c = 2;
  a = b = c;
  cout << a << " " << b << " " << c << endl;
 ```
- operator **sizeof()** rvalue
   - `int a = 0; sizeof(a); sizeof(int)`
   - is a static, the value if know during the compilation
   - `vector<int> v(100); sizeof(v);`
   - `sizeof()` from containers (`queue`, `vector` ...) is constant
   - `vector` saves:
     - size
     - current volume
     - pointer to array
     - allocator
   - `sizeof(vactor)` gives the total mem. size used by those fields of vector, but not the size of the array
   - `sizeof() does not calculate what is inside, rather it returns size of it`
     - `int a = 0; sizeof(a++);` value of `a` will not change
- **Ternary operator** r/lvalue depends on args
   - `condition ? when_true : when_false;`
   - `x = (condition ? a : b);`
   - `a` and `b` should be same type or close to each other and same r/lrvalue
   - `cout << (2 < 3 ? "sss" : "sssfdfd").size()` -> works
- **,(comma) Operator** r/lvalue depends on args
  - `int b = 2; x = (a = b, ++y, ++b);` `x` is equal to 3
  - `(a = b, c = d) = x;` => `c = x`
  - for sure in , operator will start from left to right, while it might not be true for arithmetic operators
- **Operator presedence** preoritet operatorov
  - <img title="a title" alt="Alt text" src="lib/Screenshot from 2023-01-18 07-26-44.png">
```
int x = 0;
++x = x++;
cout << x << endl;  //result is 0

std::cout << a & b; => (std::cout << a) & b;

*p++ => *(p++)
```
- Operators that have the same precedence are bound to their arguments in the direction of their associativity
  - `a = b = c` is parsed as `a = (b = c)`, and not as `(a = b) = c` because of right-to-left associativity of assignment.
  - `a + b - c` is parsed `(a + b) - c` and not `a + (b - c)` because of left-to-right associativity of addition and subtraction.
  - `a[1][2]++` is `((a[1])[2])++`
  - `a.b++` is `(a.b)++`
  - `delete ++*p` is `delete(++(*p))`
  - Precedence and associativity are compile-time concepts and are independent from order of evaluation, which is a runtime concept.
  - **Order of evaluation** poryadok vichisleniya
    - of any part of any expression, including order of evaluation of function arguments is unspecified (with some exceptions listed below). The compiler can evaluate operands and other subexpressions in any order, and may choose another order when the same expression is evaluated again.
    - no concept of left-to-right or right-to-left evaluation in C++
    - the expression `a() + b() + c()` is parsed as `(a() + b()) + c()` due to left-to-right associativity of operator`+`, but `c()` may be evaluated first, last, or between `a()` or `b()` at run time
  ```
  #include <cstdio>
  int a() { return std::puts("a"); }
  int b() { return std::puts("b"); }
  int c() { return std::puts("c"); }
  
  void z(int, int, int) {}
  
  int main()
  {
      z(a(), b(), c());       // all 6 permutations of output are allowed
      return a() + b() + c(); // all 6 permutations of output are allowed
  }
  // possible output: c b a a b c
  ```
  - **Concepts of lvalue and rvalue**
    - `(a, b) = 5;` => a = a, b = 5;
    - `a + b = 5;` => can't do in C++
    - `(2 < 3 ? ++x : x++) = 5;` => CE
    - `(2 < 3 ? ++x : x++);` => not error

### 1.7 Control statements
- `if (condition) statement;`
- `switch (expression) {`
  `case 1:`
    `statements...;`
    `break;`
  `case 5:`
    `statements...;`
    `break;`
  `default:`
    `statements...;`
  `}`
  
```
 for (int i = 0; i < n; i++) {
  do somth...;
 }
 do {

 } while (condition);

 while (condition) {

 }
 ```

## 2 Compound types

  ### 2.1 Pointers
- ***:** T\* :arrow_right: T (derefence)
- **&:** T :arrow_right: T*
- **+:** (T*, int) :arrow_right: T*
  - (int, T*) :arrow_right: T*
- **-:** (T*, T*) :arrow_right: ptrdiff_t (=int)
- :heavy_check_mark: (*pointer)++/-- number
- :heavy_check_mark: pointer - pointer
  ```
  double x = 3.14;
  double* p = &x;
  double* pp = p + 1;
  cout << pp-p << endl;
  // output: 1 (1 step difference between pp and p in memory)
  ```
- :x: number += pointer :arrow_right: **CE**
- :x: pointer + pointer
- `void* p` :arrow_right: pointer to the memory space where any type can be store
  - :x: *void_pointer because it is unclear what should be returned
  - can be casted to other pointer types
    - in C, malloc returns void* and it must be casted to other pointer type
    ```
    char *str;
    /* Initial memory allocation */
    str = (char *) malloc(15);
    ```
- `(T*) ++ -- += -=`
- `sizeof(pointer) = 8;`
- `std::cout << std:hex << x;` will print x in hex
- **nullptr** it is like zero but for pointer types
  - type: `nullptr_t`
  - can be casted to any type
  - `NULL` is a number constant, used to initialize number type variables
  - `nullptr` is a pointer constant, used to initialize pointer type variables
  
  ### 2.2 kinds of memory
- 
- **moemory**
  - any vriable stored in stack will live inside the scode of closest `{}`
- **static memory**
  - will be allocated at the beginning and variables inside static memory live until the end of the program
  - `static int x = 0;`
  - **static** variables initialized once and value will be saved
  - **global** variables also stored in static memory
  - for a program OS will allocate memory
  - [  data   |   text   |   stack ~ 4MB   ]
    - data: for static memory (static vars, global vars)
    - text: code of the program
    - stack: for variables, function calls
- **dynamic memory**
  - allocated at runtime
  - `int* p = new int(5);` returns pointer to the memory where 5 is stored
  - dynamic vars will be stored a long as we want or untill we `delete p;`
  - **memory leak**
    - when you allocated dynamic memory and forget to free it
  - deleting twice can cause to **segmentation fault** or **UB**
  
  ### 2.3 array
- arrays are similar to pointers but not the same
  - `int a[10];`
  - type of a is `int(*)[10]`
  - `int*p = a;` array to pointer conversion
    - `cout << *(p+2);` print 3rd element of array
    - `cout << p[2];` print 3rd element of array
    - `cout << a[2];` print 3rd element of array
    - `cout << *(a + 2);` print 3rd element of array
    - `cout << 2[a];` print 3rd element of array
  - `int* p = a+4;` adressing `p` to the 5th element of `a`
  - **array vs. pointers**
    - 1. you can assign pointer to pointer, but not array to array
      - :x: `int b[10] = a;`
      - :x: `int b[10]; a = b;`
    - 2. `sizeof(array)` will give you a total size of array, while `sizeof(pointer)` will give a size of a pointer, not what it points to
  - **dynamic array initializaiton**
    - `int* pa = new int[100];`
    - `delete[] pa;`
    - `new int[10]` vs. `new int(10)`
      - `new int[10]` create dynamic array with 10 elements and return pointer to it.
      - `new int(10)` create dynamic int variable with value 10 and return pointer to it.
    - :x: formally you can't do the following
    ```
    int n;
    cin >> n;
    int b[n];
    ```
    - :heavy_check_mark: you can do with dynamically allocated arrays
    ```
    int n;
    cin >> n;
    int* pa = new int[n]; 
    ```




  ### 2.4 functions
  - **function overloading**
    - signature of a function is its args, not what is returns
    - same name, but different args
    - `void f(int x);`
    - `void f(double x);`
    - `void f(char x);`
    1. exact match
    2. promotion
    3. built-in conversion (char -> int, double -> float)
    4. user-defined conversion
    - below code will give CE, because ambiguous call. It is ambiguous because _double => int_ and _double => float_ is same, and compiler doesn't know which version of `f()` to choose 
    ```
    void f(int x) {
        cout << "int arg: " << x << endl;
    }

    void f(float x) {
            cout << "float arg: " << x << endl;
    }
    int main() {
      double x = 1.3;
      f(a);  //ambiguous call!
    }
    ```
    - while choose function overcloads, compiler does not look at the return value, but only args(signature)