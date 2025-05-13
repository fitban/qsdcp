import std;

namespace my_space
{
	class my_base_class
	{
	public:
		void print(const std::stacktrace & stacktrace) const
		{
			for (const std::stacktrace_entry & frame: stacktrace)
			{
				std::cout << frame << "\n=>" << std::endl;
				if (! frame)
					std::cout << "<This frame is empty>" << std::endl;
				std::cout
					<< "\tdescription: " << frame.description() << '\n'
					<< "\tsource file: " << frame.source_file() << '\n'
					<< "\tsource line: " << frame.source_line() << '\n'
				;
			}
		}
	public:
		virtual ~my_base_class()
		{
		}
	};

	class my_derived_class: virtual public my_base_class
	{
	public:
		~my_derived_class()
		{
			std::stacktrace stacktrace = std::stacktrace::current();
			std::cout << "----------------------------------------" << std::endl;
			std::cout << stacktrace << std::endl;
			std::cout << "----------------------------------------" << std::endl;
			this->print(stacktrace);
		}
	};
}

int main()
{
	auto ptr = new my_space::my_derived_class;
	delete ptr;
	ptr = nullptr;
	std::cout << "---- returned ----\n";
}
