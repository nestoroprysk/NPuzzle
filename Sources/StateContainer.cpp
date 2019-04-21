#include "StateContainer.hpp"

#include <string>

void StateContainer::add()
{

}

void StateContainer::remove()
{

}

bool StateContainer::empty() const
{
	return false;
}

bool StateContainer::contains() const
{
	return false;
}

State const& StateContainer::getBestState() const
{
	static const std::string s = "unimplemented";
	static const State ss(s);
	return ss;
}
