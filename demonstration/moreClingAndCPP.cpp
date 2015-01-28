// LECTURE 3 C++ DEMONSTRATION

// RECAP - CODE BLOCKS AND VARIABLE SCOPING
// ========================================
// Recall that a code block is simply defined as any section of your program
// that lies bewteen a pair of braces e.g. loop bodies, if-then-else clauses
// The following snippet recapitulates some implications of this.

// Recall: The iostream header file must be included to enable output to the
// terminal.
#incude <iostream>
double doubleVar{2.5}; // (1a). NOTE: UNIFORM INITIALIZATION SYNTAX
// This integer declaration/initialization is outside the code block.
int intVar(1); // (1b). NOTE: CONSTRUCTOR INITIALIZATION SYNTAX
std::cout << intVar << std::endl; // outputs: 1

{ // This brace starts the code block
  // This integer declaration/initialization is inside the code block.
  int intVar(2); // (2)
  std::cout << intVar << ", " << doubleVar << std::endl; // outputs: 2, 2.5
} // this brace closes the code block

std::cout << intVar << std::endl; // outputs: 1

// RECALL: A code block defines a local scope, so any identifiers that
// are declared within a code block are not defined after the block has closed.

// RECALL: Identifiers that are declared in enclosing scopes retain their
// interpretations within a (UNNAMED) code block unless they are re-declared.

// RECALL: If an identifier is re-declared (2) within a code block with THE
// SAME NAME as an identifier that has ALREADY been declared in an
// ENCLOSING SCOPE (1a) then it will refer to a DIFFERENT ENTITY.

// Any use of that identifier within the code block will reference the LOCALLY
// declared entity (2). This is known as VARIABLE SHADOWING and SOME compilers
// will warn you if you do this. Once the code block is closed. The LOCALLY
// declared entity (2) will cease to exist, and subsequent uses of the
// identifier will refer to the idenifier declared at (1a).

// FUNCTIONS:
// ==========
// Functions in C++ are NAMED CODE BLOCKS i.e. code blocks that are associated
// with an identifier.
// They are generally used to isolate segments of your code that perform a
// specific task (or function!).
// Associating an identifier with a code block allows the programmer to re-use
// the code within the block by simply refering to it using the identifier.
// This is known as CALLING the function.

// FUNCTION DECLARATIONS:
// ======================
// The following snippet illustrates the SYNTAX that is required to DECLARE
// a simple function in C++. NOTE the comment that explains the purpose of the
// function and the meaningful function and parameter identifiers!

// This function converts an angle specified in degrees into radians. 
double degreesToRadians(double angleInDegrees);

// This declaration comprises several tokens. The most general form of a
// function declaration is:
//  (1)            (2)                 (3, PARAMETER LIST)
RETURN_TYPE FUNCTION_IDENTIFIER(PARAMETER1_TYPE PARAMETER1_IDENTIFIER,
				PARAMETER2_TYPE PARAMETER2_IDENTIFIER
				//, ... MORE PARAMETERS ...
				);
// (1)
// Functions may compute a RETURN VALUE and INJECT it back into the enclosing
// scope. The first token in the function declaration specifes the TYPE of that
// return value.
// (2)
// The second token specifies the IDENTIFIER that will be used to CALL the
// function in subsequent code.
// (3)
// Functions can be CALLED at arbitrary points within your code. For this
// reason, it does not make sense for identifiers that are declared in the 
// enclosing scope to be injected into the function body. Instead, the values
// of variables that are defined in enclosing scope that are required by code
// in the code block that will DEFINE the FUNCTION BODY must be passed as
// PARAMETERS. Parameters are specified as a perenthesized list of pairs of
// TYPE SPECIFIERS and IDENTIFIERS. The number of allowed parameters is
// (practically) unlimited.

// SIGNATURES AND OVERLOADING:
// ===========================
// The combination of the FUNCTION_IDENTIFIER and the TYPE_SPECIFIERs in the
// PARAMETER LIST, but NOT the RETURN_TYPE, NOR the PARAMETER IDENTIFIERs
// is called the function SIGNATURE. In C++ only functions with IDENTICAL
// signatures are considered to be identical. This means that MULTIPLE
// functions can be defined WITH THE SAME identifier as long as they have
// DIFFERENT PARAMETER TYPES. This is called FUNCTION OVERLOADING. There
// is an example of this later in the demonstration.

// NOTE: In C++, there is no limit to the number of times that  a function may
// be DECLARED. However the function body MUST be DEFINED EXACTLY ONCE.

// FUNCTION DEFINITIONS:
// =====================
// A function DEFINITION is simply a function DECLARATION followed immediately
// by a code block containing the function definition e.g.

// NOTE: If you want to try writing a function in Cling, you MUST first enable
// RAW INPUT mode by entering ".rawInput" before you start your function
// definition and again once you have finished to disable the mode. This is NOT
// required for complied C++ code.

// Including the "cmath" header file enables access to several commonly
// required mathematical functions (e.g. sin(), cos()) and constants
// (e.g. the value of pi which is given the identifier M_PI)
#include <cmath> 

.rawInput  // Only needed in Cling interpreter
// This function converts an angle specified in degrees into radians. 
  double degreesToRadians(double angleInDegrees){
  // Note the use of the M_PI constant defined by the cmath header to compute
  // the angle in radians. The statement refers to the parameter identifier
  // "angleInDegrees".
  double angleInRadians = angleInDegrees*(M_PI/180.0);
  // The "return" keyword is used to specify the value that a function returns
  // to the scope from which it was called.
  return angleInRadians;
} // NOTE: No semicolon is required - although it would not be an error.
.rawInput  // Only needed in Cling interpreter


 // CALLING FUNCTIONS:
 // ==================
 // Once a function has been DEFINED, it can be called. The following snippet
 // illustrates the FUNCTION CALL SYNTAX:

 // Declare and initialize a double precision variable to represent the angle
 // in degrees.
double degrees = 25.0;

// Call the degreesToRadians(double) function to compute the angle in radians
//   (1)       (2)      (3)          (4)
double radians = degreesToRadians(degrees);

std::cout << degrees << " degrees => " << radians << std::endl;

// To call the function:
// (1) Optionally delare a new variable to recieve the function return value.
// (2) Use the assignment operator to assign the return value to the newly
//     declared variable.
// (3) Use the FUNCTION_IDENTIFIER to invoke the code defined within the
//     function body.
// (4) Use the identifier of a variable that is declared (and has been
//     initialized!) in the scope from which the function is called, to
//     supply a value that will be assigned to the angleInDegrees identifier
//     within the function body. When used in a function call statement,
//     this identifier is called an ARGUMENT. Its value will be bound to the
//     PARAMETER from the functions's definition.

// NOTE: In this case the argument value is passed by VALUE. This means that IF
// the function body modified the value of angleInDegrees, the value of degrees
// would not be changed when the function returns. Later we will see how to
// pass function arguments by REFERENCE, in which case modifications made
// within a function persist upon function return.

// ARRAYS:
// =======
// So far we have seen how to declare simple numeric and character types. The
// most complicated type we have seen is the std::string type, and this has not
// been fully explained yet.

// The concept of an array is common to almost all computer programming
// languages. In C++ an array is a collection of a FIXED number of programatic
// entities with THE SAME TYPE. The syntax that is required to DECLARE an array
// is similar to the syntax that is required to declare a simple variable e.g.

// This statement declares an array of 5 double precision real numbers.
double arrayOf5Doubles[5];

// The key difference between this array declaration and the declaration of a
// simple double variable is the [5] token. This specifies the SIZE of the
// array i.e. the number of double precision variables or ELEMENTS is can
// contain.
// NOTE: the [5] token is NOT part of the array's IDENTIFIER.
// NOTE: the size of an array MUST be specified upon declaration and is FIXED
//       thereafter.

// IF an array is initialized WHEN IT IS DECLARED then the following syntax
// can be used:

double arrayOf3Doubles[3] = {1.0, 2.0, 3.0};

// The value of ALL the ELEMENTS of the array MUST be specified as a comma-
// separated list of literals or correctly typed identifiers between a pair
// of braces.
// NOTE: In this case the braces do not define a code block - this is an
// example of tokens assuming a context-dependent meaning.

// Once an array has been declared (and possibly also initialized), the only
// way to modify the values of its elements is to access them individually.
// This is called INDEXING and array and is achieved using the following
// syntax:

// Access the first element of an array using an integer INDEX that specifies
// the desired position in the array.
// NOTE: In C++ arrays are zero-indexed. that means that the first element has
// index 0, the second element has index 1, etc.
double firstElement = arrayOf3Doubles[0];

// The array indexing syntax involves a token that looks very similar to the
// size specification that is part of an array's TYPE SPECIFIER. In this
// context, it is called the INDEXING OPERATOR and the number between the
// square brackets is the operator's ARGUMENT.

// It is also possible to assign a new value to a particular array element
// using the indexing operator:

arrayOf5Doubles[3] = 13.0;

// The argument can also be an integer variable. This means that it is
// possible to loop over the elements of an array e.g.

// loop over all 5 elements of the array and print a tab-separated list
// of values. QUESTION: Why do I prefer the preincrement operator?
for(int index = 0; index < 5; ++index){
  std::cout << arrayOf5Doubles[index] << "\t";
  // std::endl appends a newline and flush the output stream.
  std::cout << std::endl;
 }

// POINTERS:
// =========
// Warning! Pointers often confuse people the first time that they encounter
// them. Don't panic - conceptually they're actually really simple.

// A POINTER is simply an INTEGER with a value that REPRESENTS A MEMORY
// ADDRESS.

// Why are pointers useful? When used properly, they minimize the amount of
// memory that our program uses and avoid coputationally expensive data copying
// operations, which helps our programs run faster. Pointers also allow
// functions to PERSISTENTLY modify the value of variables that are declared at
// the scope from which the function was called. This is because pointer refers
// directly to the memory where the argument's data are stored. By modifying
// the value stored in this memory, the function is able to influence the
// flow of execution outside of its local scope. Sometimes this is desirable.
// Houwever, this can also be a cause of unexpected bugs, so beware!

// DECLARING POINTERS:
// ===================

// To DECLARE A POINTER use the "*" token. The following statement binds the
// IDENTIFIER pointerToDouble to a POINTER (recall that this is really just
// an integer that refere to an ADDRESS in memory) at which a double-precision
// real number is stored.
double * pointerToDouble;

// NOTE: The * token is part of the pointer's TYPE SPECIFIER.
// At this point, NO MEMORY TO STORE THE VALUE HAS BEEN ALLOCATED.
// If we care, we can inspect the value of the pointer itself.

std::cout << pointerToDouble << std::endl;

// Cling will print 0. This is the memory address of a NULL POINTER. This
// address cannot be accessed by your program. Usually it is reserved for the
// operating system's kernel or similar. We need to explicitly ALLOCATE MEMORY
// for a double precision variable and assign the address of that ALLOCATED
// MEMORY to our pointer. We do this using the "new" OPERATOR e.g.

// The new operator will allocate the appropriate number of bytes of memory to
// store a variable with the TYPE specified by its argument and return the
// address of the FIRST BYTE of the allocated memory.
pointerToDouble = new double;
// Check that pointerToDouble is no longer 0. Instead, Cling prints a
// hexadecimal representation of the integer that specifies the memory address.
std::cout << pointerToDouble << std::endl;

// But we have still not assigned a value to the memory that has been allocated
// at the moment its bits are in an undefined state. Some compilers might be
// kind and zero-initialize them, but YOU SHOULD NOT NELY ON THIS!

// DEREFERENCING POINTERS:
// =======================
// Accessing the VALUE that is stored at the memory address to which a
// pointer's integer value refers is called DEREFERENCING the pointer.
// The syntax for dereferencing a pointer ALSO makes use of the "*" token.
// NOTE: The meaning of tokens in C++ is often very CONTEXT-DEPENDENT. Sorry!
// When the identifier that has been bound to a pointer is prepended with the
// "*" token, then the "*" is interpreted as the DEREFERENCE OPERATOR which
// returns the VALUE of the memory at the address to which the pointer's
// integer value refers INTERPRETED ACCORDING TO THE TYPE that the pointer
// was declared to have.

// Let's dereference our newly allocated pointer and see how the bytes we've
// allocated are interpreted as a double precision real number. 

double valueOfDouble = *pointerToDouble;
std::cout << valueOfDouble << std::endl;

// You can also assign a value to the memory we have allocated using the
// dereference operator e.g.

*pointerToDouble = 2015.0;
std::cout << *pointerToDouble << std::endl;

// QUESTION: What is the value of valueOfDouble now? 

// POINTERS TO ARRAYS:
// ===================
// So far, it probably seems like pointers just add another layer of useless
// complication. Indeed, for simple numeric variables, that's probably true!
// The real power of pointers arises when dealing with arrays.

// Consider the following statament:
// (1)              (2)        (3)(4)    (5)  (6)
long int * arrayOf5LongIntegers = new long int[5];

// There's a lot of things happening here and some might be surprising. Let's
// investigate.
// (1) Perhaps surprisingly we begin by declaring a pointer to a single long
//     integer i.e. there is no size specifier. This will make more sense as
//     we think about the rest of the statement.
//     NOTE: The TYPE of a POINTER to an ARRAY of variables of a specific type
//           is IDENTICAL to the TYPE of a POINTER to a single variable of that
//           type.
// (2) The declared pointer is bound to an identifier "arrayOf5LongIntegers".
// (3) The assignment operator is used to assign the address returned by an
//     invokation of the new operator (4).
//     RECALL that the new operator returns the address of the FIRST byte of
//     memory that it allocates. Now the fact that arrayOf5LongIntegers is
//     bound to a POINTER to a single long integer makes more sense. The data
//     that resides at the address referred to by the pointer's value does
//     indeed correspond to a single long integer value.
// (5) Technically we are in fact using the "new[]" operator to allocate the
//     memory for our array. Unlike the "new" operator, the "new[]" operator
//     actually takes two arguments. The first argument is the TYPE (5) of the
//     variables that will comprise the array.
// (6) The second argument is the size of the array that should be allocated.

// INDEXING ARRAYS ALLOCATED USING NEW:
// ====================================
// Here comes the first bit of good news. If you want to index an array that
// was declared using new[], you DO NOT NEED TO EXPLICITLY DEREFERENCE IT.
// Instead, you can just use the normal indexing operator. So the following
// code will loop over all elements of the allocated array and assign values to
// them.

for(int index = 0; index < 5; ++index){
  arrayOf5LongIntegers[index] = 2 + index*index;
 }

// Likewise the newly assigned values can be output to the terminal using:

for(int index = 0; index < 5; ++index){
  std::cout << arrayOf5LongIntegers[index] << std::endl;
 }

// PASSING ARRAYS TO FUNCTIONS:
// ============================
// Recall that simple variables are passed BY VALUE when they are used as
// function arguments. ARRAYS CANNOT BE PASSED BY VALUE in C++. They are
// ALWAYS passed as pointers to their first elements. Why? Passing by value
// involves copying the data from memory associated with the in which the
// function was called into memory allocated the scope of the function body.
// For a large array, this entails duplicating a lot of data and performing
// a large number of copy operations. In contrast, a pointer is a single
// integer value and reuires a single lightweight copy operation.
// In fact, many modern compilers can avoid performing any data copy when
// simple variables and pointers are passed by value.

// A VERY IMPORTANT CONSEQUENCE of this fact is that IF a function modifies
// the values of an array that is passed as an argument then the modifications
// will PERSIST AFTER THE FUNCTION RETURNS.

.rawInput // Only needed in Cling interpreter
// This function increements the elements of an array of long integers.
// It illustrates that arrays are passed as pointers and the mutations will
// persist after the function returns.
void arrayMutator(long int  array[], int arraySize){
  for(int index = 0; index < arraySize; ++index){
    array[index]++;
  }
}

// This function increements the elements of an array of characters.
// Note that we have OVERLOADED the function.
void arrayMutator(char array[], int arraySize){
  for(int index = 0; index < arraySize; ++index){
    array[index]++;
  }
}

// This function prints the values of all elements in an array of long integers
// as a space-separated list.
void arrayPrinter(long int array[], int arraySize){
  for(int index = 0; index < arraySize; ++index){
    std::cout << array[index] << " ";
    // Again, append a newline and flush the output stream.
    std::cout << std::endl;
  }
}

// This function prints the values of all elements in an array of characters
// as a space-separated list. Note that we have OVERLOADED the function.
void arrayPrinter(char array[], int arraySize){
  for(int index = 0; index < arraySize; ++index){
    std::cout << array[index] << " ";
    // Again, append a newline and flush the outflut stream.
    std::cout << std::endl;
  }
}
.rawInput  // Only needed in Cling interpreter

// Print the initial values of the array elements
arrayPrinter(arrayOf5LongIntegers, 5);
//Mutate the values of the array elements by adding 1 to each.
arrayMutator(arrayOf5LongIntegers, 5);
// Print the utimate values of the array elements
arrayPrinter(arrayOf5LongIntegers, 5);

// What if the array had not been allocated using the new[] operator e.g.
char mysteryCharsArray[16] = { 0x75, 0x64, 0x71, 0x78, 0x1f, 0x6b, 0x60, 0x71, 0x66, 0x64, 0x1f, 0x60, 0x71, 0x71, 0x60, 0x78 };
// Note that characters are really 8-bit integer types, and can be assigned accordingly

// Print the initial values of the array elements
arrayPrinter(mysteryCharsArray, 16);
//Mutate the values of the array elements by adding 1 to each.
arrayMutator(mysteryCharsArray, 16);
// Print the utimate values of the array elements - Even though the array was
// NOT declared as a pointer is WAS PASSED AS ONE AND HAS BEEN MUTATED.
arrayPrinter(mysteryCharsArray, 16);

// FREEING ALLOCATED MEMORY:
// =========================
// Memory that is allocated for variable storage using the new or new[]
// operators is NOT DEALLOCATED AUTOMATICALLY. If you do not explicitly
// deallocate the memory that a pointer refers to before the scope with which
// its identifier is associated expires, then a MEMORY LEAK is said to have
// occured. THERE IS NO WAY TO DEALLOCATE THE MEMORY ONCE THIS HAS HAPPENED!
// If a (badly written) program leaks too much memory, it can exhaust the
// system's resources and (hopefully) your program will crash.

// Memory that has been allocated using the new operator should be deallocated
// using the delete operator e.g.

delete pointerToDouble;

// Memory that has been allocated using the new[] operator shold be deallocated
// using the delete[] operator e.g.

delete[] arrayOf5LongIntegers;

// NOTE: There is no need to specify the size of the array when using
//       the delete[] operator. Secretly, the compiler "knows" how much memory
//       it needs to deallocate!

// Once you have deallocated the memory it is important to realize that the
// integer value of your pointer variable STILL REFERS TO THE ADDRESS WHERE
// THE MEMORY HAD BEEN ALLOCATED. Accidentally trying to access this memory
// ofter it has been deallocated has undefined results. For this reason it
// is GOOD PROGRAMMING PRACTICE to explicitly set the value of deleted pointers
// to 0. This is done by assigning the special nullptr value (or NULL for
// older compilers e.g.

pointerToDouble = nullptr;
arrayOf5LongIntegers = nullptr;

// OR

pointerToDouble = NULL;
arrayOf5LongIntegers = NULL;

// REFERENCES:
// ===========
// Pointers were inherited by C++ as a legacy from its ancestor language C.
// With the advent of C++ a new type of variable was introduced called a
// REFERENCE was introduced.
// References, provide much of the functionality that was previously achieved
// using pointers USING A MUCH MORE STRAIGHTFORWARD SYNTAX!
// Like pointers, references can be used to avoid data duplication and
// expensive memory-copy operations. Like pointers, references can be used to
// enable functions to persistently modify the values of reference-type
// variables that are passed as arguments.

// References can be understood as a SPECIAL TYPE OF IDENTIFIER that provides
// an ALIAS for a PREEXISTING variable.

// This implies an important distinction beween references and pointers:
// THERE IS NO SUCH THING AS A NULL REFERENCE.
// This means that ALL references MUST BE INITIALIZED with as an alias of a
// preexitsing variable WHEN THEY ARE DECLARED.
// A (mutable) reference CANNOT be initialized using a LITERAL value.

// A reference is declared using the "&" token e.g.

bool booleanVar = true; // A normal boolean variable
bool & referenceToBooleanVar = booleanVar; // A reference ALIASING booleanVar

// It is IMPORTANT to realize the previous statement DOES NOT assign the VALUE
// of booleanVar to referenceToBooleanVar. Rather it specifies that the
// IDENTIFIER referenceToBooleanVar should now REFER TO (or ALIAS) THE SAME
// data that booleanVar refers to.
// In other words, reference-type variables do NOT reference their OWN
// associated data. Instead, they reference the data of the normal variable
// that they alias.

// A very common idiom in C++ is to define function parameters as references.
// An example function with reference-type parameters might be e.g.

.rawInput // Toggle Cling's raw input mode.
void nextSongLine(std::string & stringPar, int & intPar){
  // Output the initial argument values to the terminal
  std::cout << "String => "     // Note that whitespace is ignored in C++...
	    << stringPar        // ... so you can spread out your code...
	    << ", Integer => "  // ... and make it easier to understand!
	    << intPar
	    << std::endl;

  // Modify the values of the arguments.
  // NOTE: No dereferencing is needed. You can treat references just like
  //       normal variables.
  if(intPar == 1){
    stringPar = "I say po-tah-to!";
    intPar = 2;
  }
  else{
    stringPar = "Can't remember the next line!";
    intPar = 0;
  }
  // Output the modified argument values to the terminal
  std::cout << "String => "     // Note that whitespace is ignored in C++...
	    << stringPar        // ... so you can spread out your code...
	    << ", Integer => "  // ... and make it easier to understand!
	    << intPar
	    << std::endl;
}
.rawInput

// Calling a function that accepts reference parameters is also just like
// calling a function that accepts normal VARIABLES as parameters.
// The arguments are said to be PASSED BY REFERENCE. Modifications that a
// function makes to arguments that are passed by reference can DIRECTLY
// AFFECT the data corresponding to the normal variable that they alias.
// In other words, passing by reference allows functions to modify variables
// that are defined in the scope from which the function is called.

// NOTE: The arguments do not need to be references themselves... 
std::string songLine("I say po-tay-to!");
int songLineNum(1);
// but they may be.
int & referenceSongLineNum(songLineNum); // constructor-style initialization

std::cout << referenceSongLineNum << ": " << songLine << std:: endl;

// try to get the next song line.
nextSongLine(songLine, referenceSongLineNum);

// QUESTION: What does this statement output?
std::cout << referenceSongLineNum << ": " << songLine << std:: endl;

// However, it is not legal C++ to pass a LITERAL value to a function expecting // a (mutable) reference parameter. So the following is illegal:

nextSongLine(songLine, 3); // attempt to pass a literal integer as int& fails.

// NAMESPACES:
// ===========
// C++ defines the concept of a NAMESPACE. Namespaces define a NAMED SCOPE
// that is similar to the global scope. You could usefully think of them as
// a way to partition (or slice up) the global namespace.

// IDENTIFIERS WITH THE SAME NAME that are defined within different namespaces
// have distinct interpretations. This saves programmers having to invent
// unneccesarily contrived identifier names.

// Namespaces are typically used in large projects to segregate different
// parts of the source code.

// Namespaces are defined using the "namespace" keyword followed by
// an IDENTIFIER and a CODE BLOCK containing arbitrary C++ code e.g.

namespace Iowa { // start of namespace scope

  int landArea = 145743; // square km
  // In the Iowa namespace the getCapital IDENTIFIER refers to a function
  std::string capital(){
    return "Des Moines"; // returning a literal
  }
} // end of Iowa namespace scope. Now back in the global scope.

namespace UnitedKingdom {  // start of another namespace scope

  int landArea = 243610; // square km 
  // In the UnitedKingdom namespace the getCapital IDENTIFIER refers to a
  // variable. The use of namespaces prevents it from clashing with the
  // function definition in the Iowa namespace.
  std::string capital = "London";
  
} // end of UnitedKingdom namespace scope. Now back in the global scope.

// To refer to identifiers that are declared within a namespace, use the
// SCOPE RESOLUTION OPERATOR "::" e.g.

std::cout << "The capital of Iowa is: "
<< Iowa::capital() << std::endl;

std::cout << "The capital of the UK is: "
<< UnitedKingdom::capital << std::endl;

// Hopefully you've realized that we've been using identifiers that are defined
// within a namespace for some time now. The namespace we've been using is the
// "std" namespace. The "std" namespace is RESERVED for identifiers that are
// defined by the C++ STANDARD LIBRARY and the C++ STANDARD TEMPLATE LIBRARY.
// See Lecture 4 for more information about these libraries.

// The SCOPE RESOLUTION OPERATOR can also be used to explicitly refer to the
// global namespace by using it with NO IDENTIFIER ON THE LEFT.
int landArea = 148429000; // Global land area (square km)

std::cout << "Global: " << landArea
<< "\nExplicitGlobal: " << ::landArea
<< "\nUnited Kingdom: " << UnitedKingdom::landArea
<< "\nIowa: " << Iowa::landArea
<< std::endl;

