#include "LevelParser.h"
#include "TextureManager.h"
#include "HHEngine.h"

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

		// Elements tileset et layer
		for (TiXmlElement* e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
		{
			if (e->Value() == std::string("tileset"))
			{
				parseTilesets(e, level->getTilesets());
			}//if
			else if (e->Value() == std::string("layer"))
			{
				parseTileLayer(e, level->getLayers(), level->getTilesets());
			}//else if
		}//for

		return level;
	}//parseLevel
	//---------------------------------------------------------------------------

	void LevelParser::parseTilesets(TiXmlElement* tilesetRoot, std::vector<Tileset>* tilesets)
	{
		// Ajout du tileset au textureManager
		TheTextureManager::Instance()->load(tilesetRoot->FirstChildElement()->Attribute("source"), tilesetRoot->Attribute("name"), TheHHEngine::Instance()->getRenderer());

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

	}//parseTileLayer
}