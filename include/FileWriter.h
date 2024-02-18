#pragma once

#include <iostream>
#include<string>
#include<fstream>
#include "String.h"
using namespace std;

namespace Util{
    class FileWriter {

    public:
        FileWriter(Util::String name) : fName{ name }, out{ name.getCStyleString(), ios::app } {
        }

        void writeLine(Util::String line) {
            out << line;
        }


    private:
        Util::String fName{ "" };
        ofstream out{};
    };
}