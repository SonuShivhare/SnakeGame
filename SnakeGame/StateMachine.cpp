#include "StateMachine.hpp"

StateMachine::StateMachine()
{
	isAdding = false;
	isRemoving = false;
	isReplacing = true;
}

StateMachine::~StateMachine()
{
}

void StateMachine::addState(stateRef newState, bool isReplacing)
{
	this->isAdding = true;
	this->isReplacing = isReplacing;
	this->newState = std::move(newState);
}

void StateMachine::removeState()
{
	this->isRemoving = true;
}

void StateMachine::processStateChanges()
{
	if (this->isRemoving && !states.empty())
	{
		this->states.pop();
		/*if (!this->states.empty())
		{
			this->states.top()->resume();
		}*/
		this->isRemoving = false;
	}

	if (this->isAdding)
	{
		if (isReplacing && !states.empty())
		{
			this->states.pop();
		}
		/*else if (!states.empty())
		{
			this->states.top()->pause();
		}*/
		this->states.push(std::move(this->newState));
		this->states.top()->init();
		this->isAdding = false;
	}

	
}

stateRef& StateMachine::getActiveState()
{
	return this->states.top();
}
