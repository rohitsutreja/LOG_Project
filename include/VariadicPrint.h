#ifndef PRINT_H
#define PRINT_H

void print() {}

template <typename T, typename... Types>
void print(T first, Types... args)
{
            std::cout << first << " ";
            print(args...);
}

#endif