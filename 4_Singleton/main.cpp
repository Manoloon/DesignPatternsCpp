#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>

class DatabaseInterface
{
  public:
  virtual int getPopulation(const std::string& cityName) = 0;
};
class SingletonDB : public DatabaseInterface
{
  SingletonDB()
  {
    std::cout << " Initialize DataBase\n";
    std::ifstream ifs("data.txt");
     if (!ifs.is_open())
        {
            std::cerr << "Error: File 'data.txt' does not exist or cannot be opened.\n";
            return;
        }
    std::string d1,d2;
    while (std::getline(ifs,d1))
    {
      std::getline(ifs,d2);
      int pop = std::stoi(d2);
      std::cout << d1 << " : " << pop << std::endl;
      Data[d1] = pop;
    }
  }
  std::map<std::string,int> Data;

  public:
  SingletonDB(SingletonDB const&) = delete;
  void operator =(SingletonDB const&) = delete;

  static SingletonDB& get()
  {
    static SingletonDB db;
    return db;
  }
  int getPopulation(const std::string& City)
  {
    return Data[City];
  }
};

// dummy DB to be used for TEST 
// the main problem here is with this we can have unit test for the singletonDB.
class DummyDB : public DatabaseInterface
{
  std::map<std::string, int> Data;
  DummyDB()
  {
    Data["City1"] = 1;
    Data["City2"] = 2;
    Data["City3"] = 3;
  }
  public:
  int getPopulation(const std::string& city) override
  {
    return Data[city];
  }
};
// meant to be use for TEST 
struct SingletonRecordFinder
{
    int totalPopulation(std::vector<std::string> cityNames)
    {
        int result{0};
        for(auto name : cityNames)
        {
            result +=SingletonDB::get().getPopulation(name);
        }
        return result;
    }
};

struct ConfigurableRecordFinder
{
  DatabaseInterface& db;
  ConfigurableRecordFinder(DatabaseInterface& db):db(db){}

  int totalPopulation(std::vector<std::string> cityNames)
    {
        int result{0};
        for(auto name : cityNames)
        {
            result += db.getPopulation(name);
        }
        return result;
    }
};

int main()
{
  std::string city = "Tokyo";
  int population = SingletonDB::get().getPopulation(city);
  std::cout << city << " has population of : " << population << std::endl;
  return 0;
}