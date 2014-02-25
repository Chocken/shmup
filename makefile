OBJS = Program.o Game.o MenuState.o Sprite.o PlayState.o PauseState.o Background.o Timer.o DrawableObject.o BlackScreen.o PlayerShip.o Level.o Vector2D.o GameObjectFactory.o Explosion.o CollisionDetector.o Rectangle.o Circle.o StraightProjectile.o ProjectileFactory.o BasicEnemy.o ExplosionFactory.o GamePlayObject.o SineBehaviour.o StraightWeapon.o VerticalLineBehaviour.o SplineBehaviour.o MathsHelper.o TextRenderer.o LazerWeapon.o SpreadWeapon.o SpreadWeapon2.o SpecFactory.o Enemy.o LogoState.o IntroState.o BossBehaviourOne.o

CC = g++ -std=c++0x

DEBUG = -g
CFLAGS = -c $(DEBUG)
LFLAGS = $(DEBUG)

mygame: $(OBJS)
	g++ $(OBJS) -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -o mygame

Program.o: Program.cpp Game.h LogoState.h MenuState.h GameState.h Sprite.h Settings.h
	$(CC) $(CFLAGS) Program.cpp 	 

Game.o: Game.cpp Game.h GameState.h Sprite.h
	$(CC) $(CFLAGS) Game.cpp

PlayState.o: PlayState.cpp PlayState.h GameState.h Game.h Sprite.h Timer.h LevelFactory.h DrawableObject.h Background.h PlayerShip.h BlackScreen.h GameObjectFactory.h Explosion.h Sprite.h DrawableObject.h
	$(CC) $(CFLAGS) PlayState.cpp

TextRenderer.o:TextRenderer.cpp TextRenderer.h
	$(CC) $(CFLAGS) TextRenderer.cpp

LogoState.o: LogoState.cpp LogoState.h GameState.h Game.h Sprite.h Timer.h
	$(CC) $(CFLAGS) LogoState.cpp

IntroState.o: IntroState.cpp IntroState.h GameState.h Game.h Sprite.h Timer.h
	$(CC) $(CFLAGS) IntroState.cpp

MenuState.o: MenuState.cpp MenuState.h GameState.h Game.h PlayState.h Sprite.h Timer.h LevelFactory.h DrawableObject.h Background.h PlayerShip.h BlackScreen.h GameObjectFactory.h Explosion.h Sprite.h DrawableObject.h TextRenderer.h
	$(CC) $(CFLAGS) MenuState.cpp

PauseState.o: PauseState.cpp PauseState.h GameState.h Game.h Sprite.h
	$(CC) $(CFLAGS) PauseState.cpp

LevelFactory.o: LevelFactory.cpp LevelFactory.h Level.h Background.h PlayerShip.h BlackScreen.h PlayerShip.h LevelFactory.h GameObjectFactory.h Explosion.h Timer.h Game.h DrawableObject.h Sprite.h
	$(CC) $(CFLAGS) LevelFactory.cpp

Level.o : Level.cpp Level.h Background.h PlayerShip.h BlackScreen.h PlayerShip.h LevelFactory.h GameObjectFactory.h Explosion.h Timer.h Game.h DrawableObject.h GameObjects.h Enemy.h BasicEnemy.h
	$(CC) $(CFLAGS) Level.cpp

GameObjectFactory.o: GameObjectFactory.cpp GameObjectFactory.h Sprite.h Background.h PlayerShip.h Explosion.h Vector2D.h DrawableObject.h IUpdateable.h Obstacle.h StraightWeapon.h LazerWeapon.h BasicEnemy.h SpreadWeapon.h SpecFactory.h
	$(CC) $(CFLAGS) GameObjectFactory.cpp

Explosion.o: Explosion.cpp Explosion.h DrawableObject.h Timer.h Sprite.h
	$(CC) $(CFLAGS) Explosion.cpp

Background.o: Background.cpp Background.h DrawableObject.h IUpdateable.h Sprite.h GamePlayObject.h Vector2D.h Settings.h
	$(CC) $(CFLAGS) Background.cpp

Sprite.o: Sprite.cpp Sprite.h
	$(CC) $(CFLAGS) Sprite.cpp

Timer.o: Timer.cpp Timer.h
	$(CC) $(CFLAGS) Timer.cpp

GamePlayObject.o: GamePlayObject.cpp GamePlayObject.h DrawableObject.h IUpdateable.h Sprite.h Vector2D.h
	$(CC) $(CFLAGS) GamePlayObject.cpp

DrawableObject.o: DrawableObject.cpp DrawableObject.h Sprite.h Vector2D.h
	$(CC) $(CFLAGS) DrawableObject.cpp

Vector2D.o: Vector2D.cpp Vector2D.h
	$(CC) $(CFLAGS) Vector2D.cpp

BlackScreen.o: BlackScreen.cpp BlackScreen.h DrawableObject.h Sprite.h
	$(CC) $(CFLAGS) BlackScreen.cpp

PlayerShip.o: PlayerShip.cpp PlayerShip.h Sprite.h IUpdateable.h DrawableObject.h GamePlayObject.h GameObjects.h StraightWeapon.h LazerWeapon.h Settings.h IWeapon.h
	$(CC) $(CFLAGS) PlayerShip.cpp

Enemy.o: Enemy.cpp Enemy.h GamePlayObject.h ExplosionFactory.h Vector2D.h Timer.h
	$(CC) $(CFLAGS) Enemy.cpp

BasicEnemy.o: BasicEnemy.cpp BasicEnemy.h Sprite.h IUpdateable.h DrawableObject.h GamePlayObject.h CollisionType.h Vector2D.h GameObjects.h Settings.h Enemy.h Behaviour.h
	$(CC) $(CFLAGS) BasicEnemy.cpp

WeaponEnemy.o:WeaponEnemy.cpp WeaponEnemy.h BasicEnemy.cpp BasicEnemy.h Sprite.h IUpdateable.h DrawableObject.h GamePlayObject.h CollisionType.h Vector2D.h GameObjects.h Settings.h Enemy.h IUpdateable.h
	$(CC) $(CFLAGS) WeaponEnemy.cpp

StraightProjectile.o: StraightProjectile.cpp StraightProjectile.h GamePlayObject.h DrawableObject.h Sprite.h Vector2D.h Projectile.h
	$(CC) $(CFLAGS) StraightProjectile.cpp

ProjectileFactory.o: ProjectileFactory.cpp ProjectileFactory.h Vector2D.h StraightProjectile.h GamePlayObject.h DrawableObject.h Sprite.h Vector2D.h GameObjectSpec.h
	$(CC) $(CFLAGS) ProjectileFactory.cpp

StraightWeapon.o: StraightWeapon.cpp StraightWeapon.h Vector2D.h ProjectileFactory.h StraightProjectile.h GamePlayObject.h DrawableObject.h Sprite.h Vector2D.h GameObjects.h GameObjectSpec.h IWeapon.h
	$(CC) $(CFLAGS) StraightWeapon.cpp

LazerWeapon.o: LazerWeapon.cpp LazerWeapon.h Vector2D.h ProjectileFactory.h StraightProjectile.h GamePlayObject.h DrawableObject.h Sprite.h Vector2D.h GameObjects.h GameObjectSpec.h IWeapon.h
	$(CC) $(CFLAGS) LazerWeapon.cpp

SpreadWeapon.o: SpreadWeapon.cpp SpreadWeapon.h Vector2D.h ProjectileFactory.h StraightProjectile.h GamePlayObject.h DrawableObject.h Sprite.h Vector2D.h GameObjects.h GameObjectSpec.h IWeapon.h MathsHelper.h
	$(CC) $(CFLAGS) SpreadWeapon.cpp

SpreadWeapon2.: SpreadWeapon2.cpp SpreadWeapon2.h SpreadWeapon2.h Vector2D.h ProjectileFactory.h StraightProjectile.h GamePlayObject.h DrawableObject.h Sprite.h Vector2D.h GameObjects.h GameObjectSpec.h IWeapon.h MathsHelper.h
	$(CC) $(CFLAGS) SpreadWeapon2.cpp

ExplosionFactory.o: ExplosionFactory.cpp ExplosionFactory.h Explosion.h DrawableObject.h Vector2D.h Sprite.h
	$(CC) $(CFLAGS) ExplosionFactory.cpp

CollisionDetector.o: CollisionDetector.cpp CollisionDetector.h Rectangle.h Circle.h GamePlayObject.h DrawableObject.h IUpdateable.h CollisionType.h Sprite.h Vector2D.h
	$(CC) $(CFLAGS) CollisionDetector.cpp

Rectangle.o: Rectangle.cpp Rectangle.h Vector2D.h
	$(CC) $(CFLAGS) Rectangle.cpp

SpecFactory.o: SpecFactory.cpp SpecFactory.h GameObjectSpec.h
	$(CC) $(CFLAGS) SpecFactory.cpp

Circle.o: Circle.cpp Circle.h Vector2D.h
	$(CC) $(CFLAGS) Circle.cpp

Obstacle.o: Obstacle.cpp Obstacle.h GamePlayObject.h DrawableObject.h IUpdateable.h CollisionType.h Sprite.h Vector2D.h
	$(CC) $(CFLAGS) Obstacle.cpp

SineBehaviour.o: SineBehaviour.cpp SineBehaviour.h Behaviour.h
	$(CC) $(CFLAGS) SineBehaviour.cpp

SplineBehaviour.o: SplineBehaviour.cpp SplineBehaviour.h Behaviour.h
	$(CC) $(CFLAGS) SplineBehaviour.cpp

VerticalLineBehaviour.o : VerticalLineBehaviour.cpp VerticalLineBehaviour.h Behaviour.h BasicEnemy.h MathsHelper.h
	$(CC) $(CFLAGS) VerticalLineBehaviour.cpp

BossBehaviourOne.o : BossBehaviourOne.cpp BossBehaviourOne.h Behaviour.h BasicEnemy.h MathsHelper.h
	$(CC) $(CFLAGS) BossBehaviourOne.cpp

MathsHelper.o: MathsHelper.cpp MathsHelper.h Vector2D.h
	$(CC) $(CFLAGS) MathsHelper.cpp

clean:
	rm *.o *~ mygame


