#pragma once
#include <cassert>
#include <SFML/Graphics.hpp>

class Currency
{
public:
	Currency() = default;
	Currency( const char* filename )
	{
		text.loadFromFile( filename );
		sprite.setTexture( text );
		loaded = true;
	}

	bool Load( const char* filename )
	{
		assert( !loaded );
		if( text.loadFromFile( filename ) )
		{
			sprite.setTexture( text );
			loaded = true;
			return true;
		}
		else
			return false;
	}

	bool IsLoaded()
	{
		return loaded;
	}

	sf::Sprite& GetSprite()
	{
		return sprite;
	}

	void MoveSprite( int x, int y )
	{
		sprite.move( x, y );
	}


	static constexpr int size = 78; //size of currency pics (square / 78*78)
	static constexpr int totalcurramount = 100; //rnd number / need to count relevant currencies
private:
	sf::Sprite sprite;
	sf::Texture text;
	bool loaded = false;
};