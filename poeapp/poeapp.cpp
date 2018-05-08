#include "Currency.h"
#include "Settings.h"

void LoadCurrency( Currency* allc )
{

	allc[0].Load( Currency::Type::exa );
	allc[1].Load( Currency::Type::annul );
	allc[2].Load( Currency::Type::div );
}

void MoveCurrency( Currency* allc )
{
	allc[1].MoveSprite( Currency::size, 0 );
	allc[2].MoveSprite( Currency::size * 2, 0 );
}

void DrawCurrency( Currency* curra, sf::RenderWindow& window )
{
	for( int i = 0; i < Currency::totalcurramount; i++ )
	{
		if( curra[i].IsLoaded() )
		{
			window.draw( curra[i].GetSprite() );
		}
	}
}

int main()
{
	sf::RenderWindow window( sf::VideoMode( Settings::windowx, Settings::windowy ), "POECurrencyTracker" );

	Currency allc[Currency::totalcurramount]; //all currency items

	LoadCurrency( allc ); //loading all the textures/sprites
	MoveCurrency( allc );

	while( window.isOpen() )
	{
		sf::Event event;
		while( window.pollEvent( event ) )
		{
			if( event.type == sf::Event::Closed )
				window.close();
		}

		window.clear();
		//start of drawing
		DrawCurrency( allc, window );



		//end of drawing
		window.display();
	}



	return 0;
}