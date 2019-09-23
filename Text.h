/***********************************************************
// OOP345 Workshop 2:                        Text.h       /
///////////////////////////////////////////////////////////
// Name: Andre Machado do Monte     -  Date: May 25, 2018//
///////////////////////////////////////////////////////////
***********************************************************/
#include <iostream>


#ifndef TEXT_H
#define TEXT_H


namespace sict {

	//creating a class with name Text
	class Text {

        private:
            std::string* texto;
			std::size_t cntLines;
			void set(const Text& obj);
			
		public:
			//CONSTRUCTORS
			//Default Constructor
			Text();
			
			//constructor 1 argument
			Text(char* file);

			//Copy Constructor
			Text(const Text& obj);

			//Move constructor
			Text(Text&& str);


			//DESTRUCTORS
			~Text();

			//OPERATORS
			//Move Assignment Operator
			Text& operator=(Text&& str);

			//Copy Assignment Operator
			Text& operator=(const Text& obj);

			//Member Functions
			std::size_t size() const;

	};
}
#endif

//copy - recorta e copia outro arquivo. - 2 arquivo (copy)
// move - tire de um lugar para outro. - 1 arquivo, só move (recortar)
