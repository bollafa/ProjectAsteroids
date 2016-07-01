#include <stdio.h> 
#include <allegro5/allegro.h> 
#include <allegro5/allegro_primitives.h> 
#include <allegro5\allegro_font.h>
#include <math.h> 
#include <allegro5\allegro_primitives.h>
#include "Vector.h"
#include "Entity.h"
#include "Unit.h"
#include "MathHelper.h"
#include "Globals.h"
#include "Player.h"
#include "Asteroid.h"
#include "UnitMgr.h"
#include "EnemyMgr.h"
class Player;
Player* pPlayer;
EnemyMgr* pEnemyMgr;
int main()
{
	/*
	*	Error Checking!
	*/
	if (!al_init())
		return -1;
	//	Window Init
	ALLEGRO_DISPLAY* window = NULL;
	window = al_create_display(WIDTH, HEIGHT);
	// 
	// Installing ...
	//

	al_install_keyboard();
	al_install_mouse();
	al_init_primitives_addon();
	al_init_font_addon();

	//
	//	 Fonts and Timers and Checks
	//
	ALLEGRO_FONT *Basic = NULL;
	ALLEGRO_TIMER* tick = NULL;
	ALLEGRO_EVENT_QUEUE *event_q = NULL;
	ALLEGRO_TIMER* spawner = NULL;
	bool bReDraw = true;
	bool bAlive = true;
	// Initializing
	Basic = al_create_builtin_font();
	tick = al_create_timer(1.0 / FPS); // REMEMBER THIS IS DOUBLE NOT INT
	event_q = al_create_event_queue();
	spawner = al_create_timer(10);
	// Init Player & Managers
	//--------------------------------------
	pPlayer = new Player(Vector(WIDTH / 2, HEIGHT / 2 ), 10.5,3.0),
	pEnemyMgr = new EnemyMgr(20, 2.0,50);
	int counter = 0;
	bool IsMoving = false;
	//FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
	
	// Register Events
	al_register_event_source(event_q, al_get_timer_event_source(tick));
	al_register_event_source(event_q, al_get_keyboard_event_source());
	al_register_event_source(event_q, al_get_mouse_event_source());
	al_register_event_source(event_q, al_get_display_event_source(window));
	al_register_event_source(event_q, al_get_timer_event_source(spawner));
	//TODO: CREATE TIMER THAT CREATES WAVES OF ENEMIES
	//Start Timer
	//------------------------//
	al_start_timer(spawner);
	al_start_timer(tick);

	// 600 0.004 VECTOR
	// 600 0.005 LIST

	//Game Loop

	while (bAlive)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_q, &ev);
		switch (ev.type)
		{
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			bAlive = false;
			break;
		case ALLEGRO_EVENT_TIMER:
			if(ev.timer.source == tick)
				bReDraw = true;
			if(ev.timer.source ==spawner )
				pEnemyMgr->CreateEnemies();
			break;

		case ALLEGRO_EVENT_KEY_UP:
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_RIGHT:
				//pPlayer->MoveToRight();
				pPlayer->RequestMove(0,0);
				//IsMoving = true;
				break;
			case ALLEGRO_KEY_DOWN:
				pPlayer->RequestMove(0, 3);

				break;
			case ALLEGRO_KEY_UP:
				pPlayer->RequestMove(0,2);
				break;
			case ALLEGRO_KEY_LEFT:
				//pPlayer->MoveToLeft();
				pPlayer->RequestMove(0, 1);
				//IsMoving = true;
				break;


			}
			break;
		case ALLEGRO_EVENT_KEY_CHAR:
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_RIGHT:
				//pPlayer->MoveToRight();
				pPlayer->RequestMove(1,0);
				IsMoving = true;
				break;
			case ALLEGRO_KEY_DOWN:
				pPlayer->RequestMove(1,3);
				
				break;
			case ALLEGRO_KEY_UP:
				pPlayer->RequestMove(1,2);
				break;
			case ALLEGRO_KEY_LEFT:
				//pPlayer->MoveToLeft();
				pPlayer->RequestMove(1,1);
				IsMoving = true;
				break;
			default:
				break;
			}
			break;
		default:
			break;






		}

		// Every 1/60
		
		if (bReDraw && al_event_queue_is_empty(event_q))
		{
			
			bReDraw = false; // Hah D:D
			counter++;
			
			//pPlayer->ApplyForce(counter);
			//pPlayer->MoveTo();
			pPlayer->Update();
			//pPlayer->Draw();
			//Math::VectorbyAngle(circle, counter, 3);
			//al_draw
			//al_draw_pixel(WIDTH/2 + circle.X, HEIGHT/ 2 +circle.Y, al_map_rgb(255, 25, 25));
			//al_draw_circle(WIDTH / 2 + circle.X, HEIGHT / 2 + circle.Y, 50, al_map_rgb(0, 0, 255), 2);
			//al_draw_pixel(circle.X,  circle.Y, al_map_rgb(255, 25, 25));
			//al_draw_circle( circle.X,  circle.Y, 50, al_map_rgb(0, 0, 255), 2);
			//al_draw_circle(WIDTH / 2, HEIGHT / 2, 400,al_map_rgb(0, 0, 255), 2);
			
			
			double INITIALTIME = al_get_time();
			UnitMgr::UpdateUnits();
			al_draw_textf(Basic, al_map_rgb(255, 255, 255), WIDTH / 2, HEIGHT / 2, ALLEGRO_ALIGN_CENTER, "AAAAAAAAAAAAAAA n  The Game: %i Time : %f", UnitMgr::mgrUnits.size(), al_get_time() - INITIALTIME);
			al_draw_circle(WIDTH / 2, HEIGHT / 2, 400, al_map_rgb(255, 25, 25), 2);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}





	}
	al_destroy_display(window);
	return 0;
}