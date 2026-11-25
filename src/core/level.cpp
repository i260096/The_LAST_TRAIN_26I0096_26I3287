#include "level.h"
#include "util.h"
#include <fstream>
#include <cstring>
// Modular implementation using primitive arrays for map parsing and verification


const char* getEntityName(char entitySymbol){
    switch (entitySymbol){
        case ENT_MASTER_KEY:
            return "Master Key";
        case ENT_ENERGY_PACK:
            return "Energy Pack";
        case ENT_EMERGENCY_TOOLKIT:
            return "Emergency Toolkit";
        case ENT_CLUE_4:
            return "Clue 4";
        case ENT_FUSE:
            return "Fuse";
        case ENT_CAT:
            return "Stranded Cat";
        case ENT_CONTROL_PANEL:
            return "Control Panel Terminal";
        case ENT_LIFT_PASS:
            return "Lift Pass";
        case ENT_PASSENGER:
            return "Stranded Passenger";
        case ENT_MEDICAL_KIT:
            return "Medical Kit";
        case ENT_EMERGENCY_CARD:
            return "Emergency Access Card";
        case ENT_CLUE_2:
            return "Clue 2";
        case ENT_CLUE_7:
            return "Clue 7";
        case ENT_CABINET_TRAIN_KEY:
            return "Cabinet / Train Key";
        case ENT_CAT_CARRIER:
            return "Cat Carrier";
        case ENT_OBSERVATION_TOKEN:
            return "Observation Token";
        default:
            return "Nothing";
    }
}



bool loadBuildingMap(const char* filename,
                     char horizontalConn[NUM_FLOORS][ROOMS_PER_FLOOR - 1],
                     char roomEntities[NUM_FLOORS][ROOMS_PER_FLOOR][MAX_ENTITIES_PER_ROOM],
                     int entityCounts[NUM_FLOORS][ROOMS_PER_FLOOR]){
                        std::ifstream
                        inputFile(filename);

                        if (!inputFile){
                            return false;//file not opened
                        }
                        
                        for (int floor=0; floor<NUM_FLOORS; ++floor) {
                            for (int connection=0; connection<ROOMS_PER_FLOOR-1; ++connection) {
                                horizontalConn[floor][connection]=CONN_NONE;                            }
                        }
                        
                        for (int floor=0; floor<NUM_FLOORS; ++floor) {
                            for (int room=0; room<ROOMS_PER_FLOOR; ++room) {
                                entityCounts[floor][room]=0;
                                for (int entity=0; entity<MAX_ENTITIES_PER_ROOM; ++entity) {
                                    roomEntities[floor][room][entity]=ENT_NONE;
                                }
                            }
                        }

                        char line[MAX_LINE_LEN];
                        
                        while (inputFile.getline(line, MAX_LINE_LEN)) {
                            trimWhitespace(line);
                            if (line[0]=='#' || line[0]=='\0') {
                                continue; //skip comments and empty lines
                            }
                            
                            //Map parsing logic
                            
                            char* token = std::strtok(line, "\t");
                            if (token == nullptr) {
                                continue; // blank line with only whitespace
                            }
                            
                            //handle conn lines
                            if (stringEquals(token, "CONN")){
                                
                                char* floorToken=std::strtok(nullptr, "\t");
                                
                                if(floorToken==nullptr){
                                    continue; //invalid line
                                }
                                
                                if (floorToken[0] != 'F' || floorToken[1] < '1' || floorToken[1] > '5' || floorToken[2] != '\0') {
                                    continue;
                                }
                                
                                int floorIndex=floorToken[1]-'1'; //convert '1'-'5' to 0-4
                                char* gap1=std::strtok(nullptr, "\t");
                                char* gap2=std::strtok(nullptr, "\t");
                                char* gap3=std::strtok(nullptr, "\t");
                                
                                if(gap1==nullptr || gap2==nullptr || gap3==nullptr){
                                    continue; //invalid line
                                }

                                horizontalConn[floorIndex][0]=(gap1[0]=='_') ? CONN_NONE : gap1[0];
                                horizontalConn[floorIndex][1]=(gap2[0]=='_') ? CONN_NONE : gap2[0];
                                horizontalConn[floorIndex][2]=(gap3[0]=='_') ? CONN_NONE : gap3[0];

                                //handle entity lines
                            } else if (stringEquals(token, "ENTITY")) {
                                char* floorToken = std::strtok(nullptr, " \t");
                                char* roomToken = std::strtok(nullptr, " \t");
                                char* symbolToken = std::strtok(nullptr, " \t");

                                if (floorToken == nullptr || roomToken == nullptr || symbolToken == nullptr) {
                                    continue;
                                }

                                if (floorToken[0] != 'F' || floorToken[1] < '1' || floorToken[1] > '5' || floorToken[2] != '\0') {
                                    continue;
                                }

                                if (roomToken[0] != 'R' || roomToken[1] < '1' || roomToken[1] > '4' || roomToken[2] != '\0') {
                                    continue;
                                }

                                int floorIndex = floorToken[1] - '1';
                                int roomIndex = roomToken[1] - '1';

                                if (entityCounts[floorIndex][roomIndex] < MAX_ENTITIES_PER_ROOM) {
                                    roomEntities[floorIndex][roomIndex][entityCounts[floorIndex][roomIndex]] = symbolToken[0];
                                    entityCounts[floorIndex][roomIndex]++;
                                }
                            }
                        }
                    return true;
                 }