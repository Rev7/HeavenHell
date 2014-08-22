#pragma once

#include <memory>

namespace sdlEngine
{
	class LoaderParams;

	class GameObject
	{
	public:
		virtual ~GameObject() {}

		virtual void load(std::unique_ptr<LoaderParams> const &params) = 0;
		virtual void draw() = 0;
		virtual void update() = 0;
		virtual void clean() = 0;
		virtual void collision() = 0;
		virtual std::string type() = 0;

		Vector2D& getPosition() { return _position; }
		Vector2D& getVelocity() { return _velocity; }
		int getWidth() { return _width; }
		int getHeight() { return _height; }

		bool updating() { return _updating; }
		bool dead() { return _dead; }
		bool dying() { return _dying; }

		void scroll(float scrollSpeed) { _position.setX(_position.getX() - scrollSpeed); }
		void setUpdating(bool updating) { _updating = updating; }

	protected:
		GameObject() : 
			_position(0, 0),
			_velocity(0, 0),
			_acceleration(0, 0),
			_width(0),
			_height(0),
			_currentRow(0),
			_curruntFrame(0),
			_updating(false),
			_dead(false),
			_dying(false),
			_angle(0),
			_alpha(255)
		{
		}//GameObject

		// Mouvements
		Vector2D _position;
		Vector2D _velocity;
		Vector2D _acceleration;

		// Dimensions
		int _width;
		int _height;

		// Animation
		int _currentRow;
		int _curruntFrame;
		int _numFrames;
		std::string _textureID;

		// Etats booléens
		bool _updating;
		bool _dead;
		bool _dying;

		// Rotation
		double _angle;

		// Transparence
		int _alpha;
	};
}