#include <iostream>

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

void clearscr() {
  std::cout << std::endl;
  system(CLEAR);
}

void waitInput() {
  getchar();
  std::cout << "Pressione enter para continuar...";
  getchar();
}
