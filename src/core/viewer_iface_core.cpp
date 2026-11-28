#include "viewer_iface.h"
#include "util.h"
#include "level.h"
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