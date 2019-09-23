	/***********************************************************
	// OOP345 Workshop 2:                        Text.cpp     /
	///////////////////////////////////////////////////////////
	// Name: Andre Machado do Monte     -  Date: May 25, 2018//
	///////////////////////////////////////////////////////////
	***********************************************************/

	#include <iostream>
	#include <cstring>
	#include <utility>
	#include <fstream>

	#include "Text.h"


	using namespace std;

	namespace sict {
		//Default construct setting the attribute to nullptr.
		Text::Text() {
			texto = nullptr;
			cntLines = 0;
		}

		//Constructor receiving 1 argument
		Text::Text(char* file) : Text() {

			std::ifstream is(file, ios::in);

			if(is.is_open()) {
				char line[1000];

				//counting the number of lines the file has.
				while(!is.eof()) {
					while(is.getline(line, 1000, '\n')) {
						
					cntLines++;}
				}
				
				//Allocating memory dinamically
				if(texto!=nullptr) {
					delete[] texto;
				}
				texto = new string [cntLines];
				int i = 0;
				is.seekg(0);//returning to the begining of the file.
				
				//Reading all lines and passing to texto
				while(is.good()) {
					std::getline(is, texto[i++], '\n');
				}				
				is.close();
			} 
		}


		//Copy Constructor
		Text::Text(const Text& obj) : Text() {
			set(obj);
		}


		//Move constructor
		Text::Text(Text&& str) : Text() {
			*this = move(str);
		}


		//DESTRUCTOR
		Text::~Text() {
			delete[] texto;
		}


		//OPERATORS
		//Move Assignment Operator
		Text& Text::operator=(Text&& str) {
			if(&str != this) {
				//Cleaning the current object
				if (texto != nullptr) {
					delete[] texto;
				}

				//Moving the content from str to my current object
				texto = str.texto;
				cntLines = str.cntLines;

				//Cleando the srt object
				str.texto = nullptr;
				str.cntLines = 0;
			}

			return *this;
		}

		
		//Copy Assignment Operator
		Text& Text::operator=(const Text& obj) {
			set(obj);
			return *this;
		}

		//MEMBER FUNCTIONS
		
		//function to count lines.
		std::size_t Text::size() const {
			return cntLines;
		}
		
		
		//functino to set the object
		void Text::set(const Text& obj){
			if(texto!=nullptr) {
				delete[] texto;
			}
			texto = nullptr;
			if (obj.size() > 0) {
				texto = new string[obj.size()];
				cntLines = obj.size();

				//copying array
				for(unsigned i = 0; i < obj.size(); i++) {
					texto[i] = obj.texto[i];
				}
			}
		}
	}
