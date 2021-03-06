#pragma once

#include <iostream>
#include <vector>
#include "tinyXML.h"

namespace sdlEngine
{
	class GameObject;

	class StateParser
	{
	public:
		bool parseState(const char* stateFile, std::string stateID, std::vector<GameObject*>* objects, std::vector<std::string>* textureIDs);

	private:
		void parseObjects(TiXmlElement* stateRoot, std::vector<GameObject*>* objects);
		void parseTextures(TiXmlElement* stateRoot, std::vector<std::string>* textureIDs);
	};
}