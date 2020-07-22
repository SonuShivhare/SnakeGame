#pragma once
#include<memory>
#include<stack>
#include"State.hpp"

typedef std::unique_ptr<State> stateRef;

class StateMachine
{
public:
	StateMachine();
	~StateMachine();
	void addState(stateRef newState, bool isRemoving = true);
	void removeState();
	void processStateChanges();
	stateRef& getActiveState();

private:
	std::stack<stateRef> states;
	stateRef newState;

	bool isAdding;
	bool isRemoving;
	bool isReplacing;
};

