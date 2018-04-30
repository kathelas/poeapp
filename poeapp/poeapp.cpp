#include "Currency.h"

auto LoadCurrency( Currency* allc )
{
	allc[0].Load( "Currency\\exalted.png" );
	allc[1].Load( "Currency\\exalted.png" );
	allc[2].Load( "Currency\\exalted.png" );
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
	sf::RenderWindow window( sf::VideoMode( 800, 600 ), "POECurrencyTracker" );

	Currency allc[Currency::totalcurramount]; //all currency items

	LoadCurrency( allc ); //loading all the textures/sprites

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