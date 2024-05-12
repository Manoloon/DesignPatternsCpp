#include <iostream>
#include <map>
#include <string>
#include <fstream>

class SingletonDB
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
int main()
{
  std::string city = "Tokyo";
  int population = SingletonDB::get().getPopulation(city);
  std::cout << city << " has population of : " << population << std::endl;
  return 0;
}