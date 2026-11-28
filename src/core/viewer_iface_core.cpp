#include "viewer_iface.h"
#include "util.h"
#include "level.h"
#include "state.h"
#include <iostream>
using namespace std;

// Terminal UI and dashboard rendering using primitive parameters

void renderDashboard(int playerFloor, int playerRoom, int energy, int time, int score,
                     const char inventory[MAX_INVENTORY_CAPACITY], int inventoryCount,
                     int emergencyTripsLeft){
                        cout<<"THE LAST TRAIN"<<endl;
                        cout<<"Location: Floor "<<playerFloor<<", Room "<<playerRoom<<endl;
                        cout<<"Energy: "<<energy<<"/100"<<endl;
                        cout<<"Time: "<<time<<"/50"<<endl;
                        cout<<"Score: "<<score<<endl;
                        cout<<"Emergency Lift 2 Trips Left: "<<emergencyTripsLeft<<endl;
                        cout<<"Inventory: "<<endl;

                        if (inventoryCount==0) {
                            cout<<"None";
                        }
                        else {
                            for (int i=0; i<inventoryCount; ++i) {
                                cout<<getEntityName(inventory[i]);
                                if (i<inventoryCount-1) {
                                    cout<<", ";
                                }
                            }
                        }
                     }



void renderRoomDetails(int floor, int room,
                       const char roomEntities[NUM_FLOORS][ROOMS_PER_FLOOR][MAX_ENTITIES_PER_ROOM],
                       int entityCount){
                        cout<<"Current Floor: "<<floor<<", Room: "<<room<<endl;

                        if (entityCount==0) {
                            cout<<"The Room Is Empty"<<endl;
                        }
                        else {
                            cout<<"Entities in this room: "<<endl;
                            for (int i=0; i<entityCount; ++i) {
                                cout<<getEntityName(roomEntities[floor-1][room-1][i])<<endl;
                            }
                        }


                       }



void renderObjectivesChecklist(const bool objectives[NUM_OBJECTIVES]){
    printHeader("OBJECTIVES");
    cout<<"1. Master Key: "<<(objectives[OBJ_MASTER_KEY] ? "[X]" : "[ ]")<<endl;
    cout<<"2. Clue digit4: "<<(objectives[OBJ_CLUE_4] ? "[X]" : "[ ]")<<endl;
    cout<<"3. Clue digit2: "<<(objectives[OBJ_CLUE_2] ? "[X]" : "[ ]")<<endl;
    cout<<"4. Clue digit7: "<<(objectives[OBJ_CLUE_7] ? "[X]" : "[ ]")<<endl;
    cout<<"5. Cabinet Unlocked: "<<(objectives[OBJ_CABINET_UNLOCKED] ? "[X]" : "[ ]")<<endl;
    cout<<"6. Train Key: "<<(objectives[OBJ_TRAIN_KEY] ? "[X]" : "[ ]")<<endl;
    cout<<"7. Fuse Collected: "<<(objectives[OBJ_FUSE_COLLECTED] ? "[X]" : "[ ]")<<endl;
    cout<<"8. Fuse Installed: "<<(objectives[OBJ_FUSE_INSTALLED] ? "[X]" : "[ ]")<<endl;
    cout<<"9. Lift Pass: "<<(objectives[OBJ_LIFT_PASS] ? "[X]" : "[ ]")<<endl;
    cout<<"10. Lift 2 Active: "<<(objectives[OBJ_LIFT2_ACTIVE] ? "[X]" : "[ ]")<<endl;
    cout<<"11. Passenger Rescued: "<<(objectives[OBJ_PASSENGER_RESCUED] ? "[X]" : "[ ]")<<endl;
    cout<<"12. Cat Carrier: "<<(objectives[OBJ_CAT_CARRIER] ? "[X]" : "[ ]")<<endl;
    cout<<"13. Cat Secured: "<<(objectives[OBJ_CAT_SECURED] ? "[X]" : "[ ]")<<endl;
    cout<<"14. Train Prepared: "<<(objectives[OBJ_TRAIN_PREPARED] ? "[X]" : "[ ]")<<endl;
    cout<<"15. Mission Won: "<<(objectives[OBJ_MISSION_WON] ? "[X]" : "[ ]")<<endl;
    cout<<"16. Mission Failed: "<<(objectives[OBJ_MISSION_FAILED] ? "[X]" : "[ ]")<<endl;
}




void renderAsciiBuilding(int playerFloor, int playerRoom){
    for (int floor=5; floor>=1; floor--){
        cout<<"F"<<floor<<endl;
        for (int room=1; room<=4; room++){
            if (floor==playerFloor && room==playerRoom)
                cout<<"[P]"<<endl;
            else
                cout<<"[R"<<room<<"]"<<endl;
            }
        }
    }
