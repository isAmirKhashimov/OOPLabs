#include "figure.h"


size_t Figure::VertexesNumber()
{
	return apixes.size();
}


void Figure::Print(std::ostream& os)
{
	std::string output = figureName + ": ";
	for (auto& apix : apixes)
	{
		output += apix.ToString();
	}
	os << output + "\n";
}
