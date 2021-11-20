#include "vehicle.h"
#include "parkingLot.h"
using namespace std;

void Veh::move(Vec d_vec) {
    anchor = anchor + d_vec;
    for (auto &i:look){
        i->move(d_vec);
    }
}

void Veh::rotate(float angle,Vec rot_cen){
    anchor = ((anchor-rot_cen) >> (angle*PI/180)) + rot_cen;
    for (auto &i:look){
        i->rotate(angle,rot_cen);
    }
    direction = direction - angle;
}

void Veh::draw(){
    for (auto i:look){
        i->draw();
    }
}

Veh::~Veh(){
    for (auto &i:look){
        delete i;
    }
}

Car::Car(Vec t_anchor){
    sizes* s=sizes::getInstance(); //get the size of the parking lot
    float unit=s->get_unit();
    float k= unit / 0.09f;
    float car_rect_height=0.03f*k, car_rect_length=0.1f*k, car_wheel_radium=0.01f*k, car_trap_upper_width=0.06f*k, car_trap_lower_width=0.08f*k;
    float car_trap_height=0.03f*k, car_distance_between_wheels=0.05f*k, car_flag_line_length=0.03f*k, car_flag_height=0.01f*k, car_flag_width=0.015f*k;
    condition = 0; direction = 0; flag_pos = 0; anchor = t_anchor;
    float r=0,g=0,b=0;
    Vec pt1=Vec(-car_rect_length/2,-car_rect_height/1.0f);
    Vec pt2=Vec(car_rect_length/2,-car_rect_height/1.0f);
    Vec pt3=Vec(car_rect_length/2,0);
    Vec pt4=Vec(-car_rect_length/2,0); //rectangle
    Quads* body=new Quads(anchor,pt1,pt2,pt3,pt4,r,g,b);
    body->paint();
    look.push_back(body);
    pt1=Vec(-car_trap_lower_width/2,0);
    pt2=Vec(car_trap_lower_width/2,0);
    pt3=Vec(car_trap_upper_width/2,car_trap_height);
    pt4=Vec(-car_trap_upper_width/2,car_trap_height); //trap
    Quads* window=new Quads(anchor,pt1,pt2,pt3,pt4,r,g,b);
    window->paint();
    look.push_back(window);
    pt1=anchor+Vec(-car_distance_between_wheels/2,-car_rect_height/1.0f);
    r = (float)rand()/(const float)RAND_MAX; g = (float)rand()/(const float)RAND_MAX; b = (float)rand()/(const float)RAND_MAX;
    Polygon* L_wheel=new Polygon(pt1,car_wheel_radium,360,3600,0,r,g,b);
    look.push_back(L_wheel); //left wheel
    pt1=anchor+Vec(car_distance_between_wheels/2,-car_rect_height/1.0f);
    Polygon* R_wheel=new Polygon(pt1,car_wheel_radium,360,3600,0,r,g,b);
    look.push_back(R_wheel); //right wheel
    pt1=Vec(-car_rect_length/2,0);
    pt2=pt1+Vec(0,car_flag_line_length);
    Line* flag_line=new Line(anchor,pt1,pt2,0,2,0,0,0);
    look.push_back(flag_line); //flag_line
    pt1=Vec(-car_rect_length/2-car_flag_width,car_flag_line_length-car_flag_height);
    pt2=pt1+Vec(car_flag_width,0);
    pt3=pt2+Vec(0,car_flag_height);
    pt4=pt3+Vec(-car_flag_width,0);
    Quads* flag=new Quads(anchor,pt1,pt2,pt3,pt4,1.0f,0,0);
    look.push_back(flag); //flag
    rotate(-90,anchor);
}

void Veh::calculate(){
    sizes* s=sizes::getInstance();set_condition();
    float now_x=anchor.getX(),now_y=anchor.getY(),unit=s->get_unit(),road_1_x=(s->get_road_1()).getX(),road_1_y=(s->get_road_1()).getY();
    float road_2_L_x=(s->get_road_2_L()).getX(),road_2_L_y=(s->get_road_2_L()).getY(),road_2_R_x=(s->get_road_2_R()).getX();
    if (condition==1){
        if (now_x==road_1_x&&now_y<road_1_y&&direction==90){
            if (road_1_y-0.02f*unit<now_y){
                move(Vec(0,road_1_y-now_y));
            }
            else{move(Vec(0,0.1f*(road_1_y-now_y)));}    
        }
        else if(now_y<=road_2_L_y&&direction>0){
            rotate(1,s->get_turning_1());
        }
        else if(now_x<road_2_R_x&&direction<90){
            float mid=(road_2_L_x+road_2_R_x)/2;
            if(road_2_R_x-0.01f*unit<now_x){
                move(Vec(road_2_R_x-now_x,0));
            }
            else if(abs(mid-now_x)<unit*2){
                move(Vec(0.005f/(2.0f*unit),0));
            }
            else {move(Vec(0.005f/abs(mid-now_x),0));}
        }
        else if(dest_con==2){
            move(Vec(0.01f*unit,0));
        }
        else if(direction<180){
            rotate(-1,s->get_turning_2());
        }
        else{move(Vec(-0.01f,0));}
    }
    else if(condition==2){
        if((int)direction%180==0&&now_x!=dest_rot_cen.getX()){
            if (abs(now_x-dest_rot_cen.getX())>0.01f*unit){
                move(Vec(0.05f*(dest_rot_cen.getX()-now_x),0));
            }
            else {
                move(Vec(dest_rot_cen.getX()-now_x,0));
            }
        }
        else if (direction!=90&&direction!=270){
            rotate(-1,dest_rot_cen);
        }
        else {move(Vec(0,0.01f*unit*(float)pow(-1,((int)direction/90)%3)));}
    }
}

void Veh::set_dest(Vec t_dest){
    sizes* s=sizes::getInstance();
    dest=t_dest;
    float mid_height=(s->get_turning_2()).getY();
    float unit=s->get_unit();
    if (dest.getY()<mid_height){
        dest_rot_cen=dest+Vec(unit,0.5f*unit);
        if(-dest.getX()+(s->get_turning_2()).getX()<unit){
            dest_con=2;
        }
        else{
            dest_con=0;
        }
    }
    else{
        dest_rot_cen=dest+Vec(-unit,-0.5f*unit);
        dest_con=1;
    }
    condition=1;
}

void Veh::set_condition(){
    if(dest_con==0||dest_con==2){
        if((anchor.getY()<=dest.getY())&&condition==2){
            condition=3;
        }
        else if(anchor.getX()>=dest.getX()&&direction<90){
            condition=2;
        }
    }
    else{
        if((anchor.getY()>=dest.getY())&&condition==2){
            condition=3;
        }
        else if(anchor.getX()<=dest.getX()&&direction>90){
            condition=2;
        }
    }
}

void Car::changing(){
    sizes* s=sizes::getInstance();
    static int flag=0;
    float k=(s->get_unit())/0.09f;
    float delta=0.001f*k;
    float angle=direction+90;
    float dx=delta*cos(angle*PI/180);
    float dy=delta*sin(angle*PI/180);
    if (flag==0&&flag_pos>=0){
        (look.back())->move(Vec(dx,dy));
        flag_pos--;
    }
    else if(flag_pos<=20){
        flag=1;flag_pos++;
        (look.back())->move(Vec(-dx,-dy));
    }
    else{
        flag=0;
    }
}

UFO::UFO(Vec t_anchor){
    sizes* s=sizes::getInstance();
    float unit=s->get_unit(), k=unit/0.13f;
    float ufo_radium=0.04f*k, ufo_line_length=0.04f*k, ufo_trap_upper_width=0.02f*k, ufo_trap_lower_width=0.03f*k, ufo_trap_height=0.02f*k;
    condition = 0; direction = 0; anchor = t_anchor;
    float r=0, g=0, b=0;
    Vec pt1 = anchor;
    Polygon* window = new Polygon(pt1,ufo_radium,180,1800,0,r,g,b);
    window->paint();
    look.push_back(window); //semicircle
    pt1=Vec(-ufo_radium*(float)cos(60*PI/180),ufo_radium*(float)sin(60*PI/180));
    Vec pt2=pt1+Vec(-ufo_line_length*(float)cos(60*PI/180),ufo_line_length*(float)sin(60*PI/180));
    r = (float)rand()/(const float)RAND_MAX; g = (float)rand()/(const float)RAND_MAX; b = (float)rand()/(const float)RAND_MAX;
    Line* L_line=new Line(anchor,pt1,pt2,0,2,r,g,b);
    look.push_back(L_line); //left line
    pt1=Vec(ufo_radium*(float)cos(60*PI/180),ufo_radium*(float)sin(60*PI/180));
    pt2=pt1+Vec(ufo_line_length*(float)cos(60*PI/180),ufo_line_length*(float)sin(60*PI/180));
    Line* R_line=new Line(anchor,pt1,pt2,0,2,r,g,b);
    look.push_back(R_line); //right line
    pt1=Vec(-ufo_radium/2-ufo_trap_upper_width/2,0);
    pt2=Vec(-ufo_radium/2-ufo_trap_lower_width/2,-ufo_trap_height);
    Vec pt3=Vec(-ufo_radium/2+ufo_trap_lower_width/2,-ufo_trap_height);
    Vec pt4=Vec(-ufo_radium/2+ufo_trap_upper_width/2,0);
    r = (float)rand()/(const float)RAND_MAX; g = (float)rand()/(const float)RAND_MAX; b = (float)rand()/(const float)RAND_MAX;
    Quads* L_engine=new Quads(anchor,pt1,pt2,pt3,pt4,r,g,b);
    look.push_back(L_engine); //left trap
    pt1=Vec(ufo_radium/2-ufo_trap_upper_width/2,0);
    pt2=Vec(ufo_radium/2-ufo_trap_lower_width/2,-ufo_trap_height);
    pt3=Vec(ufo_radium/2+ufo_trap_lower_width/2,-ufo_trap_height);
    pt4=Vec(ufo_radium/2+ufo_trap_upper_width/2,0);
    Quads* R_engine=new Quads(anchor,pt1,pt2,pt3,pt4,r,g,b);
    look.push_back(R_engine); //right trap
    rotate(-90,anchor);
}

void UFO::changing(){
    if (condition!=3){
        for (auto &i:look){
           i->rotate(-5,anchor);
        }
    }
}

Rocket::Rocket(Vec t_anchor){
    sizes* s=sizes::getInstance();
    float unit=s->get_unit(), k=unit/0.15f, rocket_body_length=0.1f*k, rocket_body_width=0.05f*k, rocket_head_height=0.03f*k;
    float rocket_wing_length=0.03f*k, rocket_wing_width=0.015f*k, rocket_wing_difference=0.015f*k, rocket_fire_upper_length=0.03f*k;
    float rocket_fire_lower_length=0.04f*k, rocket_fire_height=0.02f*k;
    condition = 0; direction = 90; engine_pos = 0; anchor=t_anchor;
    float r = 0, g = 0, b = 0;
    Vec pt1=Vec(-rocket_body_width/2,-rocket_body_length/2);
    Vec pt2=Vec(rocket_body_width/2,-rocket_body_length/2);
    Vec pt3=Vec(rocket_body_width/2,rocket_body_length/2);
    Vec pt4=Vec(-rocket_body_width/2,rocket_body_length/2);
    Quads* body=new Quads(anchor,pt1,pt2,pt3,pt4,r,g,b);
    body->paint(); look.push_back(body); //body
    pt1=Vec(-rocket_body_width/2,rocket_body_length/2);
    pt2=Vec(rocket_body_width/2,rocket_body_length/2);
    pt3=Vec(0,rocket_body_length/2+rocket_head_height);
    Triangle* head=new Triangle(anchor,pt1,pt2,pt3,r,g,b);
    head->paint(); look.push_back(head); //head
    pt1=Vec(-rocket_body_width/2,rocket_wing_length-rocket_body_length/2);
    pt2=Vec(-rocket_body_width/2-rocket_wing_width,rocket_wing_length-rocket_body_length/2-rocket_wing_difference);
    pt3=Vec(-rocket_body_width/2-rocket_wing_width,-rocket_body_length/2-rocket_wing_difference);
    pt4=Vec(-rocket_body_width/2,-rocket_body_length/2);
    r = (float)rand()/(const float)RAND_MAX; g = (float)rand()/(const float)RAND_MAX; b = (float)rand()/(const float)RAND_MAX;
    Quads* L_wing=new Quads(anchor,pt1,pt2,pt3,pt4,r,g,b);
    look.push_back(L_wing); //left wing
    pt1=Vec(rocket_body_width/2,rocket_wing_length-rocket_body_length/2);
    pt2=Vec(rocket_body_width/2+rocket_wing_width,rocket_wing_length-rocket_body_length/2-rocket_wing_difference);
    pt3=Vec(rocket_body_width/2+rocket_wing_width,-rocket_body_length/2-rocket_wing_difference);
    pt4=Vec(rocket_body_width/2,-rocket_body_length/2);
    Quads* R_wing=new Quads(anchor,pt1,pt2,pt3,pt4,r,g,b);
    look.push_back(R_wing); //right wing
    pt1=Vec(-rocket_fire_upper_length/2,0);
    pt2=Vec(-rocket_fire_lower_length/2,-rocket_fire_height);
    pt3=Vec(rocket_fire_lower_length/2,-rocket_fire_height);
    pt4=Vec(rocket_fire_upper_length/2,0);
    Quads* fire=new Quads(anchor+Vec(0,-rocket_body_length/2),pt1,pt2,pt3,pt4,r,g,b);
    fire->paint(); look.push_back(fire); //fire
}

void Rocket::changing(){
    static int flag=0;
    if (condition!=3){
        if(flag==0&&engine_pos>=0){
            (look.back())->zoom(1.1f);
            engine_pos--;
        }
        else if(engine_pos<=10){
            flag=1;engine_pos++;
            (look.back())->zoom(1.0f/1.1f);
        }
        else {
            flag=0;
        }
    }
}
