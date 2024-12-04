#include <iostream>
#include <string>
using namespace std;

struct Renderer
{
    virtual string what_to_render_as() const = 0;
    virtual ~Renderer() = default;
};

struct Shape
{
    protected:
        Renderer& renderer;
        string name;
    public:
    Shape(Renderer& renderer, const std::string& Name) : renderer(renderer),name(Name){}
    virtual string str() const =0;
    virtual ~Shape() = default;
    
};

struct Triangle : Shape
{
    Triangle(Renderer& renderer) : Shape(renderer,"Triangle"){}
    string str() const override 
    {
        return "Drawing " + name + " as " + renderer.what_to_render_as();
    }
};

struct Square : Shape
{
    Square(Renderer& renderer) : Shape(renderer,"Square"){}

    string str() const override
    {
        return "Drawing " + name + " as " + renderer.what_to_render_as();
    }
};

// imagine e.g. VectorTriangle/RasterTriangle etc. here
struct VectorRenderer : Renderer 
{
    string what_to_render_as() const override 
    {
        return "lines";
    }
};

struct RasterRenderer : Renderer 
{
    string what_to_render_as() const override 
    {
        return "pixels";
    }
};
