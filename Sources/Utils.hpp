#pragma once

namespace Utils {

class ScopedCaller
{
public:
	ScopedCaller(std::function<void()> i_f)
		: m_f(std::move(i_f))
	{
		if (!noexcept(i_f))
			throw std::logic_error("noexcept function expected");
	}
	~ScopedCaller()
	{
		m_f();
	}
private:
	std::function<void()> m_f;
};

} // namespace Utils
