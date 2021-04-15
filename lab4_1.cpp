// 9893, Росихин Александр, 
// Дисциплина ОС,
// Лабораторная работа №4.

/*
 Программа № 1
*/

#include <iostream>
//#include <pthread.h>
#include <unistd.h> // для sleep()


int main(int argc, char *argv[])
{
 std::cout << "Росихин, 9893, ОС, Лаба 4, Программа № 1.\n";
 
 std::cout << "Идентификатор процесса: " << getpid() << "\n";
 std::cout << "Идентификатор родителя: " << getppid() << "\n";
 
 for (int i = 0; i < argc; ++i)
 	{
        std::cout << "Аргумент № " << i << " =  " << argv[i] << "\n";
        usleep(500000);

	}
 return 0;
}
