#pragma once

#include "project_api.h"
#include "transport.h"
#include "landTransport.h"

class Track {
private:
	int type; // 1 = назмемный, 2 = воздушный, 3 = и наземный и воздушный
	int distance;
	Transport* transports[7]; // всего, можно добавить 7 видов транспортов
	int countRacingTracks = 3;
	int numberTransport = 0;
	std::string namesRacingTracks[3][2] = {
		{"1", "Гонка для наземного транспорта"},
		{"2", "Гонка для воздушного транспорта"},
		{"3", "Гонка для наземного и воздушного транспорта"}
	};
	bool findRacingTracks(int numberTypeRacingTrack);
	void sortFinishedTransports();
public:
	PROJECT_API Track();
	PROJECT_API void setType(int type);
	PROJECT_API void setDistance(int distance);
	PROJECT_API std::string getDesriptionRacingTrackByNumberType(int numberTypeRacingTrack);
	PROJECT_API int addNewTransport(Transport* transport);
	PROJECT_API int numberAddedTransport();
	PROJECT_API Transport* getAllTransport();
	PROJECT_API Transport getTransportByIndex(int index);
	PROJECT_API void start();
};