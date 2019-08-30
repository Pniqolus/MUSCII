#include "MChar.hpp"

#include <string>
#include <stdexcept>

using UTF8 = std::char_traits<char>;

using namespace MUSCII;

//------------------------------------------------------------------------------ Constructor(s)

MChar::MChar ()
{

}

MChar::MChar (int8_t position)
{
	this->position = position;
}

MChar::MChar (char ascii)
{
	auto muscii = CONVERSION_TABLE[ascii];
	if (muscii < 0)
		throw std::invalid_argument(
			"No equivalent MUSCII symbol exists for 0x" + std::to_string(ascii) + ".");
	
	this->position = muscii;
}

//------------------------------------------------------------------------------ Destructor

MChar::~MChar ()
{
	
}

//------------------------------------------------------------------------------ To Upper

MChar MChar::ToUpper () const
{
	return MChar( int8_t(
		(position >  9 && position < 36)
			? position ^ 64
			: position ));
}

//------------------------------------------------------------------------------ To Lower

MChar MChar::ToLower () const
{
	return MChar( int8_t(
		(position > 73 && position < 100)
			? position | 64
			: position ));
}

//------------------------------------------------------------------------------ To Shift Key

MChar MChar::ToShiftKey () const
{
	return MChar( int8_t(position | 64) );
}

//------------------------------------------------------------------------------ To ASCII

char MChar::ToASCII () const
{
	return static_cast<char>(CHARACTER_TABLE[position]);
}

//------------------------------------------------------------------------------ Is Upper

bool MChar::IsUpper () const
{
	return (position > 73 && position < 100);
}

//------------------------------------------------------------------------------ Is Lower

bool MChar::IsLower () const
{
	return (position >  9 && position < 36);
}

//------------------------------------------------------------------------------ Is Shift Key

bool MChar::IsShiftKey () const
{
	return (position & 64) != 0;
}

//------------------------------------------------------------------------------ Is Alpha

bool MChar::IsAlpha () const
{
	auto upper = (position | 64);
	return (upper > 73 && upper < 100);
}

//------------------------------------------------------------------------------ Is Numeric

bool MChar::IsNumeric () const
{
	return (position < 10);
}

//------------------------------------------------------------------------------ Is Alpha-Numeric

bool MChar::IsAlphaNumeric () const
{
	return (position < 36 || (position > 73 && position < 100));
}

//------------------------------------------------------------------------------ Is Symbol

bool MChar::IsSymbol () const
{
#if TREAT_GREEK_AS_SYMBOL
	return (position < 119 && !IsAlphaNumeric());
#else
	return (position < 119 &&
		!(IsAlphaNumeric() && (position > 46 && position < 64)));
#endif
}

//------------------------------------------------------------------------------