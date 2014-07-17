#pragma once

#include <string>
#include <map>
#include "GameObject.h"
#include "Tools.h"

namespace sdlEngine
{
	class BaseCreator
	{
	public:
		virtual GameObject* createGameObject() const = 0;
		virtual ~BaseCreator() {}
	};

	class GameObjectFactory
	{
	public:
		static GameObjectFactory* Instance()
		{
			if (NULL == _instance)
			{
				_instance = new GameObjectFactory();
			}//if

			return _instance;
		}//Instance

		bool registerType(std::string typeID, BaseCreator* creator)
		{
			std::map<std::string, BaseCreator*>::iterator it = _creators.find(typeID);

			if (it != _creators.end())
			{
				delete creator;
				return false;	// !!! !!! !!!
			}//if

			_creators[typeID] = creator;

			return true;
		}//registerType

		GameObject* create(std::string typeID)
		{
			std::map<std::string, BaseCreator*>::iterator it = _creators.find(typeID);

			if (it == _creators.end())
			{
				std::cout << "### Could not find type: " << typeID << "\n";
				return NULL;
			}//if

			BaseCreator* creator = (*it).second;
			return creator->createGameObject();
		}//create

	private:
		static GameObjectFactory* _instance;
		std::map<std::string, BaseCreator*> _creators;
	};

	GameObjectFactory* GameObjectFactory::_instance = NULL;
	typedef GameObjectFactory TheGameObjectFactory;
}