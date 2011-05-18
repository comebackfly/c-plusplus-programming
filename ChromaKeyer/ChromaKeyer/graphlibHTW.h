/*!***************************************************************************

  @file:         GraphlibHTW.h

  @author:       Tim Wöhrle

  @keyword:       Small graph library for HTW

  Kleine Graphikbibliothek mit Bilddatei-Im- und Export. 
  .h und .lib-Datei muessen im Projektordner liegen; .dll im Ausfuehrungsordner

  Aufrufbeispiel:
  ...

  // Einbinden der Bibliothek

  #include "graphlibHTW.h"
  int w, h, bpp;
  unsigned char *pix = (unsigned char *)htwOpenImage( "C:\\MyImage.png", &w, &h, &bpp );
  
  if( !pix )
     // Bild konnte nicht geladen werden
  else if( bpp==1 )
     // Graustufenbild in eigene Struktur kopieren
  else if( bpp==3 )
     // Farbbild in eigene Struktur kopieren
  htwDeleteImage( pix ); 

  @history
  2009-06-22 - rekommentiert

*****************************************************************************/
#include <windows.h>
#include <math.h>

#ifndef _graphlibHTW_H
#define _graphlibHTW_H

#ifdef GRAPHLIBHTW_EXPORTS
   #define BM_API extern "C" __declspec(dllexport)
#else
   #define BM_API extern "C" __declspec(dllimport)
   #pragma comment(lib, "graphlibHTW.lib")
#endif
#define BM_EXP __cdecl


///////////////////////////////////////////////////////////////////////////////
/// Oeffnet eine Bilddatei, und liefert den Inhalt zurueck.
/// Wenn es sich ume eine gueltige Bilddatei handelt, werden die Bilddaten
/// eingelesen und in ein einheitliches Format konvertiert
/// htwOpenImage unterstuetzt folgende Formate:
/// @li BMP
/// @li PNG
/// @li JPG
/// @li GIF
/// 
/// @param pFileName[in]: Name der Bilddatei
/// @param pWidth[out]: Breite des Bildes in Pixel
/// @param pHeight[out]: Hoehe des Bildes in Pixel
/// @param pBytesPerPixel[out]: Anzahl der Bytes pro Pixel
///     htwOpenImage unterstuetzt 2 Formate: Schwarzweissbilder (1 Byte pro Pixel)
///     und Farbbilder (3 Byte pro Pixel: B,G,R)
///
/// @return Zeiger auf die Bilddaten. Der Zeiger zeigt auf das erste Pixel der 
/// Bilddaten, und muss nach Benutzung mit htwDeleteImage freigegeben werden.
/// Die Groesse des Blocks, auf das er zeigt, betraegt pWidth*pHeight*pBytesPerPixel
///////////////////////////////////////////////////////////////////////////////
BM_API void *BM_EXP htwOpenImage( const char *pFileName, int *pWidth, int *pHeight, int *pBytesPerPixel );


///////////////////////////////////////////////////////////////////////////////
/// Speichert Bilddaten in einer Bilddatei.
/// Abhaengig von der Extension in pFileName wird das entsprechende Format 
/// gewaehlt ( "Bild.bmp" --> BMP-Format )
/// Unterstuetzte BildFormate: BMP, JPG
///
/// @param pFileName[in]: Name der Bilddatei
/// @param pPixel[in]: Zeiger auf die Bilddaten analog zu htwOpenImage
/// @param pWidth[in]: Breite des Bildes in Pixel
/// @param pHeight[in]: Hoehe des Bildes in Pixel
/// @param pBytesPerPixel[in]: Anzahl der Bytes pro Pixel
///
/// @return true--> Erfolgreich
///////////////////////////////////////////////////////////////////////////////
BM_API bool BM_EXP htwSaveImage( const char *pFileName, const void *pPixel, int pWidth, int pHeight, int pBytesPerPixel );


///////////////////////////////////////////////////////////////////////////////
/// Erzeugt einen Block mit leeren Bilddaten.
/// Der Block wird mit 0en gefuellt
/// BildFormat: @see htwOpenImage
///
/// @param pWidth[in]: Breite des Bildes in Pixel
/// @param pHeight[in]: Hoehe des Bildes in Pixel
/// @param pBytesPerPixel[in]: Anzahl der Bytes pro Pixel
///
/// @return Zeiger auf die Bilddaten, @see htwOpenImage
///////////////////////////////////////////////////////////////////////////////
BM_API void *BM_EXP htwCreateImage( const char *pFileName, int pWidth, int pHeight, int pBytesPerPixel );


///////////////////////////////////////////////////////////////////////////////
/// Loescht die Bilddaten, die mit htwOpenImage/htwCreateImage erzeugt wurden.
/// 
/// @param pPixel[in]: Zeiger auf die Bilddaten analog zu htwOpenImage
///////////////////////////////////////////////////////////////////////////////
BM_API void BM_EXP htwDeleteImage( void *pPixel );

#endif // _biplib_H