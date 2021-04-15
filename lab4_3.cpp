// 9893, Росихин Александр, 
// Дисциплина ОС,
// Лабораторная работа №4.

/*
 Программа № 3
*/

#include <iostream>
//#include <pthread.h>
#include <unistd.h> // для sleep()
#include <sys/wait.h>


static int childFunc(void *arg)
{
  std::cout << "Идентификатор дочернего (3): " << getpid() << "\n";
  std::cout << "Идентификатор родителя(3): " << getppid() << "\n";
  char *arg2[] = {(char*)"1", (char*)"2", (char*)"-b", (char *)0};
  execve("lab4_1", arg2, NULL);
  
  return 0;
}

int main(int argc, char *argv[])
{
 std::cout << "Росихин, 9893, ОС, Лаба 4, Программа № 3.\n";
 std::cout << "Идентификатор свой (3): " << getpid() << "\n";
 
 #define STACK_SIZE 1024*1024
 char *stack;
 char *stackTop;
 
 stack = (char*)malloc(STACK_SIZE);
 stackTop = stack + STACK_SIZE;
 
 pid_t child_pid = clone(childFunc, stackTop, SIGCHLD, NULL);
 
 int status;
 
 while (waitpid(child_pid, &status, WNOHANG) != child_pid)
   {
    std::cout << "ждем\n";
   
    usleep(500000);
   }
   
   std::cout << "Код завершения: : " << status << "\n";
 
 return 0;
}
