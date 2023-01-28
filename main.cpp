
#include <podofo/podofo.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <exception>

using namespace PoDoFo;

int main()
{
	std::ifstream file( "1.jpg", std::ios::in | std::ios::binary );

	if( file.is_open() )
	{
		std::vector< char > content;

		file.seekg( 0, std::ios::end );
		const auto ssize = file.tellg();
		content.resize( (size_t) ssize );
		file.seekg( 0, std::ios::beg );
		file.read( &content[ 0 ], ssize );

		file.close();

		PdfMemDocument doc;

		std::cout << "image buffer size " << content.size() << std::endl;

		auto pdfImg = doc.CreateImage();

		try {
			pdfImg->LoadFromBuffer( { &content[ 0 ], content.size() } );

			return 0;
		}
		catch( const std::exception & x )
		{
			std::cout << x.what() << std::endl;
		}
		catch( ... )
		{
			std::cout << "Unknown exception";
		}

		return 1;
	}
	else
		std::cout << "Unable to open 1.jpg file.\n";

	return 1;
}
