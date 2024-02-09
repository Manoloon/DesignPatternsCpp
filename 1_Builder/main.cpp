#include <string>
#include <ostream>
using namespace std;

class CodeBuilder
{
public:
    CodeBuilder(const string& class_name)
    {
        string Class_name;
    }

    CodeBuilder& add_field(const string& name, const string& type)
    {

    }

    friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
    {
        // todo
    }
};

int main(){
    auto cb = CodeBuilder{"Person"}.add_field("name", "string").add_field("age", "int");
    cout << cb;
return 0;
}