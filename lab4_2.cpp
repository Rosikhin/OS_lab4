// 9893, Росихин Александр, 
// Дисциплина ОС,
// Лабораторная работа №4.

/*
 Программа № 2
*/

#include <iostream>
//#include <pthread.h>
#include <unistd.h> // для sleep()
#include <sys/wait.h>

int main(int argc, char *argv[])
{
 std::cout << "Росихин, 9893, ОС, Лаба 4, Программа № 2.\n";
 std::cout << "Идентификатор свой: " << getpid() << "\n";
 pid_t pid = fork();
 if (pid==0)
 {
  std::cout << "Идентификатор дочернего: " << getpid() << "\n";
  std::cout << "Идентификатор родителя: " << getppid() << "\n";
  char *arg[] = {(char*)"14", (char*)"23", (char*)"-a", (char *)0};
  execve("lab4_1", arg, NULL);
 }
 else
 {
   int status;
   
   while (waitpid(pid, &status, WNOHANG) != pid)
   {
    std::cout << "ждем\n";
   
    usleep(500000);
   }
  
   std::cout << "Код завершения: : " << status << "\n";
  
 }
 

 return 0;
}
