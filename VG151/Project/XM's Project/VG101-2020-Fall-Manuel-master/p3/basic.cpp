#include "header.h"
motorbike::motorbike(){
    type="motorbike";
    price=2;
    seconds=rand()%5+5;
    plate=digit[rand()%26];
    for (int i=1;i<=3;i++){
        plate=plate+to_string(rand()%10);
    }
}

bicycle::bicycle(){
    type="bicycle";
    price=1;
    seconds=rand()%5+5;
    plate=digit[rand()%26];
    for (int i=1;i<=2;i++){
        plate=plate+to_string(rand()%10);
    }
}

van::van(){
    type="van";
    price=4;
    seconds=rand()%5+5;
    plate=digit[rand()%26];
    for (int i=1;i<=4;i++){
        plate=plate+to_string(rand()%10);
    }
}

car::car(){
    type="car";
    price=3;
    seconds=rand()%5+5;
    plate=digit[rand()%26];
    for (int i=1;i<=4;i++){
        plate=plate+to_string(rand()%10);
    }
}

string Vehicle::get_type(){
    return type;
}

int Vehicle::get_price(){
    return price;
}

int Vehicle::get_seconds(){
    return seconds;
}

string Vehicle::get_plate(){
    return plate;
}

void car::cry(){
    cout<<"---------------------------"<<endl;
    cout<<"Car "<<plate<<" cries:Queuing is an insult to such a handsome car like me!"<<endl;
    cout<<"---------------------------"<<endl;
}

void van::cry(){
    cout<<"---------------------------"<<endl;
    cout<<"Van "<<plate<<" cries: Let me rush into the parking lot! BANG BANG!"<<endl;
    cout<<"---------------------------"<<endl;
}

void bicycle::cry(){
    cout<<"---------------------------"<<endl;
    cout<<"Bicycle "<<plate<<" cries: Why should a bike waiting together with big cars!"<<endl;
    cout<<"---------------------------"<<endl;
}

void motorbike::cry(){
    cout<<"---------------------------"<<endl;
    cout<<"Motor "<<plate<<" cries: Oh shit."<<endl;
    cout<<"---------------------------"<<endl;
}

Slot::Slot(char floor,int seq){
    empty=true;
    pos=floor+to_string(seq);
}

void Slot::leave(){
    if ((!empty)&&leave_time<=time(nullptr)){
        cout<<"---------------------------"<<endl;
        cout<<"Leaving ticket"<<endl;
        cout<<"Car type: "<<this_veh->get_type()<<endl;
        cout<<"Plate: "<<this_veh->get_plate()<<endl;
        cout<<"Parking time: ";
        cout<<this_veh->get_seconds()/60<<" minutes ";
        cout<<this_veh->get_seconds()%60<<" seconds"<<endl;
        cout<<"Price: "<<this_veh->get_price()*this_veh->get_seconds()<<endl;
        cout<<"Thanks for coming!"<<endl;
        cout<<"---------------------------"<<endl;

        delete this_veh;
        empty=true;
        enter_time=0;
        leave_time=0;
    }
}

void Slot::enter(Vehicle* target){    
    this_veh=target;
    enter_time=time(nullptr);
    leave_time=enter_time+this_veh->get_seconds();
    empty=false;
    
    cout<<"---------------------------"<<endl;
    cout<<"Arrival ticket"<<endl;
    cout<<"Arrival time: "<<asctime(localtime(&enter_time));
    cout<<"Type: "<<this_veh->get_type()<<endl;
    cout<<"Plate: "<<this_veh->get_plate()<<endl;
    cout<<"Slot_number: "<<pos<<endl;
    cout<<"---------------------------"<<endl;
}

bool Slot::get_condition(){
    return empty;
}

Slot::~Slot(){
    if (!empty){
        delete this_veh;
    }
}

P_area::P_area(){
    for (int i=1;i<=rand()%3+2;i++){
        vector<Slot*> a;
        for (int j=1;j<=rand()%3+1;j++){
            Slot* temp=new Slot((char)digit[i-1],j);
            a.push_back(temp);
        }
        head.push_back(a);
    }
}

void P_area::enter(Vehicle* target){
    if (queue.size()==0){
        for (auto &i:head){
            for (auto &j:i){
                if (j->get_condition()){
                    j->enter(target);
                    return;
                }
            }
        }
        queue.push_back(target);
        target->cry();
    }
    else {
        queue.push_back(target);
        target->cry();
        for (auto &i:head){
            for (auto &j:i){
                if (j->get_condition()){
                    j->enter(queue.front()); 
                    queue.erase(queue.begin());    
                    return;
                }
            }
        }
    }
}

void P_area::leave(){
    for (auto &i:head){
        for (auto &j:i){
            j->leave();            
        }
    }
}

void P_area::show(){
    int a=0;
    for (auto i:head){
        for (auto j:i){
            if(0){j++;}
            a++;
        }
    }
    cout<<"---------------------------"<<endl;
    cout<<"Qi Ling's Fantastic Parking is built!"<<endl;
    cout<<"It has "<<head.size()<<" floors!"<<endl;
    cout<<"It has "<<a<<" slots in total!"<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"Print enter to continue...";
    if(cin.get()){}
}

P_area::~P_area(){
    for (auto &i:queue){
        delete i;
    }
    for (auto &i:head){
        for (auto &j:i){
            delete j;
        }
    }
}
