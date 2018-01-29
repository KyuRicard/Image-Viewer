#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <experimental/filesystem>

namespace NekoUtils
{
    enum class PrintColor
    {
        Red, Blue, Green, White, Yellow, Cyan, Magenta, Res, Count, Invalid
    };

    enum class PrintMods
    {
        None, Bold, Underline, Count, Invalid
    };

    const char * GetColor(const PrintColor& c)
    {
        #define o(e, c) case e: return c;
        switch(c) {
            o(PrintColor::Res,      "\x1B[0m" )
            o(PrintColor::Red,      "\x1B[31m")
            o(PrintColor::Green,    "\x1B[32m")
            o(PrintColor::Yellow,   "\x1B[33m")
            o(PrintColor::Blue,     "\x1B[34m")
            o(PrintColor::Magenta,  "\x1B[35m")
            o(PrintColor::Cyan,     "\x1B[36m")
            o(PrintColor::White,    "\x1B[37m")
            default: return "";
        }
        #undef o
    }

    const char * GetMods(const PrintMods& m)
    {
        #define o(e, c) case e: return c;
        switch(m)
        {
            o(PrintMods::Bold, "\x1B[1m")
            o(PrintMods::Underline, "\x1B[4m")
            default: return "";
        }
    }

    void PrintColor(const char * txt, PrintColor color, PrintMods mods = PrintMods::None)
    {
        std::cout << GetMods(mods);
        std::cout << GetColor(color);
        std::cout << txt;
        std::cout << GetColor(PrintColor::Res);
    }

    std::vector<std::string> Split(const std::string& str, char delim = ' ')
    {
        std::vector<std::string> vec;
        std::stringstream ss(str);
        std::string line;
        while (std::getline(ss, line, delim))
        {
            vec.push_back(line);
        }
        return vec;
    }

    std::string GetFileExtension(const std::string& file)
    {
        std::experimental::filesystem::path p(file);
        return p.extension().string();
    }
}