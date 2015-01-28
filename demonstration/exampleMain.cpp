#include <iostream>
#include <string>

int main(int argc, char * argv[]){

  // How many command line arguments dis we receive?
  std::cout << "argc = " << argc << std::endl;
  // What were those arguments?
  std::cout << "argv is an array of strings containing: \n";
  for(int argIndex = 0; argIndex < argc; ++argIndex){
    std::cout << argIndex << ": " << argv[argIndex] << '\n';
  }
  /* NOTE: You don't always have to use std::endl. In fact it's more efficient
   * not to because std::endl also FLUSHES THE OUTPUT STREAM, which is an
   * additional operation. Unless you actually want to flush the stream just
   * insert a '\n' (newline) character into the output stream using the 
   * STREAM OUTPUT OPERATOR "<<".
   * 
   * It is also possible to just flush the output stream, without also 
   * appending a newline using std::flush e.g.
   */
  std::cout << std::flush;
  
  return 0; // By convention return 0 on success!
}
