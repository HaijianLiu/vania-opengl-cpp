
#ifndef Boss_hpp
#define Boss_hpp

enum skill { DEATH_BITE, DEATH_AREA, SKILL_MAX, NONE_SKILL, DEATH_AREA_LEFT, DEATH_AREA_RIGHT };

class Boss : public GameObject {
private:

public:
	// Collider
	BoxCollider* collider;
	// OffsetObject
	OffsetObject* leftTarget;
	OffsetObject* rightTarget;

	// GameObject
	BossCore* core;
	std::vector<BossDeathWall*> deathWallsLeft;
	std::vector<BossDeathWall*> deathWallsRight;
	std::vector<BossBullet*> bullets;
	BossDeathBite* deathBite;
	// UIObject
	UIObject* uiBossBG;
	UIObject* uiLife;

	// Target
	GameObject* target;

	// Parameter
	float sleepHP = 100.0f;
	float hp = 1500.0f;
	float deathWallRange = 1.6f;
	float deathAreaTime = 3.0f;
	float deathBiteTime = 2.0f;
	float skillColdDown = 5.0f;
	float skillDelay = 1.0f;
	float bulletColdDown = 15.0f;

	// status
	bool awake = false;
	bool alive = true;
	bool intro = false;
	int currentSkill = NONE_SKILL;
	float lastSkill = 0;
	float lastBullet = 0;
	int phase = 0;

	// Constructors
	Boss ();
	~Boss();

	// virtual Functions
	void start();
	void update();
	void onTriggerEnter(BoxCollider* other);
	void reset();

	// Functions
	void checkSkill();
};

#endif /* Boss_hpp */
