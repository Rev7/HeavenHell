#include "LevelParser.h"
#include "TextureManager.h"
#include "HHEngine.h"
#include "TileLayer.h"
#include "ObjectLayer.h"
#include "GameObjectFactory.h"
#include "LoaderParams.h"
#include "Level.h"
#include "base64.h"
#include "zlib\zlib.h"

namespace sdlEngine
{
	LevelParser::LevelParser()
	{

	}//LevelParser
	//---------------------------------------------------------------------------

	LevelParser::~LevelParser()
	{
	}//~LevelParser
	//---------------------------------------------------------------------------

	Level* LevelParser::parseLevel(const char* levelFile)
	{
		// Création du document XML
		TiXmlDocument levelDoc;

		// Chargement du levelFile
		levelDoc.LoadFile(levelFile);

		// Création de l'objet level
		Level* level = new Level();

		// Element root
		TiXmlElement* root = levelDoc.RootElement();

		root->Attribute("tilewidth", &_tileSize);
		root->Attribute("width", &_width);
		root->Attribute("height", &_height);

		// Properties
		TiXmlElement* properties = root->FirstChildElement();
		for (TiXmlElement* e = properties->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
		{
			if (e->Value() == std::string("property"))
			{
				parseTextures(e);
			}//if
		}//for

		// Tilesets
		for (TiXmlElement* e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
		{
			if (e->Value() == std::string("tileset"))
			{
				parseTilesets(e, level->getTilesets());
			}//if
		}//for

		// Layers et ObjectGroups
		for (TiXmlElement* e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
		{
			if (e->Value() == std::string("objectgroup") || e->Value() == std::string("layer"))
			{
				if (e->FirstChildElement()->Value() == std::string("object"))
				{
					parseObjectLayer(e, level->getLayers());
				}//if
				else if (e->FirstChildElement()->Value() == std::string("data") ||
							(e->FirstChildElement()->NextSiblingElement() != 0 &&
							 e->FirstChildElement()->NextSiblingElement()->Value() == std::string("data")))
				{
					parseTileLayer(e, level->getLayers(), level->getTilesets());
				}//else if
			}//if
		}//for

		return level;
	}//parseLevel
	//---------------------------------------------------------------------------

	void LevelParser::parseTilesets(TiXmlElement* tilesetRoot, std::vector<Tileset>* tilesets)
	{
		// Ajout du tileset au textureManager
		TheTextureManager::Instance()->load("assets/"+ std::string(tilesetRoot->FirstChildElement()->Attribute("source")), tilesetRoot->Attribute("name"), TheHHEngine::Instance()->getRenderer());

		// Création d'un objet tileset
		Tileset tileset;
		tilesetRoot->FirstChildElement()->Attribute("width", &tileset.width);
		tilesetRoot->FirstChildElement()->Attribute("height", &tileset.height);
		tilesetRoot->Attribute("firstgid", &tileset.firstGridID);
		tilesetRoot->Attribute("tilewidth", &tileset.tileWidth);
		tilesetRoot->Attribute("tileheight", &tileset.tileHeight);
		tilesetRoot->Attribute("spacing", &tileset.spacing);
		tilesetRoot->Attribute("margin", &tileset.margin);
		tileset.name = tilesetRoot->Attribute("name");

		tileset.numColumns = tileset.width / (tileset.tileWidth + tileset.spacing);

		tilesets->push_back(tileset);
	}//parseTilesets
	//---------------------------------------------------------------------------

	void LevelParser::parseTileLayer(TiXmlElement* tileElement, std::vector<Layer*>* layers, const std::vector<Tileset>* tilesets)
	{
		TileLayer* tileLayer = new TileLayer(_tileSize, *tilesets);

		bool collidable = false;
		std::vector<std::vector<int>> data;
		std::string decodedIDs;

		TiXmlElement* dataNode = NULL;
		for (TiXmlElement* e = tileElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
		{
			if (e->Value() == std::string("properties"))
			{
				for (TiXmlElement* property = e->FirstChildElement(); property != NULL; property = property->NextSiblingElement())
				{
					if (property->Value() == std::string("property"))
					{
						if (property->Attribute("name") == std::string("collidable"))
						{
							collidable = true;
						}//if
					}//if
				}//for
			}//if

			else if (e->Value() == std::string("data"))
			{
				dataNode = e;
			}//else if
		}//for

		for (TiXmlNode* e = dataNode->FirstChild(); e != NULL; e = e->NextSibling())
		{
			TiXmlText* text = e->ToText();
			std::string t = text->Value();
			decodedIDs = base64_decode(t);
		}//for

		// Décompression zlib
		uLongf numGids = _width * _height * sizeof(int);
		std::vector<unsigned> gids(numGids);
		uncompress((Bytef*)&gids[0], &numGids, (const Bytef*)decodedIDs.c_str(), decodedIDs.size());

		std::vector<int> layerRow(_width);

		for (unsigned int j = 0; j < _height; ++j)
		{
			data.push_back(layerRow);
		}//for

		for (unsigned int rows = 0; rows < _height; ++rows)
		{
			for (unsigned int cols = 0; cols < _width; ++cols)
			{
				data[rows][cols] = gids[rows * _width + cols];
			}//for
		}//for

		tileLayer->setTileIDs(data);

		if (collidable)
		{
			collisionLayers->push_back(tileLayer);
		}//if

		layers->push_back(tileLayer);
	}//parseTileLayer
	//---------------------------------------------------------------------------

	void LevelParser::parseTextures(TiXmlElement* textureRoot)
	{
		TheTextureManager::Instance()->load(textureRoot->Attribute("value"), textureRoot->Attribute("name"), TheHHEngine::Instance()->getRenderer());
	}//parseTextures
	//---------------------------------------------------------------------------

	void LevelParser::parseObjectLayer(TiXmlElement* objectElement, std::vector<Layer*>* layers)
	{
		ObjectLayer* objectLayer = new ObjectLayer();

		std::cout << objectElement->FirstChildElement()->Value();

		for (TiXmlElement* e = objectElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
		{
			std::cout << e->Value();
			if (e->Value() == std::string("object"))
			{
				int x, y, width, height, numFrames, callbackID, animSpeed;
				std::string textureID;

				e->Attribute("x", &x);
				e->Attribute("y", &y);

				GameObject* gameObject = TheGameObjectFactory::Instance()->create(e->Attribute("type"));

				for (TiXmlElement* properties = e->FirstChildElement(); properties != NULL; properties = properties->NextSiblingElement())
				{
					if (properties->Value() == std::string("properties"))
					{
						for (TiXmlElement* property = properties->FirstChildElement(); property != NULL; property = property->NextSiblingElement())
						{
							if (property->Value() == std::string("property"))
							{
								if (property->Attribute("name") == std::string("numFrames"))
								{
									property->Attribute("value", &numFrames);
								}//if
								else if (property->Attribute("name") == std::string("textureHeight"))
								{
									property->Attribute("value", &height);
								}//else if
								else if (property->Attribute("name") == std::string("textureID"))
								{
									textureID = property->Attribute("value");
								}//else if
								else if (property->Attribute("name") == std::string("textureWidth"))
								{
									property->Attribute("value", &width);
								}//else if
								else if (property->Attribute("name") == std::string("callbackID"))
								{
									property->Attribute("value", &callbackID);
								}//else if
								else if (property->Attribute("name") == std::string("animSpeed"))
								{
									property->Attribute("value", &animSpeed);
								}//else if
							}//if
						}//for
					}//if
				}//for

				gameObject->load(new LoaderParams(x, y, width, height, textureID, numFrames, callbackID, animSpeed));

				if (type == "Player")
				{
					_level->setPlayer(dynamic_cast<Player*>(gameObject));
				}//if

				objectLayer->getGameObjects()->push_back(gameObject);
			}//if 
		}//for

		layers->push_back(objectLayer);
	}//parseObjectLayer
}