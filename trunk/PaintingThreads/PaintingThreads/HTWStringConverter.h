/*!***************************************************************************

  @file:         HTWStringConverter.h

  @author:       Tim Wöhrle

  @keyword:      string <--> String Converter class

  Klasse zur Konvertierung zwischen std-Strings (std::string) 
  und .NET-Strings (System::String)

  Code freundlicherweise zur Verfügung gestellt von: 
  Justin Evans und Claudio Brefeldt

  Aufrufbeispiel:
  Annahme: es gibt im GUI ein Eingabefeld 'tbInput'
  Dessen Text-Property ist ein .NET-String
  
  #include "HTWStringConverter.h"

  std::string s;
  s = HTWStringConverter::Sys2Std( tbInput->Text );


  @history
  2010-05-06 - erzeugt
  2010-05-07 - fehlendes std:: --> gefixt
  2010-05-07 - Erweiterung Std2Sys() auf wstring
*****************************************************************************/

#ifndef _HTWStringConverter_H
#define _HTWStringConverter_H


class HTWStringConverter
{

public:

   // .NET-String --> std-string
   static std::string Sys2Std (System::String^ S)
   {
      std::string ss; 

      if (S->Length > 0)
      {
         System::IntPtr ip = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi (S);

         try { ss = static_cast<const char*>(ip.ToPointer ()); }
         __finally { System::Runtime::InteropServices::Marshal::FreeHGlobal (ip);}
      }

      return ss;
   }

   // std-string --> .NET-String
   static System::String^ Std2Sys (std::string str)
   {
      return gcnew System::String (str.c_str ());
   }

   // std-wstring --> .NET-String
   static System::String^ Std2Sys (std::wstring str)
   {
      return gcnew System::String (str.c_str ());
   }
};

#endif // __HTWStringConverter_H



