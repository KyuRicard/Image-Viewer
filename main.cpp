#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Display.hpp"

#include "utils.hpp"

const char * progname; 

int main(int argc, char * args[])
{
	progname = args[0];
	if (--argc == 0)
	{
		std::cout << progname << ": ";
		NekoUtils::PrintColor("error:", NekoUtils::PrintColor::Red, NekoUtils::PrintMods::Bold);
		std::cout << " no input files\n";
		return 1;
	}
	
	++args;

	std::vector<std::string> extensions;
	#define _EXT(n) extensions.push_back(std::string(n));
	_EXT(".png")
	_EXT(".jpg")
	_EXT(".gif")
	_EXT(".jpeg")
	_EXT(".bmp")
	_EXT(".tiff")
	_EXT(".xcf")
	#undef _EXT

	char * title = args[0];

	std::string ext = NekoUtils::GetFileExtension(title);
	
	if (std::find(extensions.begin(), extensions.end(), ext) == extensions.end())
	{
		std::cout << "Invalid image format. Try to use a Image format.\n";
		return EXIT_FAILURE;
	}

	Display disp(args[0]);	
	
	while (!disp.update());
	
	return 0;
}
