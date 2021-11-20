#include "header.h"
int main(){
    srand((unsigned)time(nullptr));
    P_area Parking_lot;
    Parking_lot.show();
    time_t now=time(nullptr);
    for (int i=1;i<=50;i++){
        switch (rand()%6){
            case 0:{
                car* new_car=new car;        
                Parking_lot.enter(new_car);  
                break;
            }
            case 1:{
                van* new_van=new van;        
                Parking_lot.enter(new_van); 
                break;
            }
            case 2:{
                bicycle* new_bicycle=new bicycle;        
                Parking_lot.enter(new_bicycle); 
                break;
            }
            case 3:{
                motorbike *new_motorbike = new motorbike;
                Parking_lot.enter(new_motorbike); 
                break;
            }
        }
        Parking_lot.leave();
        while(now+1>time(nullptr)){}
        now++;
    }
    return 0;
}
