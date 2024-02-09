#include <string>
#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

class CodeBuilder
{
public:
    CodeBuilder(const string& class_name):Class_name(class_name){}
    string Class_name;
    vector<pair<string,string>> data;
    
    CodeBuilder& add_field(const string& name, const string& type)
    {
        data.push_back(make_pair(name,type));
        return *this;
    }

    friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
    {
        os << "class " << obj.Class_name << std::endl << "{" << std::endl;
        for(const auto& d : obj.data){
            os  << "  "<< d.second << " " << d.first << ";" << std::endl;
            }
        os << "};" << std::endl;
        return os; 
    }
};

int main(){
    auto cb = CodeBuilder{"Pablo"}.add_field("name", "string").add_field("age", "int");
    cout << cb;
return 0;
}