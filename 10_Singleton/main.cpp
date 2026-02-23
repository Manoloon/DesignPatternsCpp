#include <iostream>
#include <memory>
#include <map>
#include <string>
/*
	Multiton
*/
enum class importance
{
	primary,
	secondary,
	tertiary
};
class Test
{
	public:
		void Print()
	{
		std::cout << "my address is :" << this << std::endl;
	}
};
class Singleton
{
	Singleton()=default;
	Singleton(const Singleton& s)=delete;
	~Singleton()=default;
	Singleton operator=(const Singleton& s)=delete;
public:
	static Singleton* GetInstance()
	{
		static Singleton instance;
		return &instance;
	}
	void Print()
	{
		std::cout << "my address is :" << this << std::endl;
	}
};
namespace single
{
	Test test;

	void Print()
	{
		std::cout << "my address is :" << &test << std::endl;
	}
}
template<typename T,typename Key = std::string>
class Multiton
{
public:
	static std::shared_ptr<T> get(const Key& key)
	{
		if(const auto it = instances.find(key);
			it != instances.end())
			{
				return it->second;
			}
		auto instance = std::make_shared<T>();
		instances[key] = instance;
		return instance;
	}
protected:
	Multiton() =default;
	virtual ~Multiton() =default;
private:
	static std::map<Key,std::shared_ptr<T>> instances;
};

 template<typename T,typename Key>
 std::map<Key,std::shared_ptr<T>> Multiton<T,Key>::instances;
 
class Printer
{
public:
	Printer()
	{
		++Printer::totalInstanceCount;
		std::cout << "Total of :" << 
		Printer::totalInstanceCount << 
		" instances created\n";
	}
private:
	static int totalInstanceCount;
};
int Printer::totalInstanceCount = 0;

int main()
{
	typedef Multiton<Printer,importance> mt;
	
	auto main = mt::get(importance::primary);
	auto aux = mt::get(importance::secondary);
	auto aux2 = mt::get(importance::secondary);
	auto aux3 = mt::get(importance::tertiary);
	auto s = Singleton::GetInstance();
	auto d = Singleton::GetInstance();
	std::cout << "Testing singleton class" << std::endl;
	s->Print();
	d->Print();
	std::cout << "Testing namespace as singleton" << std::endl;
	single::Print();
	single::Print();
	single::Print();
	single::Print();
}