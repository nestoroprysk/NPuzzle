#pragma once

#include <string>

namespace Solver {

struct Result
{
	bool m_success = false;
	// TODO: add path
};

Result solve(std::string const& i_file_content);

} // namespace Solver
