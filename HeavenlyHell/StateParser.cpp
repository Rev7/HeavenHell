#include "StateParser.h"
#include "TextureManager.h"
#include "HHEngine.h"
#include "GameObjectFactory.h"
#include "LoaderParams.h"

namespace sdlEngine
{
	bool StateParser::parseState(const char* stateFile, std::string stateID, std::vector<GameObject*>* objects, std::vector<std::string>* textureIDs)
	{
		// Création du document XML
		TiXmlDocument xmlDoc;

		// Chargement du stateFile
		if (!xmlDoc.LoadFile(stateFile))
		{
			std::cout << xmlDoc.ErrorDesc() << "\n";
			return false;
		}//if

		// Element root
		TiXmlElement* root = xmlDoc.RootElement();

		// Element stateRoot
		TiXmlElement* stateRoot = NULL;
		for (TiXmlElement* e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
		{
			if (e->Value() == stateID)
			{
				stateRoot = e;
			}//if
		}//for

		// Element textureRoot et objectRoot
		TiXmlElement* textureRoot = NULL;
		TiXmlElement* objectRoot = NULL;
		for (TiXmlElement* e = stateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
		{
			if (e->Value() == std::string("TEXTURES"))
			{
				textureRoot = e;
			}//if

			else if (e->Value() == std::string("OBJECTS"))
			{
				objectRoot = e;
			}//else if
		}//for

		// Parsing des textures et objets
		parseTextures(textureRoot, textureIDs);
		parseObjects(objectRoot, objects);

		return true;
	}//parseState

	void StateParser::parseObjects(TiXmlElement* stateRoot, std::vector<GameObject*>* objects)
	{
		for (TiXmlElement* e = stateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
		{
			int x, y, width, height, numFrames, callbackID, animSpeed;
			std::string textureID;
			
			e->Attribute("x", &x);
			e->Attribute("y", &y);
			e->Attribute("width", &width);
			e->Attribute("height", &height);
			e->Attribute("numFrames", &numFrames);
			e->Attribute("callbackID", &callbackID);
			e->Attribute("animSpeed", &animSpeed);

			textureID = e->Attribute("textureID");

			GameObject* gameObject = TheGameObjectFactory::Instance()->create(e->Attribute("type"));
			gameObject->load(new LoaderParams(x, y, width, height, textureID, numFrames, callbackID, animSpeed));
			objects->push_back(gameObject);
		}//for
	}//parseObjects

	void StateParser::parseTextures(TiXmlElement* stateRoot, std::vector<std::string>* textureIDs)
	{
		for (TiXmlElement* e = stateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
		{
			std::string filenameAttribute = e->Attribute("filename");
			std::string idAttribute = e->Attribute("ID");
			textureIDs->push_back(idAttribute);

			TheTextureManager::Instance()->load(filenameAttribute, idAttribute, TheHHEngine::Instance()->getRenderer());
		}//for
	}//parseTextures
}