#include <vector>
#include <ostream>
#include <iostream>
/*
Simple drive command system
*/

class Car
{
    std::pair<int,int> pos;
    public:
    explicit Car(int x, int y):pos(x,y){};

    void MoveHor(int x)
    {
        pos.first +=x;
    }
    void Accelerate(int y)
    {
        pos.second +=y;
    } 
    std::pair<int,int> GetPosition() const 
    {
        return pos;
    }
};

struct command
{
    virtual void Forward()=0;
    virtual void Reverse()=0;
};

struct DriveCommand : command 
{
    Car& car;
    enum EAction{Left,Right,Accelerate,Decelerate} action;
    int speed;
    DriveCommand(Car& car,EAction Action,int speed):car{car},action{Action},speed{speed}{};
    void Forward() override
    {
        switch (action)
        {
        case Left:
            car.MoveHor(-speed);
            break;
        case Right:
            car.MoveHor(speed);
            break;
        case Accelerate:
            car.Accelerate(speed);
            break;
        case Decelerate:
            car.Accelerate(-speed);
            break;
        default:
            break;
        }
    }
    void Reverse() override {}
};


int main()
{
    Car MyCar(0,0);
    std::vector<DriveCommand> DriveCommands
    {
        DriveCommand{MyCar,DriveCommand::Accelerate,100},
        DriveCommand{MyCar,DriveCommand::Left,100},
        DriveCommand{MyCar,DriveCommand::Left,100},
        DriveCommand{MyCar,DriveCommand::Decelerate,100},
    };
    auto StartPos = MyCar.GetPosition();
    std::cout << "Start driving at: Pos X : " << StartPos.first << " Pos Y : " << StartPos.second << std::endl; 
    for(auto c : DriveCommands)
    {
        c.Forward();
    }
    std::cout << "Stop commands\n";
    std::cout << "Stop driving at: Pos X : " << MyCar.GetPosition().first << " Pos Y : " << MyCar.GetPosition().second << std::endl;
    return 0;
};