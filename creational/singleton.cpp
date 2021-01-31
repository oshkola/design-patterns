class Singleton
{
	Singleton() = default;

public:
	//public + delete provides clear error messages
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	//lazy initialization of _instance
	static Singleton& get_instance()
	{
  		//static + local variable does the trick  
        static Singleton _instance;
		return _instance;
	}
};

int main()
{
	Singleton& s = Singleton::get_instance();
}