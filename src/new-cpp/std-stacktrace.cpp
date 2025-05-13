import std;

///////////////////////////////////////////////////////////////////////////

// The std::stacktrace stack trace is an object in programming that keeps track of the called functions till a particular point in the program. It keeps a log of the stack frames currently present in the function call stack of the program.

// c++ std::stacktrace_entry represents the record of a single stack frame in the function call stack.

// c++ std::stacktrace class is the actual class that keeps the records of the stack frames along with their sequence of execution.

///////////////////////////////////////////////////////////////////////////
// std::stacktrace::current(skip, max_depth, alloc);
// std::stacktrace::current(skip, alloc);
// std::stacktrace::current(alloc);
//				static method

namespace my_space
{
	class my_class
	{
	public:
		virtual ~my_class()
		{
			{
				std::stacktrace stacktrace{std::stacktrace::current()};
				std::cout << "----------------------------------------\n";
				std::cout << "size: " << stacktrace.size() << std::endl;
				std::cout << "possible max size: " << stacktrace.max_size() << std::endl;
				std::cout << "empty: " << std::boolalpha << stacktrace.empty() << std::endl;
				std::cout << stacktrace << std::endl;
				std::cout << "At 3: " << stacktrace[3] << std::endl;
				std::cout << "range-based for loop:" << std::endl;
				for (const std::stacktrace_entry & x: stacktrace)
					std::cout << x << std::endl;
			}
			{
				std::stacktrace stacktrace{std::stacktrace::current(0, 1000)};
				std::cout << "Real max size: " << stacktrace.size() << std::endl;
			}
			{
				std::stacktrace stacktrace = std::stacktrace::current(2, 3);
				std::cout << "----------------------------------------\n";
				std::cout << "From 2 to 2+3:\n";
				std::cout << stacktrace << std::endl;
				std::cout << "std::to_string:" << std::endl << std::to_string(stacktrace) << std::endl;
			}
		}
	};
}

int main()
{
	my_space::my_class my_object;
}
