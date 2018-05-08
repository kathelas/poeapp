#pragma once
#include <cassert>
#include <SFML/Graphics.hpp>

class Currency
{
public:
	enum class Type
	{
		acs,
		alch,
		alt,
		annul,
		bauble,
		bless,
		chance,
		chaos,
		chis,
		chrom,
		div,
		exa,
		fus,
		gcp,
		jcs,
		jew,
		mcs,
		regal,
		regret,
		scour,
		silv,
		vaal
	};
public:
	Currency() = default;
	Currency( const char* filename )
	{
		text.loadFromFile( filename );
		sprite.setTexture( text );
		loaded = true;
	}

	bool Load( Type type )
	{
		assert( !loaded );
		if( text.loadFromFile( TypeToString( type ) ) )
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
		sprite.move( (float)x, (float)y );
	}


	static constexpr int size = 78; //size of currency pics (square / 78*78)
	static constexpr int totalcurramount = 100; //rnd number / need to count relevant currencies
private:
	const char* TypeToString( Type type )
	{
		switch( type )
		{
		case Type::acs:
			return "Currency\\acs.png";
		case Type::alch:
			return "Currency\\alch.png";
		case Type::alt:
			return "Currency\\alt.png";
		case Type::annul:
			return "Currency\\acs.png";
		case Type::div:
			return "Currency\\div.png";
		case Type::exa:
			return "Currency\\exa.png";
		}
	}

	sf::Sprite sprite;
	sf::Texture text;
	bool loaded = false;
};