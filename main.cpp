
#include <podofo/podofo.h>

#include <QImage>
#include <QByteArray>
#include <QBuffer>
#include <QDebug>

using namespace PoDoFo;

int main()
{
	QImage img( "1.jpg" );
	QByteArray data;
	QBuffer buf( &data );

	img.save( &buf, "jpg" );

	PdfMemDocument doc;

	qDebug() << "image buffer size" << data.size();

	auto pdfImg = doc.CreateImage();
	pdfImg->LoadFromBuffer( { data.data(), static_cast< size_t > ( data.size() ) } );

	return 0;
}
