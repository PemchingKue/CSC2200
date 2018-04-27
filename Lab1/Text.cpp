//Pemching Kue
//fr6680

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include "Text.h"

Text::Text ( const char *charSeq ){
	
	bufferSize = strlen(charSeq) + 1;
	buffer = new char[bufferSize];
	strcpy(buffer, charSeq);
}

Text::Text(const Text &other) :bufferSize(other.bufferSize){
	buffer = new char[bufferSize];
	strcpy(buffer, other.buffer);
}

void Text::operator = ( const Text &other )
{
	if (bufferSize < other.bufferSize){
		delete[] buffer;
		bufferSize = other.bufferSize;
		buffer = new char[bufferSize];
	}
	strcpy(buffer, other.buffer);
}

Text::~Text ()
{
	delete[] buffer;
}

int Text::getLength () const
{
	return bufferSize - 1;
}

char Text::operator [] ( int n ) const
{
	if (n >= 0 && n < bufferSize){
		return buffer[n];
	}
	else{
		return '\0';
	}
}

void Text::clear ()
{
	delete[] buffer;
	buffer = new char[bufferSize];
	for (int i = 0; i < bufferSize; i++){
		buffer[i] = '\0';
	}
}

void Text::showStructure () const
{

	int j;   // Loop counter
	for (j = 0; j < bufferSize; j++)
		cout << j << "\t";    
		cout << endl;

	for (j = 0; buffer[j] != '\0'; j++)
		cout << buffer[j] << "\t";
		cout << "\\0" << endl;

}

Text Text::toUpper( ) const
{
	Text temp(buffer);
	for (int i = 0; i < bufferSize; i++){
		if ((buffer[i] > 96) && (buffer[i] < 123)){
			temp.buffer[i] = char(buffer[i] - 32);
		}
	}
	return temp;
}

Text Text::toLower( ) const
{
	Text temp(buffer);
	for (int i = 0; i < temp.getLength(); i++){
		if ((buffer[i] > 64) && (buffer[i] < 91)){
			temp.buffer[i] = char(buffer[i] + 32);
		}
	}
	return temp;
}

bool Text::operator == ( const Text& other ) const
{
	if (bufferSize == other.getLength()){
		if (bufferSize == 0){
			return true;
		}
		else{
			for (int i = 0; i < bufferSize; i++){
				if (buffer[i] != other.buffer[i]){
					return false;
				}
			}
			return true;
		}
	}
	else{
		return false;
	}
}

bool Text::operator <  ( const Text& other ) const
{
	if (other.getLength()){
		if (bufferSize){
			for (int i = 0; i < bufferSize; i++){
				if (buffer[i] > other.buffer[i]){
					return false;
				}
			}
			if ((other.getLength() < bufferSize) || (other.getLength() == bufferSize)){
				return false;
			}
			else{
				return true;
			}
		}
		else{
			return true;
		}
	}
	return false;
}

bool Text::operator >  ( const Text& other ) const
{
	if (bufferSize){
		if (other.getLength()){
			for (int i = 0; i < other.getLength(); i++){
				if (buffer[i] < other.buffer[i]){
					return false;
				}
			}
			if ((other.getLength() > bufferSize) || (other.getLength() == bufferSize)){
				return false;
			}
			else{
				return true;
			}
		}
		else{
			return true;
		}
	}
	return false;
}
