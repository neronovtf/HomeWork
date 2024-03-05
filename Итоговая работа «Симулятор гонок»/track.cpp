#include "track.h"

Track::Track() {
	this->type = 3;
	this->distance = 0;
};

bool Track::findRacingTracks(int numberTypeRacingTrack) {
	bool flag = false;
	for (int i = 0; i < this->countRacingTracks; i++) {
		if (std::stoi(namesRacingTracks[i][0]) == numberTypeRacingTrack) {
			flag = true;
			break;
		}
	}
	return flag;
}

void Track::setType(int type) {
	if (this->findRacingTracks(type)) {
		this->type = type;
	}
	else {
		throw Error("������ �� ������������ ����� ���� ...");
	}
};

void Track::setDistance(int distance) {
	distance > 0 ? this->distance = distance : throw Error("������������� ����� ��������� ...");
};

std::string Track::getDesriptionRacingTrackByNumberType(int numberTypeRacingTrack) {
	std::string name;
	for (int i = 0; i < this->countRacingTracks; i++) {
		if (std::stoi(namesRacingTracks[i][0]) == numberTypeRacingTrack) {
			name = namesRacingTracks[i][1];
			break;
		}
	}
	return name;
}

/*
	1 - ������������ �������� ���������
	0 - ������������ �������� ��� ����������
	-1 - �� ������������ ����
*/
int Track::addNewTransport(Transport* transport) {
	bool flag = true;
	// ��������, �� ����������� ���������� � ���� �����
	if (this->type != 3) { // ���(3) ��� ��� ����, ����� �������� �� �����
		flag = (this->type == (*transport).getType());
	}

	if (!flag) return -1; // �� ����������� ����, ������ �� �������

	// ��������, �� ������� ������ ���������� � �����
	for (int i = 0; i < this->numberTransport; i++) {
		if ((*transports[i]).getName() == (*transport).getName()) {
			flag = false;
			break;
		}
	}

	if (!flag) return 0; // ������������ ��, ������ �� �������

	transports[this->numberTransport] = transport;
	this->numberTransport++;

	return 1; // �� ������
};

int Track::numberAddedTransport() {
	return this->numberTransport;
};

Transport* Track::getAllTransport() {
	Transport* transports = new Transport[this->numberTransport];
	for (int i = 0; i < this->numberTransport; i++) {
		transports[i] = *this->transports[i];
	}
	return transports;
};

Transport Track::getTransportByIndex(int index) {
	if (index <= this->numberTransport) {
		return *this->transports[index];
	}
	else {
		throw Error("����� �� ������� ������� ...");
	}
};

void Track::start() {
	for (int i = 0; i < this->numberTransport; i++) {
		(*this->transports[i]).calculate(this->distance);
	}
	this->sortFinishedTransports();
};

void Track::sortFinishedTransports() {
	int countActiveTC = this->numberTransport;

	int minIndex, minValue;
	Transport* transport;
	for (int i = 0; i < countActiveTC; i++) {
		minIndex = i;
		minValue = (*this->transports[minIndex]).getTime();
		for (int j = i; j < countActiveTC; j++) {
			if (minValue > (*this->transports[j]).getTime()) {
				minIndex = j;
				minValue = (*this->transports[minIndex]).getTime();
			}
		}
		transport = this->transports[i];
		this->transports[i] = this->transports[minIndex];
		this->transports[minIndex] = transport;
	}
};