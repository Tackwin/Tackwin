#include "ScriptSystem.hpp"

ScriptSystem::ScriptSystem()
{
}


ScriptSystem::~ScriptSystem()
{
}

bool compareScript(const ScriptInfo &A, const ScriptInfo &B) {
	return A.priority < B.priority;
}

void ScriptSystem::update(entityx::EntityManager &enm, entityx::EventManager &evm, entityx::TimeDelta delta) {
	for(auto E : enm.entities_with_components<Script>(script)) {
		for(int i = 0; i < script->scripts.size(); i++) {
			auto &it = script->scripts[i];
			Clock &c = it.internalClock;
			if(paused && !c.isPaused()) c.pause();
			if(!paused && c.isPaused()) c.start();
			if(!c.isPaused() && c.elapsed() >= it.timer) {
				it.internalClock.restart();
				if(script->scripts[i].script(E)) {
					script->scripts.erase(script->scripts.begin() + i);
					i--;
				}
			}
		}
	}
}
