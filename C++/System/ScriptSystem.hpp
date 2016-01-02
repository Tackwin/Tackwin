#ifndef SCRIPTSYSTEMHPP
#define SCRIPTSYSTEMHPP

#include "Script.hpp"

class ScriptSystem : public entityx::System<ScriptSystem> {
private:
	entityx::ComponentHandle<Script> script;
public:
	ScriptSystem();
	~ScriptSystem();

	void update(entityx::EntityManager &enm, entityx::EventManager &evm, entityx::TimeDelta delta);
	bool paused = false;
};

#endif
